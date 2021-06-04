#include "../tests/doctest/doctest.h"
#include "pyramid.hpp"

TEST_CASE("Py 1.01: konstruktor bezparametryczny piramid i przeciazenie operatora <<")
{
    //double tab[2][2] = {{3,1}};
    Pyramid a;
    std::ostringstream out;
    out << a; //
    std::ostringstream out2;
    out2 << "Wierzcholek A: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek B: \n"
         << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek C: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek D: \n"
         << "[ 0.0000000000 ]\n[ 1.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek E: \n"
         << "[ 0.5000000000 ]\n[ 0.5000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek F: \n"
         << "[ 0.5000000000 ]\n[ 0.5000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek G: \n"
         << "[ 0.5000000000 ]\n[ 0.5000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek H: \n"
         << "[ 0.5000000000 ]\n[ 0.5000000000 ]\n[ 1.0000000000 ]\n\n";
    CHECK(out.str() == out2.str());
}

TEST_CASE("Py 1.02: operator == dla klasy Cuboid")
{
    Pyramid a, b;

    CHECK(a == b);
}

TEST_CASE("Py 1.03: operator == dla klasy Cuboid false")
{
    Pyramid a;
    Pyramid b;
    double tab[3] = {100,100,100};
    Vector3D vec(tab);
    b = b.translation(vec);

    CHECK(!(a == b));
}

TEST_CASE("Py 1.04: Prism::scale()")
{
    Pyramid a, b;
    double tab[3] = {1,1,1};
    Vector3D vec(tab);
    a = a.scale_cub(vec);

    CHECK(a == b);
}

TEST_CASE("Py 1.05: Prism::scale()")
{
    Pyramid a;
    double tab[3] = {2,2,2};
    Vector3D vec(tab);
    a = a.scale_cub(vec);
    int i;
    Vector3D tops[2][4];
    double iter[4][3] = {{0, 0, 0}, {2, 0, 0}, {2, 2, 0}, {0, 2, 0}};
    double ver[3] = {1,1,2};
    Vector3D v(ver);
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        tops[1][i] = v;
    }
    Cuboid b(tops);
    CHECK(a == b);
}