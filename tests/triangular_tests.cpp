#include "../tests/doctest/doctest.h"
#include "../include/triangular.hpp"

TEST_CASE("Py 1.01: konstruktor bezparametryczny piramid i przeciazenie operatora <<")
{
    //double tab[2][2] = {{3,1}};
    Triangular a;
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
         << "[ 0.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek F: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek G: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek H: \n"
         << "[ 0.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    CHECK(out.str() == out2.str());
}

TEST_CASE("Py 1.02: operator == dla klasy Cuboid")
{
    Triangular a, b;

    CHECK(a == b);
}

TEST_CASE("Py 1.03: operator == dla klasy Cuboid false")
{
    Triangular a;
    Triangular b;
    double tab[3] = {100, 100, 100};
    Vector3D vec(tab);
    b = b.translation(vec);

    CHECK(!(a == b));
}

TEST_CASE("Py 1.04: Triangular::scale()")
{
    Triangular a, b;
    double tab[3] = {1, 1, 1};
    double tab1[3] = {-0.5,-0.5,-0.5};
    Vector3D tran(tab1);
    b = b.translation(tran);
    Vector3D vec(tab);
    a = a.scale_cub(vec);

    CHECK(a == b);
}

TEST_CASE("Py 1.05: Triangular::scale() 2")
{
    Triangular a;
    double tab[3] = {2, 2, 2};
    Vector3D vec(tab);
    a = a.scale_cub(vec);
    int i;
    Vector3D tops[2][4];
    double iter[4][3] = {{-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1}};
    double iter2[4][3] = {{-1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {-1, 1, 1}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        tops[1][i] = Vector3D(iter2[i]);
    }
    Cuboid b(tops);
    CHECK(a == b);
}

TEST_CASE("Py 1.06: Triangular::get_basis_centre() 1")
{
    Triangular a;
    double tab[3] = {0.5,0.5,0};
    Vector3D res(tab);

    CHECK(a.get_basis_centre() == res);
    CHECK(a.get_height() == 1);
}

TEST_CASE("Py 1.07: Triangular::get_basis_centre() 2")
{
    Triangular a;
    double tab2[3] = {0,0,-1};
     double tab[3] = {2,2,2};
    Vector3D vec(tab);
    a = a.scale_cub(vec);
    Vector3D res(tab2);

    CHECK(a.get_basis_centre() == res);
    CHECK(a.get_height() == 2);
}

TEST_CASE("Py 2.01: Triangular::centre_point() 1")
{
    Triangular a;
    double tab[3] = {0.5,0.5,0.5};
    Vector3D res(tab);

    CHECK(a.centre_point() == res);
}

TEST_CASE("Py 2.02: Triangular::centre_point() 2")
{
    Triangular a;
    double scal[3] = {1,2,3};
    a.set_scale(scal);
    a = a.scale_cub();
    double tab[3] = {0,0,0};
    Vector3D res(tab);

    CHECK(a.centre_point() == res);
}

TEST_CASE("Py 2.03: Triangular::centre_point() 3")
{
    Triangular a;
    double sca[3] = {1,2,3};
    Vector3D scal(sca);
    a.set_scale(scal);
    a = a.scale_cub();
    a = a.translation(scal);
    double tab[3] = {1,2,3};
    Vector3D res(tab);

    CHECK(a.centre_point() == res);
}