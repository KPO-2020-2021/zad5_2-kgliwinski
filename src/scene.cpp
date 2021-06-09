#include "../include/scene.hpp"

Scene::Scene(Vector3D const (&pos)[SIZE], Vector3D const (&scal_bod)[SIZE], Vector3D const (&scal_rot)[SIZE],
             std::string const (&names_bod)[SIZE][2], std::string const (&names_rot)[SIZE][4][2])
{
    unsigned int i;
    for (i = 0; i < SIZE; ++i)
    {
        flies[i].set_drone_pos(pos[i]);
        flies[i].set_scale_all(scal_bod[i], scal_rot[i]);
        flies[i] = flies[i].scale_dro();
        flies[i] = flies[i].translation_to_pos();
        flies[i].setup_filenames(names_bod[i], names_rot[i]);
        flies[i].set_rotors_in_place();
    }
    active = 0;
    filename_num = 0;
}

bool Scene::init_objects()
{
    std::shared_ptr<Drone> a = std::make_shared<Drone>(flies[0]);
    objects.push_back(a);
    a = std::make_shared<Drone>(flies[1]);
    objects.push_back(a);
    return !objects.empty();
}

bool Scene::add_basic_objects()
{
    double tab1[3] = {30, 40, 35};
    Vector3D vec1(tab1); //skala
    double tab2[3] = {25, 25, 50};
    Vector3D vec2(tab2); //skala
    double tab3[3] = {30, 50, 10};
    Vector3D vec3(tab3); //skala
    double tab4[3] = {20, 10, 30};
    Vector3D vec4(tab4); //skala
    double tab5[3] = {15, 15, 50};
    Vector3D vec5(tab5); //skala
    double tab6[3] = {45, 45, 50};
    Vector3D vec6(tab6); //skala
    if (!add_object_type_cuboid("../datasets/main/sample/pyramid_default_sample.dat", "../datasets/main/final/pyramid_default_final.dat", vec1, 100, 100, 30, 1))
        return 0;
    if (!add_object_type_cuboid("../datasets/main/sample/triangular_default_sample.dat", "../datasets/main/final/triangular_default_final.dat", vec2, 250, 40, 60, 2))
        return 0;
    if (!add_object_type_cuboid("../datasets/main/sample/cuboid_default_sample.dat", "../datasets/main/final/cuboid_default_final.dat", vec3, 40, 220, 0, 3))
        return 0;
    if (!add_object_type_prism("../datasets/main/sample/circus_default_sample.dat", "../datasets/main/final/circus_default_final.dat", vec4, 230, 230, 20, 4))
        return 0;
    if (!add_object_type_prism("../datasets/main/sample/tent_default_sample.dat", "../datasets/main/final/tent_default_final.dat", vec5, 160, 80, 90, 5))
        return 0;
    if (!add_object_type_prism("../datasets/main/sample/volcano_default_sample.dat", "../datasets/main/final/volcano_default_final.dat", vec6, 240, 140, 45, 6))
        return 0;
    return 1;
}

bool Scene::add_object(const Vector3D &sca, const double &x, const double &y, const double &angle, const unsigned int &option, PzG::LaczeDoGNUPlota &Lacze)
{
    switch (option)
    {
    case 1:
    case 2:
    case 3:
    {
        std::string s, f;
        create_filenames(s, f, option);
        if (!add_object_type_cuboid(s, f, sca, x, y, angle, option))
            return 0;
        Lacze.DodajNazwePliku(f.c_str());
        break;
    }
    case 4:
    case 5:
    case 6:
    {
        std::string s, f;
        create_filenames(s, f, option);
        if (!add_object_type_prism(s, f, sca, x, y, angle, option))
            return 0;
        Lacze.DodajNazwePliku(f.c_str());
        break;
    }
    default:
    {
        return 0;
        break;
    }
    }
    return 1;
}

