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

void Scene::add_basic_objects()
{
    std::shared_ptr<Pyramid> p = std::make_shared<Pyramid>(Pyramid());
    double tab1[3] = {20, 30, 15};
    Vector3D vec(tab1);
    *p = Pyramid("../datasets/main/sample/pyramid_default_sample.dat", "../datasets/main/final/pyramid_default_final.dat", vec);
    double tab[3] = {100, 100, p->get_height()*0.5};
    std::cout<<p->get_height();
    Vector3D tran(tab);
    *p = p->translation(tran);
    p->Cuboid_To_File(p->get_sample_name());
    p->Cuboid_To_File(p->get_final_name());
    objects.push_back(p);
}

int Scene::get_objects_size() const
{
    return objects.size();
}

bool Scene::check_scene() const
{
    unsigned int i;
    for (i = 0; i < SIZE; ++i)
    {
        if (!flies[i].check_dro())
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
    Lacze.UstawZakresZ(0, 120);
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
        Lacze.DodajNazwePliku(i->get()->get_sample_name().c_str(),PzG::SR_Ciagly);
        Lacze.DodajNazwePliku(i->get()->get_final_name().c_str());
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