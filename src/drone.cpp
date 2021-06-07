#include "../include/drone.hpp"

Drone::Drone()
{
    int i;
    double tmp[3] = {17, 20, 2.5};
    drone_pos = Vector3D(tmp);
    double tmp2[3] = {17, 20, 5};
    body.set_scale(tmp2);
    body = body.scale_cub();
    tmp[0] = 6;
    tmp[1] = 6;
    tmp[2] = 6;
    for (i = 0; i < 4; ++i)
    {
        rotors[i].set_scale(tmp);
        rotors[i] = rotors[i].scale_pri();
    }
    set_rotors_in_place();
    Matrix3D mat;
    mat = mat.rotation_matrix(90, 'z');
    *this = rotation_around_cen(mat);
    double tab[3] = {1, 0, 0};
    drone_orient = Vector3D(tab);
    drone_angle = 0;
}

void Drone::set_rotors_in_place()
{
    int i;
    Vector3D tmp[2][4];
    body.get_cub(tmp);
    for (i = 0; i < 4; ++i)
    {
        rotors[i] = rotors[i].translation_of_lower_cen(tmp[1][i]);
    }
}

Drone Drone::translation(Vector3D const &tran) const
{
    Drone rotated = *this;
    int i;
    rotated.body = body.translation(tran);
    for (i = 0; i < 4; ++i)
    {
        rotated.rotors[i] = rotors[i].translation(tran);
    }
    return rotated;
}

Drone Drone::translation_to_pos() const
{
    Drone translated = *this;
    Vector3D tran = drone_pos - body.centre_point();
    translated = this->translation(tran);
    return translated;
}

bool Drone::operator==(const Drone &dro) const
{
    int i;
    if (!(body == dro.body))
        return 0;
    if (!(drone_pos == dro.drone_pos))
        return 0;
    for (i = 0; i < 4; ++i)
    {
        if (!(rotors[i] == dro.rotors[i]))
            return 0;
    }
    return 1;
}

void Drone::get_dro(Cuboid &b, Prism (&rot)[4], Vector3D &p) const
{
    int i;
    b = body;
    for (i = 0; i < 4; ++i)
    {
        rot[i] = rotors[i];
    }
    p = drone_pos;
}

Drone Drone::rotation_around_cen(const Matrix3D &mat) const
{
    int i;
    Drone rotated = *this;
    rotated.body = body.rotation_around_cen(mat);
    for (i = 0; i < 4; ++i)
    {
        rotated.rotors[i] = rotors[i].rotation_around_cen(mat);
    }
    rotated.drone_orient = mat * drone_orient;
    rotated.set_rotors_in_place();
    return rotated;
}

Drone Drone::scale_dro() const
{
    Drone scaled = *this;
    int i;
    scaled.body = body.scale_cub();
    for (i = 0; i < 4; ++i)
    {
        scaled.rotors[i] = rotors[i].scale_pri();
    }
    return scaled;
}

void Drone::setup_filenames(std::string const (&bod)[2], std::string const (&rots)[4][2])
{
    int i;
    body.set_sample_name(bod[0]);
    body.set_final_name(bod[1]);
    for (i = 0; i < 4; ++i)
    {
        rotors[i].set_sample_name(rots[i][0]);
        rotors[i].set_final_name(rots[i][1]);
    }
}

bool Drone::set_filenames_gnuplot(PzG::LaczeDoGNUPlota &Lacze) const
{
    int i;
    if (body.get_final_name() == "")
        return 0;
    body.Cuboid_To_File(body.get_final_name());
    Lacze.DodajNazwePliku(body.get_final_name().c_str(), PzG::SR_Ciagly);
    if (body.get_sample_name() == "")
        return 0;
    body.Cuboid_To_File(body.get_sample_name());
    for (i = 0; i < 4; ++i)
    {
        if (rotors[i].get_final_name() == "")
            return 0;
        rotors[i].Prism_To_File(rotors[i].get_final_name());
        Lacze.DodajNazwePliku(rotors[i].get_final_name().c_str(), PzG::SR_Ciagly);
        if (rotors[i].get_sample_name() == "")
            return 0;
        rotors[i].Prism_To_File(rotors[i].get_sample_name());
    }
    return 1;
}

void Drone::get_filenames(std::string (&bod)[2], std::string (&rots)[4][2]) const
{
    int i;
    bod[0] = body.get_sample_name();
    bod[1] = body.get_final_name();
    for (i = 0; i < 4; ++i)
    {
        rots[i][0] = rotors[i].get_sample_name();
        rots[i][1] = rotors[i].get_final_name();
    }
}