bool Scene::delete_object(const unsigned int &num, PzG::LaczeDoGNUPlota &Lacze)
{
    if (num == 0)
        return 0;
    if (objects.size() <= num + 1)
        return 0;
    std::list<std::shared_ptr<Block>>::iterator i = objects.begin();
    std::advance(i, num + 1);
    std::string name = i->get()->get_final_name();
    if (!Lacze.UsunNazwePliku(name))
        return 0;
    objects.erase(i);
    return 1;
}

bool Scene::switch_object_position(const unsigned int &num, const double &x, const double &y)
{
    if (num == 0)
        return 0;
    if (objects.size() <= num + 1)
        return 0;
    std::list<std::shared_ptr<Block>>::iterator i = objects.begin();
    std::advance(i, num + 1);
    i->get()->switch_pos(x,y);
    return 1;
}

bool Scene::add_object_type_cuboid(const std::string &s_name, const std::string &f_name, const Vector3D &sca,
                                   const double &x, const double &y, const double &angle, const unsigned int &option)
{
    std::shared_ptr<Cuboid> p;
    switch (option)
    {
    case 1:
    {
        p = std::make_shared<Pyramid>(Pyramid());
        *p = Pyramid(s_name, f_name, sca);
        break;
    }
    case 2:
    {
        p = std::make_shared<Triangular>(Triangular());
        *p = Triangular(s_name, f_name, sca);
        break;
    }
    case 3:
    {
        p = std::make_shared<Cuboid>(Cuboid());
        *p = Cuboid(s_name, f_name, sca);
        break;
    }
    default:
    {
        return 0;
        break;
    }
    }
    double tr[3] = {x, y, p->get_height() * 0.5};
    Vector3D tran(tr);
    *p = p->translation(tran);
    Matrix3D mat;
    mat = mat.rotation_matrix(angle, 'z');
    *p = p->rotation_around_cen(mat);
    p->Cuboid_To_File(p->get_sample_name());
    p->Cuboid_To_File(p->get_final_name());
    objects.push_back(p);
    return 1;
}

bool Scene::add_object_type_prism(const std::string &s_name, const std::string &f_name, const Vector3D &sca,
                                  const double &x, const double &y, const double &angle, const unsigned int &option)
{
    std::shared_ptr<Prism> p;
    switch (option)
    {
    case 4:
    {
        p = std::make_shared<Circus>(Circus());
        *p = Circus(s_name, f_name, sca);
        break;
    }
    case 5:
    {
        p = std::make_shared<Tent>(Tent());
        *p = Tent(s_name, f_name, sca);
        break;
    }
    case 6:
    {
        p = std::make_shared<Volcano>(Volcano());
        Vector3D sca1 = sca * (5.0 / 6.0);
        *p = Volcano(s_name, f_name, sca1);
        break;
    }
    default:
    {
        return 0;
        break;
    }
    }
    double tr[3] = {x, y, p->get_height() * 0.5};
    Vector3D tran(tr);
    *p = p->translation(tran);
    Matrix3D mat;
    mat = mat.rotation_matrix(angle, 'z');
    *p = p->rotation_around_cen(mat);
    p->Prism_To_File(p->get_sample_name());
    p->Prism_To_File(p->get_final_name());
    objects.push_back(p);
    return 1;
}

bool Scene::create_filenames(std::string &s_name, std::string &f_name, const unsigned int &option)
{
    if (s_name != "" || f_name != "")
        return 0;
    s_name.append("../datasets/main/sample/created_object_");
    f_name.append("../datasets/main/final/created_object_");
    switch (option)
    {
    case 1:
    {
        switch_create_filenames(s_name, f_name, "Pyramid");
        break;
    }
    case 2:
    {
        switch_create_filenames(s_name, f_name, "Triangular");
        break;
    }
    case 3:
    {
        switch_create_filenames(s_name, f_name, "Cuboid");
        break;
    }
    case 4:
    {
        switch_create_filenames(s_name, f_name, "Circus");
        break;
    }
    case 5:
    {
        switch_create_filenames(s_name, f_name, "Tent");
        break;
    }
    case 6:
    {
        switch_create_filenames(s_name, f_name, "Volcano");
        break;
    }
    default:
    {
        s_name = "";
        f_name = "";
        return 0;
        break;
    }
    }
    return 1;
}

