#include "../tests/doctest/doctest.h"
#include "tent.hpp"

TEST_CASE("Te 1.01: konstruktor bezparametryczny Tent i przeciazenie operatora <<")
{
    //double tab[2][2] = {{3,1}};
    Tent a;
    std::ostringstream out;
    out << a; //
    std::ostringstream out2;
    out2 << "Wierzcholek A1: \n"
         << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek B1: \n"
         << "[ 0.5000000000 ]\n[ 0.8660254038 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek C1: \n"
         << "[ -0.5000000000 ]\n[ 0.8660254038 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek D1: \n"
         << "[ -1.0000000000 ]\n[ 0.0000000000 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek E1: \n"
         << "[ -0.5000000000 ]\n[ -0.8660254038 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek F1: \n"
         << "[ 0.5000000000 ]\n[ -0.8660254038 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek A2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek B2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek C2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek D2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek E2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek F2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";

    CHECK(out.str() == out2.str());
}

TEST_CASE("Te 1.02: konstruktor parametryczny Tent 1")
{
    double tab[3] = {1,1,1};
    Vector3D sca(tab);
    Tent a("abc", "cde", sca);
        std::ostringstream out;
    out << a; //
    std::ostringstream out2;
    out2 << "Wierzcholek A1: \n"
         << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek B1: \n"
         << "[ 0.5000000000 ]\n[ 0.8660254038 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek C1: \n"
         << "[ -0.5000000000 ]\n[ 0.8660254038 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek D1: \n"
         << "[ -1.0000000000 ]\n[ 0.0000000000 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek E1: \n"
         << "[ -0.5000000000 ]\n[ -0.8660254038 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek F1: \n"
         << "[ 0.5000000000 ]\n[ -0.8660254038 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek A2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek B2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek C2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek D2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek E2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek F2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";

    CHECK(out.str() == out2.str());
    CHECK(a.get_final_name() == "cde");
    CHECK(a.get_sample_name() == "abc");
}

TEST_CASE("Te 1.03: konstruktor parametryczny Tent 2")
{
    double tab[3] = {1,1,1};
    Vector3D sca(tab);
    Tent a("abc", "", sca);
        std::ostringstream out;
    out << a; //
    std::ostringstream out2;
    out2 << "Wierzcholek A1: \n"
         << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek B1: \n"
         << "[ 0.5000000000 ]\n[ 0.8660254038 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek C1: \n"
         << "[ -0.5000000000 ]\n[ 0.8660254038 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek D1: \n"
         << "[ -1.0000000000 ]\n[ 0.0000000000 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek E1: \n"
         << "[ -0.5000000000 ]\n[ -0.8660254038 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek F1: \n"
         << "[ 0.5000000000 ]\n[ -0.8660254038 ]\n[ -0.5000000000 ]\n\n";
    out2 << "Wierzcholek A2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek B2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek C2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek D2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek E2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek F2: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";

    CHECK(out.str() == out2.str());
    CHECK(a.get_final_name() == "");
    CHECK(a.get_sample_name() == "abc");
    CHECK(!a.check_block());
}

TEST_CASE("Te 1.04: get_special_points 1")
{
Tent a;
Vector3D cuts[2], cen;
a.get_special_points(cuts,cen);
double tab1[3] = {0,0,-0.5};
double tab2[3] = {0,0,1.0};
double tab3[3] = {0,0,0};
Vector3D res1(tab1), res2(tab2), cen1(tab3);
CHECK(res1 == cuts[0]);
CHECK(res2 == cuts[1]);
CHECK(cen == cen1);
}

TEST_CASE("Te 1.05: get_special_points 2")
{
Tent a;
double sca[3] = {1,1,1};
a.set_scale(sca);
a = a.scale_pri();
Vector3D cuts[2], cen;
a.get_special_points(cuts,cen);
double tab1[3] = {0,0,-0.5};
double tab2[3] = {0,0,1.0};
double tab3[3] = {0,0,0};
Vector3D res1(tab1), res2(tab2), cen1(tab3);
CHECK(res1 == cuts[0]);
CHECK(res2 == cuts[1]);
CHECK(cen == cen1);
}