bool Drone::set_drone_pos(Vector3D const &pos)
{
    if (pos[2] < body.get_height() * 0.5)
        return 0;
    drone_pos = pos;
    return 1;
}

void Drone::set_scale_all(Vector3D const &bod, Vector3D const &rot)
{
    int i;
    body.set_scale(bod);
    for (i = 0; i < 4; ++i)
    {
        rotors[i].set_scale(rot);
    }
}

bool Drone::check_dro() const
{
    int i;
    if (!body.check_cub())
        return 0;
    for (i = 0; i < 4; ++i)
    {
        if (!rotors[i].check_pri())
            return 0;
    }
    if (!check_orien())
        return 0;
    return 1;
}

Vector3D Drone::get_orien() const
{
    Vector3D res;
    res = drone_orient;
    return res;
}

double Drone::get_body_height() const
{
    return body.get_height();
}

bool Drone::check_orien() const
{
    if (!(abs(drone_orient.get_len() - 1.0) <= 0.00001))
        return 0;
    return 1;
}

void Drone::Print_to_gnuplot_drone() const
{
    int i;
    PzG::LaczeDoGNUPlota Lacze;
    body.Cuboid_To_File(body.get_sample_name());
    Lacze.DodajNazwePliku(body.get_sample_name().c_str(), PzG::SR_Ciagly);
    for (i = 0; i < 4; ++i)
    {
        Lacze.DodajNazwePliku(rotors[i].get_sample_name().c_str(), PzG::SR_Ciagly);
        rotors[i].Prism_To_File(rotors[i].get_sample_name());
    }
    Lacze.UstawZakresX(0, 200);
    Lacze.UstawZakresY(0, 200);
    Lacze.UstawZakresZ(0, 120);
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.Rysuj();
}

void Drone::Print_to_files_drone() const
{
    int i;
    body.Cuboid_To_File(body.get_final_name());
    for (i = 0; i < 4; ++i)
    {
        rotors[i].Prism_To_File(rotors[i].get_final_name());
    }
}

void Drone::Rotors_rotation_animation()
{
    Matrix3D mat_pos, mat_neg;
    mat_pos = mat_pos.rotation_matrix(3, 'z');
    mat_neg = mat_neg.rotation_matrix(-3, 'z');
    rotors[0] = rotors[0].rotation_around_cen(mat_pos);
    rotors[1] = rotors[1].rotation_around_cen(mat_neg);
    rotors[2] = rotors[2].rotation_around_cen(mat_neg);
    rotors[3] = rotors[3].rotation_around_cen(mat_pos);
    Print_to_files_drone();
}

void Drone::Drone_rotation_animation(PzG::LaczeDoGNUPlota Lacze, double const &angle)
{
    double angle1 = angle;
    while(angle1<0)
        {
            angle1 +=360;
        }
    int i;
    double theta = 1;
    Matrix3D mat = mat.rotation_matrix(theta, 'z');
    for (i = 0; i < angle1; ++i)
    {
        *this = rotation_around_cen(mat);
        Print_to_files_drone();
        Rotors_rotation_animation();
        usleep(10000); // 0.1 ms
        Lacze.Rysuj();
    }
    Drone_change_to_sample(drone_angle);
    //std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    //std::cin.ignore(100000, '\n');
}

bool Drone::Drone_make_path(Vector3D const &tran, std::vector<Vector3D> &path)
{
    int i;
    if (tran[2] != 0)
        return 0;
    double tab[3] = {0, 0, 1};
    Vector3D rise(tab);
    for (i = 0; i < 80; ++i)
    {
        path.push_back(path.at(i) + rise);
    }
    Vector3D fly = tran / 360;
    for (; i < 440; ++i)
    {
        path.push_back(path.at(i) + fly);
    }
    double tab2[3] = {0, 0, -1};
    Vector3D fall(tab2);
    for (; i < 521; ++i)
    {
        path.push_back(path.at(i) + fall);
    }
    return 1;
}

bool Drone::Drone_path_clear(std::string const &name)
{
    std::ofstream filestrm;
    filestrm.open(name, std::ofstream::out | std::ofstream::trunc);
    filestrm.close();
    return !filestrm.fail();
}