void Scene::switch_create_filenames(std::string &s_name, std::string &f_name, const std::string &type)
{
    ++filename_num;
    std::string ext = file_extension;
    s_name.append(type);
    s_name.append(std::to_string(filename_num));
    s_name.append(ext);
    f_name.append(type);
    f_name.append(std::to_string(filename_num));
    f_name.append(ext);
}

int Scene::get_objects_size() const
{
    return objects.size();
}

bool Scene::check_scene()
{
    unsigned int j;
    for (j = 0; j < SIZE; ++j)
    {
        if (!flies[j].check_dro())
            return 0;
    }

    std::list<std::shared_ptr<Block>>::iterator i;
    for (i = objects.begin(); i != objects.end(); ++i)
    {
        if (!(i->get()->check_block()))
            return 0;
    }
    return 1;
}

bool Scene::operator==(const Scene &sce) const
{
    unsigned int i;
    for (i = 0; i < SIZE; ++i)
    {
        if (!(flies[i] == sce.flies[i]))
            return 0;
    }
    return 1;
}

bool Scene::choose_drone(unsigned int const &ch)
{
    if (ch > SIZE - 1)
        return 0;
    active = ch;
    return 1;
}

bool Scene::init_gnuplot(double const &x, double const &y, PzG::LaczeDoGNUPlota &Lacze)
{
    unsigned int i;
    for (i = 0; i < SIZE; ++i)
    {
        flies[i].set_filenames_gnuplot(Lacze);
    }
    Lacze.UstawZakresX(0, x);
    Lacze.UstawZakresY(0, y);
    Lacze.UstawZakresZ(0, 180);
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Plane a(x, y, "../datasets/main/sample/plane_sample.dat", "../datasets/main/final/plane_final.dat");
    a.make_plane();
    Lacze.DodajNazwePliku("../datasets/main/final/plane_final.dat");
    if (!init_objects())
        return 0;
    add_basic_objects();
    if (!iterate_over_objects(Lacze))
        return 0;
    Lacze.Rysuj();
    return 1;
}

bool Scene::iterate_over_objects(PzG::LaczeDoGNUPlota &Lacze)
{
    if (get_objects_size() == 0)
        return 0;
    std::list<std::shared_ptr<Block>>::iterator i;
    i = objects.begin();
    std::advance(i, 2);
    for (; i != objects.end(); ++i)
    {
        Lacze.DodajNazwePliku(i->get()->get_final_name().c_str(), PzG::SR_Ciagly);
    }
    return 1;
}

unsigned int Scene::get_active() const
{
    return active;
}

unsigned int Scene::get_filename_num() const
{
    return filename_num;
}

void Scene::print_active() const
{
    flies[active].print_drone_pos();
}
void Scene::print_positions() const
{
    std::cout << "1 - Polozenie (x,y): ";
    flies[0].print_drone_pos();
    std::cout << std::endl;
    std::cout << "2 - Polozenie (x,y): ";
    flies[1].print_drone_pos();
    std::cout << std::endl
              << std::endl;
}

bool Scene::fly(double const &angle, double const &len, PzG::LaczeDoGNUPlota &Lacze)
{
    if (!flies[active].Drone_basic_motion(angle, len, Lacze))
        return 0;
    return 1;
}

bool Scene::fly_roundabout(double const &radius, PzG::LaczeDoGNUPlota &Lacze)
{
    if (!flies[active].Drone_roundabout(radius, Lacze))
        return 0;
    return 1;
}

void Scene::show_elements()
{
    int k = 1;
    std::list<std::shared_ptr<Block>>::iterator i;
    i = objects.begin();
    std::advance(i, 2);
    for (; i != objects.end(); ++i)
    {
        std::cout << k << ". ";
        i->get()->print_pos();
        i->get()->print_name();
        ++k;
    }
}