TEST_CASE("Te 1.06: get_special_points 3")
{
Tent a;
double sca[3] = {3,3,3};
a.set_scale(sca);
a = a.scale_pri();
Vector3D cuts[2], cen;
a.get_special_points(cuts,cen);
double tab1[3] = {0,0,-1.5};
double tab2[3] = {0,0,1.5};
double tab3[3] = {0,0,0};
Vector3D res1(tab1), res2(tab2), cen1(tab3);
CHECK(res1 == cuts[0]);
CHECK(res2 == cuts[1]);
CHECK(cen == cen1);
}

TEST_CASE("Te 2.01: Tent::get_height() 1")
{
    Tent a;
    CHECK(a.get_height() == 1);
}

TEST_CASE("Te 2.02: Tent::get_height() 2")
{
    Tent a;
    double tab[3] = {2,2,2};
    Vector3D sc(tab);
    a.set_scale(sc);
    a = a.scale_pri();
    CHECK(a.get_height() == 2);
}

TEST_CASE("Te 2.03: Tent::get_height() 3")
{
    Tent a;
    double tab[3] = {2,2,17};
    Vector3D sc(tab);
    a.set_scale(sc);
    a = a.scale_pri();
    CHECK(a.get_height() == 17);
}

TEST_CASE("Te 2.04: Tent::get_height() 4")
{
    Tent a;
    double tab[3] = {2,2,17};
    Vector3D sc(tab);
    a.set_scale(sc);
    a = a.scale_pri();
    a = a.translation(sc);
    CHECK(a.get_height() == 17);
}

TEST_CASE("Te 3.01: Tent::centre_point() 1")
{
    Tent a;
    double tab[3] = {0,0,0};
    Vector3D res(tab);
    CHECK(a.centre_point() == res);
}

TEST_CASE("Te 3.02: Tent::centre_point() 2")
{
    Tent a;
    double tab2[3] = {2,2,2};
    Vector3D sc(tab2);
    a.set_scale(sc);
    a = a.scale_pri();
    double tab[3] = {0,0,0};
    Vector3D res(tab);
    CHECK(a.centre_point() == res);
}

TEST_CASE("Te 3.03: Tent::centre_point() 3")
{
    Tent a;
    double tab2[3] = {2,2,17};
    Vector3D sc(tab2);
    a.set_scale(sc);
    a = a.scale_pri();
    double tab[3] = {0,0,0};
    Vector3D res(tab);
    CHECK(a.centre_point() == res);
}

TEST_CASE("Te 4.01: Tent::special_points() 2")
{
    Tent a;
    double tab[3] = {0,0,0};
    Vector3D res(tab);
    Vector3D cut[2], cen;
    CHECK(a.special_points(cut) == res);
    double t1[3] = {0,0,-0.5};
    double t2[3] = {0,0,0.5};
    Vector3D cut1(t1), cut2(t2);
    a.get_special_points(cut, cen);
    CHECK(cut[0] == cut1);
    CHECK(cut[1] == cut2);
}

TEST_CASE("Te 4.02: Tent::special_points() 2")
{
    Tent a;
    double tab2[3] = {2,2,2};
    Vector3D sc(tab2);
    a.set_scale(sc);
    a = a.scale_pri();
    double tab[3] = {0,0,0};
    Vector3D res(tab);
    Vector3D cut[2], cen;
    CHECK(a.special_points(cut) == res);
    double t1[3] = {0,0,-1};
    double t2[3] = {0,0,1};
    Vector3D cut1(t1), cut2(t2);
    a.get_special_points(cut, cen);
    CHECK(cut[0] == cut1);
    CHECK(cut[1] == cut2);
}

TEST_CASE("Te 4.03: Tent::special_points() 3")
{
    Tent a;
    double tab2[3] = {2,2,18};
    Vector3D sc(tab2);
    a.set_scale(sc);
    a = a.scale_pri();
    double tab[3] = {0,0,0};
    Vector3D res(tab);
    Vector3D cut[2], cen;
    CHECK(a.special_points(cut) == res);
    double t1[3] = {0,0,-9};
    double t2[3] = {0,0,9};
    Vector3D cut1(t1), cut2(t2);
    a.get_special_points(cut, cen);
    CHECK(cut[0] == cut1);
    CHECK(cut[1] == cut2);
}