bool Drone::Drone_path_to_file(std::vector<Vector3D> &path, std::string const &name, PzG::LaczeDoGNUPlota &Lacze)
{
    long unsigned int i;
    std::ofstream filestrm;
    filestrm.open(name);
    if (!filestrm.is_open())
    {
        std::cerr << ":(  Operacja otwarcia do zapisu \"" << name << "\"" << std::endl
                  << ":(  nie powiodla sie." << std::endl;
        return false;
    }

    for (i = 0; i < path.size(); ++i)
    {
        filestrm << std::setw(10) << std::fixed << std::setprecision(10) << path[i][0] << " " << path[i][1] << " " << path[i][2] << std::endl;
    }
    filestrm.close();
    Lacze.DodajNazwePliku(name.c_str(), PzG::SR_Ciagly);
    Lacze.Rysuj();
    return !filestrm.fail();
}

void Drone::Drone_translation_animation(PzG::LaczeDoGNUPlota &Lacze, Vector3D const &tran)
{
    std::vector<Vector3D> cur_path = {drone_pos};
    Drone_make_path(tran, cur_path);
    Drone_path_to_file(cur_path, "../datasets/path.dat", Lacze);
    long unsigned int i;
    for (i = 0; i < cur_path.size(); ++i)
    {
        this->drone_pos = cur_path.at(i);
        *this = translation_to_pos();
        Print_to_files_drone();
        Rotors_rotation_animation();
        usleep(10000); // 0.1 ms
        Lacze.Rysuj();
    }
    Drone_change_to_sample(drone_angle);
}

Drone Drone::Drone_From_Sample() const
{
    int i;
    Drone dro;
    dro.body.Cuboid_From_Sample();
    for (i = 0; i < 4; ++i)
    {
        dro.rotors[i].Prism_From_Sample();
    }
    dro.drone_angle = drone_angle;
    std::string bod[2], rots[4][2];
    get_filenames(bod, rots);
    dro.setup_filenames(bod, rots);
    return dro;
}

void Drone::Drone_change_to_sample(double const &angle)
{
    int i;
    Drone sam = Drone_From_Sample();
    Matrix3D mat;
    mat = mat.rotation_matrix(angle, 'z');
    sam = sam.rotation_around_cen(mat);
    sam.set_drone_pos(drone_pos);
    sam.drone_angle = drone_angle;
    sam = sam.translation_to_pos();
    body = sam.body;
    for (i = 0; i < 4; ++i)
    {
        rotors[i] = sam.rotors[i];
    }
}

bool Drone::Drone_basic_motion(double const &angle, double const &len, PzG::LaczeDoGNUPlota &Lacze)
{
    long unsigned int i;
    drone_angle += angle;
    double theta = drone_angle * (PI / 180);
    double x = len * cos(theta);
    double y = len * sin(theta);
    double tab[3] = {x, y, 0};
    Vector3D tran(tab);
    std::vector<Vector3D> cur_path = {drone_pos};
    if (!Drone_make_path(tran, cur_path))
        return 0;
    std::cout << "Naciśnij ENTER, aby narysowac sciezke" << std::endl;
    std::cin.ignore(100000, '\n');
    if (!Drone_path_to_file(cur_path, "../datasets/sciezka.dat", Lacze))
        return 0;
    std::cout << "Naciśnij ENTER, aby wykonac animacje przelotu" << std::endl;
    std::cin.ignore(100000, '\n');
    std::cout << "Wznoszenie" << std::endl;
    for (i = 0; i < 80; ++i)
    {
        this->drone_pos = cur_path.at(i);
        *this = translation_to_pos();
        Print_to_files_drone();
        Rotors_rotation_animation();
        usleep(10000); // 0.1 ms
        Lacze.Rysuj();
    }
    std::cout << "Zmiana orientacji" << std::endl;
    Drone_rotation_animation(Lacze,angle);
    std::cout << "Lot do przodu" << std::endl;
    for (; i < 440; ++i)
    {
        this->drone_pos = cur_path.at(i);
        *this = translation_to_pos();
        Print_to_files_drone();
        Rotors_rotation_animation();
        usleep(10000); // 0.1 ms
        Lacze.Rysuj();
    }
    Drone_change_to_sample(drone_angle);
    std::cout << "Opadanie" << std::endl;
    for (; i < 521; ++i)
    {
        this->drone_pos = cur_path.at(i);
        *this = translation_to_pos();
        Print_to_files_drone();
        Rotors_rotation_animation();
        usleep(10000); // 0.1 ms
        Lacze.Rysuj();
    }
    Drone_change_to_sample(drone_angle);
    std::cout << "Naciśnij ENTER, aby usunac sciezke" << std::endl;
    std::cin.ignore(100000, '\n');
    if (!Drone_path_clear("../datasets/sciezka.dat"))
        return 0;
    Lacze.Rysuj();
    drone_pos.print_count();
    cur_path.clear();
    return 1;
}

