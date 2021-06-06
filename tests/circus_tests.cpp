#include "../tests/doctest/doctest.h"
#include "../include/circus.hpp"

TEST_CASE("Ci 1.01: konstruktor bezparametryczny Circus i przeciazenie operatora <<")
{
    //double tab[2][2] = {{3,1}};
    Circus a;
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
         << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek B2: \n"
         << "[ 0.5000000000 ]\n[ 0.8660254038 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek C2: \n"
         << "[ -0.5000000000 ]\n[ 0.8660254038 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek D2: \n"
         << "[ -1.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek E2: \n"
         << "[ -0.5000000000 ]\n[ -0.8660254038 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek F2: \n"
         << "[ 0.5000000000 ]\n[ -0.8660254038 ]\n[ 0.5000000000 ]\n\n";

    CHECK(out.str() == out2.str());
}

TEST_CASE("Ci 1.02: konstruktor parametryczny Circus 1")
{
    double tab[3] = {1,1,1};
    Vector3D sca(tab);
    Circus a("abc", "cde", sca);
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
         << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek B2: \n"
         << "[ 0.5000000000 ]\n[ 0.8660254038 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek C2: \n"
         << "[ -0.5000000000 ]\n[ 0.8660254038 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek D2: \n"
         << "[ -1.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek E2: \n"
         << "[ -0.5000000000 ]\n[ -0.8660254038 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek F2: \n"
         << "[ 0.5000000000 ]\n[ -0.8660254038 ]\n[ 0.5000000000 ]\n\n";

    CHECK(out.str() == out2.str());
    CHECK(a.get_final_name() == "cde");
    CHECK(a.get_sample_name() == "abc");
}

TEST_CASE("Ci 1.03: konstruktor parametryczny Circus 2")
{
    double tab[3] = {1,1,1};
    Vector3D sca(tab);
    Circus a("abc", "", sca);
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
         << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek B2: \n"
         << "[ 0.5000000000 ]\n[ 0.8660254038 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek C2: \n"
         << "[ -0.5000000000 ]\n[ 0.8660254038 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek D2: \n"
         << "[ -1.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek E2: \n"
         << "[ -0.5000000000 ]\n[ -0.8660254038 ]\n[ 0.5000000000 ]\n\n";
    out2 << "Wierzcholek F2: \n"
         << "[ 0.5000000000 ]\n[ -0.8660254038 ]\n[ 0.5000000000 ]\n\n";

    CHECK(out.str() == out2.str());
    CHECK(a.get_final_name() == "");
    CHECK(a.get_sample_name() == "abc");
    CHECK(!a.check_block());
}

TEST_CASE("Ci 1.04: get_special_points 1")
{
Circus a;
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

TEST_CASE("Ci 1.05: get_special_points 2")
{
Circus a;
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

TEST_CASE("Ci 1.06: get_special_points 3")
{
Circus a;
double sca[3] = {3,3,3};
a.set_scale(sca);
a = a.scale_pri();
Vector3D cuts[2], cen;
a.get_special_points(cuts,cen);
double tab1[3] = {0,0,-1.5};
double tab2[3] = {0,0,3.0};
double tab3[3] = {0,0,0};
Vector3D res1(tab1), res2(tab2), cen1(tab3);
CHECK(res1 == cuts[0]);
CHECK(res2 == cuts[1]);
CHECK(cen == cen1);
}
