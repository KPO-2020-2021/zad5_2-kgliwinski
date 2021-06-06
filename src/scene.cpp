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
}

bool Scene::init_objects(double const &x, double const &y)
{
    std::shared_ptr<Plane> p = std::make_shared<Plane>(Plane(x, y, "../datasets/main/sample/plane_sample.dat", "../datasets/main/final/plane_final.dat"));
    p->make_plane();
    objects.push_back(p);
    return !objects.empty();
}

bool Scene::add_basic_objects()
{
    std::shared_ptr<Pyramid> p = std::make_shared<Pyramid>(Pyramid());
    double tab1[3] = {30, 40, 35};
    Vector3D vec1(tab1);
    double tab2[3] = {25, 25, 50};
    Vector3D vec2(tab2);
    double tab3[3] = {30, 50, 10};
    Vector3D vec3(tab3);
    double tab4[3] = {20, 10, 30};
    Vector3D vec4(tab4);
    if (!add_object_type_cuboid("../datasets/main/sample/pyramid_default_sample.dat", "../datasets/main/final/pyramid_default_final.dat", vec1, 100, 100, 30, 1))
        return 0;
    if (!add_object_type_cuboid("../datasets/main/sample/triangular_default_sample.dat", "../datasets/main/final/triangular_default_final.dat", vec2, 250, 40, 60, 2))
        return 0;
    if (!add_object_type_cuboid("../datasets/main/sample/cuboid_default_sample.dat", "../datasets/main/final/cuboid_default_final.dat", vec3, 40, 220, 0, 3))
        return 0;
    if (!add_object_type_prism("../datasets/main/sample/circus_default_sample.dat", "../datasets/main/final/circus_default_final.dat", vec4, 230, 230, 20, 4))
        return 0;
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
    /*
    case 5:
    {
        p = std::make_shared<Triangular>(Triangular());
        *p = Triangular(s_name, f_name, sca);
        break;
    }
    case 6:
    {
        p = std::make_shared<Prism>(Prism());
        *p = Prism(s_name, f_name, sca);
        break;
    }
    */
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
    Lacze.UstawZakresZ(0, 160);
    Lacze.ZmienTrybRys(PzG::TR_3D);
    if (!init_objects(x, y))
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
    for (i = objects.begin(); i != objects.end(); ++i)
    {
        Lacze.DodajNazwePliku(i->get()->get_sample_name().c_str(), PzG::SR_Ciagly);
        Lacze.DodajNazwePliku(i->get()->get_final_name().c_str(), PzG::SR_Ciagly);
    }
    return 1;
}

unsigned int Scene::get_active() const
{
    return active;
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