bool Drone::Drone_roundabout(double const &radius, PzG::LaczeDoGNUPlota &Lacze)
{
    long unsigned int i;
    std::vector<Vector3D> cur_path = {drone_pos};
    if (!Drone_make_path_roundabout(radius, cur_path))
        return 0;
    std::cout << "Naciśnij ENTER, aby narysowac sciezke" << std::endl;
    std::cin.ignore(10000000000, '\n');
    if (!Drone_path_to_file(cur_path, "../datasets/sciezka.dat", Lacze))
        return 0;
    std::cout << "Naciśnij ENTER, aby wykonac animacje przelotu" << std::endl;
    std::cin.ignore(100000, '\n');
    std::cout << "Wznoszenie" << std::endl;
    for (i = 0; i < 80; ++i)
    {
        this->drone_pos = cur_path.at(i);
        *this = translation_to_pos();
        Print_to_files_drone();
        Rotors_rotation_animation();
        usleep(10000); // 0.1 ms
        Lacze.Rysuj();
    }
    std::cout << "Odlecenie na promien okregu" << std::endl;
    for (; i < 160; ++i)
    {
        this->drone_pos = cur_path.at(i);
        *this = translation_to_pos();
        Print_to_files_drone();
        Rotors_rotation_animation();
        usleep(10000); // 0.1 ms
        Lacze.Rysuj();
    }
    Matrix3D mat;
    mat = mat.rotation_matrix(1,'z');
    std::cout << "Oblot" << std::endl;
    for (; i < 520; ++i)
    {
        this->drone_pos = cur_path.at(i);
        *this = translation_to_pos();
        *this = rotation_around_cen(mat);
        drone_angle+=1;
        Print_to_files_drone();
        Rotors_rotation_animation();
        usleep(10000); // 0.1 ms
        Lacze.Rysuj();
    }
    Drone_change_to_sample(drone_angle);
    std::cout << "Powrot" << std::endl;
    for (; i < 600; ++i)
    {
        this->drone_pos = cur_path.at(i);
        *this = translation_to_pos();
        Print_to_files_drone();
        Rotors_rotation_animation();
        usleep(10000); // 0.1 ms
        Lacze.Rysuj();
    }
    std::cout << "Opadanie" << std::endl;
    for (; i < 680; ++i)
    {
        this->drone_pos = cur_path.at(i);
        *this = translation_to_pos();
        Print_to_files_drone();
        Rotors_rotation_animation();
        usleep(10000); // 0.1 ms
        Lacze.Rysuj();
    }
    Drone_change_to_sample(drone_angle);
    std::cout << "Naciśnij ENTER, aby usunac sciezke" << std::endl;
    std::cin.ignore(100000, '\n');
    if (!Drone_path_clear("../datasets/sciezka.dat"))
        return 0;
    Lacze.Rysuj();
    drone_pos.print_count();
    
    cur_path.clear();
    return 1;
}

bool Drone::Drone_make_path_roundabout(double const &radius, std::vector<Vector3D> &path)
{
    int i;
    if (radius <= 0)
        return 0;
    double posi[3];
    drone_pos.get_vec(posi);
    posi[3] = 80;
    Vector3D tmp(posi);
    double tab[3] = {0, 0, 1};
    Vector3D rise(tab);
    for (i = 0; i < 80; ++i)
    {
        path.push_back(path.at(i) + rise);
    }
    double tab2[3] = {0,radius,0};
    Vector3D tran(tab2);
    Vector3D fly = tran / 80;
    for (; i < 160; ++i)
    {
        path.push_back(path.at(i) + fly);
    }
    Matrix3D mat;
    mat = mat.rotation_matrix(1,'z');
    for (; i < 520; ++i)
    {
        path.at(i) = path.at(i) - tmp;
        path.at(i) = mat*path.at(i);
        path.at(i) = path.at(i) + tmp;
        path.push_back(path.at(i));
    }
    Vector3D back = fly*(-1);
    for (; i < 600; ++i)
    {
        path.push_back(path.at(i) + back);
    }
    Vector3D fall = rise *(-1);
    for (; i < 680; ++i)
    {
        path.push_back(path.at(i) + fall);
    }
    return 1;
}

void Drone::print_drone_pos() const
{
    std::cout << drone_pos[0] << " " << drone_pos[1];
}