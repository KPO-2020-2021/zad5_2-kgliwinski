#include "../tests/doctest/doctest.h"
#include "cuboid.hpp"

TEST_CASE("C 1.01: konstruktor bezparametryczny prostopadloscianu i przeciazenie operatora <<")
{
    //double tab[2][2] = {{3,1}};
    Cuboid a;
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
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek F: \n"
         << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek G: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek H: \n"
         << "[ 0.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    CHECK(out.str() == out2.str());
}

TEST_CASE("C 1.02: konstruktor parametryczny prostopadloscianu (przeciazenie z double) i przeciazenie operatora <<")
{
    int i, j, k;
    double tab[2][4][3];
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            for (k = 0; k < 3; ++k)
            {
                tab[i][j][k] = 1.0;
            }
        }
    }
    Cuboid a(tab);
    std::ostringstream out;
    out << a; //
    std::ostringstream out2;
    out2 << "Wierzcholek A: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek B: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek C: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek D: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek E: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek F: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek G: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek H: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    CHECK(out.str() == out2.str());
}

TEST_CASE("C 1.03: konstruktor parametryczny prostopadloscianu (przeciazenie z Vector3D) i przeciazenie operatora <<")
{
    int i, j;
    double tab_vec[3] = {1, 2, 3};
    Vector3D tab[2][4];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid a(tab);
    std::ostringstream out;
    out << a; //
    std::ostringstream out2;
    out2 << "Wierzcholek A: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek B: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek C: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek D: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek E: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek F: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek G: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek H: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    CHECK(out.str() == out2.str());
}

TEST_CASE("C 1.03: konstruktor parametryczny prostopadloscianu (przeciazenie z Vector3D) i przeciazenie operatora << small")
{
    int i, j;
    double tab_vec[3] = {0.0000000001, 0.0000000002, 0.0000000003};
    Vector3D tab[2][4];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid a(tab);
    std::ostringstream out;
    out << a; //
    std::ostringstream out2;
    out2 << "Wierzcholek A: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek B: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek C: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek D: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek E: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek F: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek G: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek H: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";

    CHECK(out.str() == out2.str());
}

TEST_CASE("C 1.04: konstruktor parametryczny prostopadloscianu (przeciazenie z double) i przeciazenie operatora <<")
{
    int i, j, k;
    double tab[2][4][3];
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            for (k = 0; k < 3; ++k)
            {
                tab[i][j][k] = -1.0;
            }
        }
    }
    Cuboid a(tab);
    std::ostringstream out;
    out << a; //
    std::ostringstream out2;
    out2 << "Wierzcholek A: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek B: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek C: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek D: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek E: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek F: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek G: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek H: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    CHECK(out.str() == out2.str());
}


TEST_CASE("C 1.05: operator == dla klasy Cuboid")
{
    Cuboid a, b;

    CHECK(a == b);
}

TEST_CASE("C 1.06: operator == dla klasy Cuboid false")
{
    Cuboid a;
    int i, j;
    double tab_vec[3] = {1, 2, 3};
    Vector3D tab[2][4];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid b(tab);
    CHECK(!(a == b));
}

TEST_CASE("C 1.07: konstruktor parametryczny prostopadloscianu (przeciazenie z Vector3D) wraz z konstruktorem Block(), sprawdzenie dzialania")
{
    int i, j;
    double tab_vec[3] = {1, 2, 3};
    Vector3D tab[2][4];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    std::string s = "sname";
    std::string f = "fname";
    Vector3D vec;
    Cuboid a(tab,s,f,vec);

    CHECK (a.get_sample_name() == "sname");
    CHECK (a.get_final_name() == "fname");
    CHECK (a.get_scale() == vec);
}

TEST_CASE("C 1.08: konstruktor parametryczny prostopadloscianu (przeciazenie z Vector3D) wraz z konstruktorem Block(), sprawdzenie dzialania")
{
    int i, j;
    double tab_vec[3] = {1, 2, 3};
    Vector3D tab[2][4];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    std::string s = "sname";
    std::string f = "fname";
    Vector3D vec(tab_vec);
    Cuboid a(tab,s,f,vec);

    CHECK (a.get_sample_name() == "sname");
    CHECK (a.get_final_name() == "fname");
    CHECK (a.get_scale() == vec);
}



TEST_CASE("C 2.01: Cuboid::get_cub()")
{
    int i, j;
    double tab_vec[3] = {1, 2, 3};
    Vector3D tab[2][4];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid a(tab);
    Vector3D tab2[2][4];
    a.get_cub(tab2);
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            CHECK(tab[i][j] == tab2[i][j]);
        }
    }
}

TEST_CASE("C 2.02: Cuboid::get_cub() small")
{
    int i, j;
    double tab_vec[3] = {0.0000000001, 0.0000000002, 0.0000000003};
    Vector3D tab[2][4];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid a(tab);
    Vector3D tab2[2][4];
    a.get_cub(tab2);
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            CHECK(tab[i][j] == tab2[i][j]);
        }
    }
}

TEST_CASE("C 2.03: Cuboid::get_cub() negative")
{
    int i, j;
    double tab_vec[3] = {-1, -2, -3};
    Vector3D tab[2][4];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid a(tab);
    Vector3D tab2[2][4];
    a.get_cub(tab2);
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            CHECK(tab[i][j] == tab2[i][j]);
        }
    }
}

TEST_CASE("C 2.05: Cuboid::get_cub() double")
{
    int i, j, z;
    double tab_vec[2][4][3];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (z=0;z<3;z++)
            tab_vec[i][j][z] = z+1;
        }
    }
    Cuboid a(tab_vec);
    double tab2[2][4][3];
    a.get_cub(tab2);
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            for(z=0;z<3;++z)
            CHECK(tab_vec[i][j][z] == tab2[i][j][z]);
        }
    }
}

TEST_CASE("C 2.06: Cuboid::get_height() double 1")
{
    Cuboid a;
    CHECK (a.get_height() == 1);
}

TEST_CASE("C 2.07: Cuboid::get_height() double 2")
{
    Cuboid a;
    double tab[3] = {100,100,100};
    Vector3D scale(tab);
    a = a.scale_cub(scale);
    CHECK (a.get_height() == 100);
}

TEST_CASE("C 2.08: Cuboid::get_height() double 3")
{
    Cuboid a;
    double tab[3] = {100,100,100};
    Vector3D scale(tab);
    a = a.scale_cub(scale);
    a = a.translation(scale);
    CHECK (a.get_height() == 100);
}

TEST_CASE("C 2.09: Cuboid::get_height() double 4")
{
    Cuboid a;
    double tab[3] = {100,100,100};
    Matrix3D mat;
    mat = mat.rotation_matrix(23235,'x');
    mat = mat.rotation_matrix(-124,'y') * mat;
    mat = mat.rotation_matrix(-124,'z') * mat;
    a = a.rotation(mat);
    Vector3D scale(tab);
    a = a.scale_cub(scale);
    a = a.translation(scale);
    CHECK (a.get_height() == 100);
}

TEST_CASE("C 3.01: Cuboid::translation(Vector3D)")
{
    Cuboid a;
    double tab[3] = {1, 2, 3};
    Vector3D tran(tab);
    Cuboid c = a.translation(tran);
    double tab2[2][4][3] = {{{1, 2, 3}, {2, 2, 3}, {2, 3, 3}, {1, 3, 3}}, {{1, 2, 4}, {2, 2, 4}, {2, 3, 4}, {1, 3, 4}}};
    Cuboid b(tab2);
    CHECK(c == b);
}

TEST_CASE("C 3.02: Cuboid::translation(Vector3D) negative")
{
    Cuboid a;
    double tab[3] = {-1, -2, -3};
    Vector3D tran(tab);
    Cuboid c = a.translation(tran);
    double tab2[2][4][3] = {{{-1, -2, -3}, {0, -2, -3}, {0, -1, -3}, {-1, -1, -3}}, {{-1, -2, -2}, {0, -2, -2}, {0, -1, -2}, {-1, -1, -2}}};
    Cuboid b(tab2);
    CHECK(c == b);
}

TEST_CASE("C 4.01: Cuboid::rotation(Matrix3D) 1")
{
    Cuboid a;
    double tab[3] = {-1, -2, -3};
    Vector3D tran(tab);
    Cuboid c = a.translation(tran);
    double tab2[2][4][3] = {{{-1, -2, -3}, {0, -2, -3}, {0, -1, -3}, {-1, -1, -3}}, {{-1, -2, -2}, {0, -2, -2}, {0, -1, -2}, {-1, -1, -2}}};
    Cuboid b(tab2);
    CHECK(c == b);
}

TEST_CASE("C 4.02: Cuboid::centre_point() 1")
{
    Cuboid a;
    Vector3D ref = a.centre_point();
    double tab[3] = {0.5,0.5,0.5};
    Vector3D res(tab);
    CHECK (res == ref);
}

TEST_CASE("C 4.03: Cuboid::centre_point() 2")
{
    Cuboid a;
    double tab[3] = {-1, -2, -3};
    Vector3D tran(tab);
    a = a.translation(tran);
    Vector3D ref = a.centre_point();
    double tab2[3] = {-0.5,-1.5,-2.5};
    Vector3D res(tab2);
    CHECK (res == ref);
}

TEST_CASE("C 4.04: Cuboid::centre_point() 3")
{
    int i;
    Vector3D tops[2][4];
    double iter[4][3] = {{-1, 1, -1}, {1, 1, -1}, {1, -1, -1}, {-1, -1, -1}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 1;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    Vector3D ref = a.centre_point();
    double tab2[3] = {0,0,0};
    Vector3D res(tab2);
    CHECK (res == ref);
}

TEST_CASE("C 4.05: Cuboid::rotation_around_cen(Matrix3D, Vector3D) 1")
{
    int i;
    Vector3D tops[2][4];
    double iter[4][3] = {{-1, 1, -1}, {1, 1, -1}, {1, -1, -1}, {-1, -1, -1}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 1;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);

    Matrix3D rot;
    rot = rot.rotation_matrix(360,'x');
    Cuboid b = a.rotation_around_cen(rot);
    CHECK(a == b);
}

TEST_CASE("C 4.06: Cuboid::rotation_around_cen(Matrix3D, Vector3D) 2")
{
    int i;
    Vector3D tops[2][4];
    double iter[4][3] = {{-1, 1, -1}, {1, 1, -1}, {1, -1, -1}, {-1, -1, -1}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 1;
        tops[1][i] = Vector3D(iter[i]);
    }
    Vector3D tops2[2][4];
    double iter2[4][3] = {{-1, 1, 1}, {1, 1, 1}, {1, 1, -1}, {-1, 1, -1}};
    for (i = 0; i < 4; ++i)
    {
        tops2[0][i] = Vector3D(iter2[i]);
        iter2[i][1] = -1;
        tops2[1][i] = Vector3D(iter2[i]);
        std::cout<<tops2[1][i]<<std::endl;
    }
    Cuboid a(tops);
    Cuboid res(tops2);
    Matrix3D rot;
    rot = rot.rotation_matrix(90,'x');
    Cuboid b = a.rotation_around_cen(rot);
    CHECK(res == b);
    CHECK(a.centre_point() == b.centre_point());
    CHECK(b.centre_point() == res.centre_point());
}

TEST_CASE("C 4.07: Cuboid::rotation_around_cen(Matrix3D, Vector3D) 3")
{
    Cuboid a;
    Vector3D cen = a.centre_point();
    Matrix3D mat;
    mat = mat.rotation_matrix(360,'x');
    Cuboid b = a.rotation_around_cen(mat);
    CHECK (a == b);
    CHECK (cen == b.centre_point());
    b = b.rotation_around_cen(mat);
    CHECK (a == b);
    CHECK (cen == b.centre_point());
}

TEST_CASE("C 4.08: Cuboid::rotation_around_cen(Matrix3D, Vector3D) 4")
{
    Cuboid a;
    Vector3D cen = a.centre_point();
    Matrix3D mat;
    mat = mat.rotation_matrix(60,'x');
    mat = mat.rotation_matrix(60,'y') * mat;
    Cuboid b = a.rotation_around_cen(mat);
    CHECK (cen == b.centre_point());
    b = b.rotation_around_cen(mat);

}

TEST_CASE("C 5.01: Cuboid:get_vec_opp i check_vec_opp")
{
    int i;
    Cuboid a;
    Vector3D opp[3][2];
    a.get_vec_opp(opp);
    double tab[3][3] = {{1, 0, 0}, {0, 0, 1}, {0, 1, 0}};
    Vector3D vec[3];
    for (i = 0; i < 3; ++i)
    {
        vec[i] = Vector3D(tab[i]);
    }
    for (i = 0; i < 3; ++i)
    {
        CHECK(opp[i][0] == opp[i][1]);
        CHECK(opp[i][1] == vec[i]);
    }
    CHECK(a.check_vec_opp());
    CHECK(a.check_cub());
}

TEST_CASE("C 5.02: Cuboid:get_vec_opp i check_vec_opp 2")
{
    int i;
    Vector3D tops[2][4];
    double iter[4][3] = {{0, 0, 0}, {2, 0, 0}, {2, 2, 0}, {0, 2, 0}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    Vector3D opp[3][2];
    a.get_vec_opp(opp);
    double tab[3][3] = {{2, 0, 0}, {0, 0, 2}, {0, 2, 0}};
    Vector3D vec[3];
    for (i = 0; i < 3; ++i)
    {
        vec[i] = Vector3D(tab[i]);
    }
    for (i = 0; i < 3; ++i)
    {
        CHECK(opp[i][0] == opp[i][1]);
        CHECK(opp[i][1] == vec[i]);
    }
    CHECK(a.check_vec_opp());
    CHECK(a.check_cub());
}

TEST_CASE("C 5.03: Cuboid:get_vec_opp i check_vec_opp 3")
{
    int i;
    Vector3D tops[2][4];
    double iter[4][3] = {{-2, -2, 0}, {0, -2, 0}, {0, 0, 0}, {-2, 0, 0}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    Vector3D opp[3][2];
    a.get_vec_opp(opp);
    double tab[3][3] = {{2, 0, 0}, {0, 0, 2}, {0, 2, 0}};
    Vector3D vec[3];
    for (i = 0; i < 3; ++i)
    {
        vec[i] = Vector3D(tab[i]);
    }
    for (i = 0; i < 3; ++i)
    {
        CHECK(opp[i][0] == opp[i][1]);
        CHECK(opp[i][1] == vec[i]);
    }
    CHECK(a.check_vec_opp());
    CHECK(a.check_cub());
}


TEST_CASE("C 6.01: Cuboid::check_cub 1"){
    Cuboid a;
    CHECK(a.check_cub());
}

TEST_CASE("C 6.02: Cuboid::check_cub 2"){
    int i;
    Vector3D tops[2][4];
    double iter[4][3] = {{-2, -2, 0}, {0, -2, 0}, {0, 0, 0}, {-2, 0, 0}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    CHECK(a.check_cub());
}

TEST_CASE("C 6.03: Cuboid::check_cub 3"){
    int i;
    Vector3D tops[2][4];
    double iter[4][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    CHECK(!a.check_cub());
}

TEST_CASE("C 6.04: Cuboid::check_cub 4"){
    int i;
    Vector3D tops[2][4];
    double iter[4][3] = {{0, 0, 0}, {2, 0, 0}, {2, 2, 0}, {0, 2, 0}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    CHECK(a.check_cub());
}

TEST_CASE("C 6.05: Cuboid::check_cub 5"){
    int i;
    Vector3D tops[2][4];
    double iter[4][3] = {{214, 3234, 4140}, {4234, 0, 0}, {114, 41243, 0}, {0,0, 0}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    CHECK(!a.check_cub());
}

TEST_CASE("C 6.06: Cuboid::check_cub 6 small"){
    int i;
    Vector3D tops[2][4];
    double iter[4][3] = {{0, 0, 0}, {0.0000000002, 0, 0}, {0.0000000002, 0.0000000002, 0}, {0, 0.0000000002, 0}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    CHECK(a.check_cub());
}

TEST_CASE("C 6.07: Cuboid::check_cub 7 small neg"){
    int i;
    Vector3D tops[2][4];
    double iter[4][3] = {{0, 0, 0}, {-0.0000000002, 0, 0}, {-0.0000000002, -0.0000000002, 0}, {0, -0.0000000002, 0}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    CHECK(a.check_cub());
}

TEST_CASE("C 6.08: Cuboid::print_cub 8 "){
    int i;
    Vector3D tops[2][4];
    double iter[4][3] = {{0, 0, 0}, {2, 0, 0}, {2, 2, 0}, {0, 2, 0}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
  std::ostringstream out;
  std::ostringstream out2;
  a.print_cuboid(out);
out2<<"0.0000000000 0.0000000000 0.0000000000 \n";
out2<<"2.0000000000 0.0000000000 0.0000000000 \n\n";

out2<<"2.0000000000 2.0000000000 0.0000000000 \n";
out2<<"0.0000000000 2.0000000000 0.0000000000 \n\n";

out2<<"0.0000000000 0.0000000000 2.0000000000 \n";
out2<<"2.0000000000 0.0000000000 2.0000000000 \n\n";

out2<<"2.0000000000 2.0000000000 2.0000000000 \n";
out2<<"0.0000000000 2.0000000000 2.0000000000 \n\n";

out2<<"0.0000000000 0.0000000000 0.0000000000 \n";
out2<<"2.0000000000 0.0000000000 0.0000000000 \n";

  CHECK (out.str() == out2.str());
}

TEST_CASE("C 7.01: Cuboid::special_points() 1")
{
    Cuboid a;
    Vector3D tab[2], cen;
    cen = a.special_points(tab);
    double cen_tab[3] = {0.5, 0.5, 0.5};
    double one[3] = {0.5, 0.5, 0};
    double two[3] = {0.5, 0.5, 1};
    Vector3D cen_res(cen_tab);
    Vector3D cut_res1(one);
    Vector3D cut_res2(two);
    CHECK (cen == cen_res);
    CHECK (tab[0] == cut_res1);
    CHECK (tab[1] == cut_res2);
}

TEST_CASE("C 7.02: Cuboid::special_points() 2")
{
    Cuboid a;
    double tran[3] = {1,2,3};
    Vector3D trans(tran);
    a = a.translation(trans);
    Vector3D tab[2], cen;
    cen = a.special_points(tab);
    double cen_tab[3] = {1.5, 2.5, 3.5};
    double one[3] = {1.5, 2.5, 3};
    double two[3] = {1.5, 2.5, 4};
    Vector3D cen_res(cen_tab);
    Vector3D cut_res1(one);
    Vector3D cut_res2(two);
    CHECK (cen == cen_res);
    CHECK (tab[0] == cut_res1);
    CHECK (tab[1] == cut_res2);
}

TEST_CASE("C 7.03: Cuboid::special_points() 3")
{
    Cuboid a;
    double tran[3] = {-1,-2,-3};
    Vector3D trans(tran);
    a = a.translation(trans);
    Vector3D tab[2], cen;
    cen = a.special_points(tab);
    double cen_tab[3] = {-0.5, -1.5, -2.5};
    double one[3] = {-0.5, -1.5, -3};
    double two[3] = {-0.5, -1.5, -2};
    Vector3D cen_res(cen_tab);
    Vector3D cut_res1(one);
    Vector3D cut_res2(two);
    CHECK (cen == cen_res);
    CHECK (tab[0] == cut_res1);
    CHECK (tab[1] == cut_res2);
}

TEST_CASE("C 7.04: Cuboid::special_points() 4")
{
    Cuboid a;
    double tran[3] = {-0.0000000001,-0.0000000001,-0.0000000001};
    Vector3D trans(tran);
    a = a.translation(trans);
    Vector3D tab[2], cen;
    cen = a.special_points(tab);
    double cen_tab[3] = { 0.499999999, 0.499999999, 0.499999999};
    double one[3] = {0.499999999, 0.499999999, -0.0000000001};
    double two[3] = {0.499999999, 0.499999999, 0.999999999};
    Vector3D cen_res(cen_tab);
    Vector3D cut_res1(one);
    Vector3D cut_res2(two);
    CHECK (cen == cen_res);
    CHECK (tab[0] == cut_res1);
    CHECK (tab[1] == cut_res2);
}

TEST_CASE("C 8.01 : Cuboid::print_Cuboid_3D() oraz Cuboid::read_Cuboid_3D()")
{
     Cuboid a;
     a.set_sample_name("../tests/test_datasets/test_cub.dat");
     a.Cuboid_To_File(a.get_sample_name());

     Cuboid b;
     b = a.Cuboid_From_Sample();

     CHECK (a==b);
}

TEST_CASE("C 8.02 : Cuboid::print_Cuboid_3D() oraz Cuboid::read_Cuboid_3D() 2")
{
     Cuboid a;
     double tab[3] = {100,100,100};
     Vector3D sc(tab);
     a = a.scale_cub(sc);
     a.set_sample_name("../tests/test_datasets/test_cub2.dat");
     a.Cuboid_To_File(a.get_sample_name());

     Cuboid b;
     b = a.Cuboid_From_Sample();

     CHECK (a==b);
}

TEST_CASE("C 8.03 : Cuboid::print_Cuboid_3D() oraz Cuboid::read_Cuboid_3D() 3")
{
     Cuboid a;
     double tab[3] = {100,100,100};
     Vector3D sc(tab);
     a = a.scale_cub(sc);
     a = a.translation(sc);
     a.set_sample_name("../tests/test_datasets/test_cub3.dat");
     a.Cuboid_To_File(a.get_sample_name());

     Cuboid b;
     b = a.Cuboid_From_Sample();

     CHECK (a==b);
}

TEST_CASE("C 8.04 : Cuboid::print_Cuboid_3D() oraz Cuboid::read_Cuboid_3D() 4")
{
     Cuboid a;
     double tab[3] = {100,100,100};
     Vector3D sc(tab);
     a = a.scale_cub(sc);
     a = a.translation(sc);
     Matrix3D mat;
     mat = mat.rotation_matrix(5132, 'x');
     mat = mat.rotation_matrix(124, 'y') * mat;
     a = a.rotation_around_cen(mat);
     a.set_sample_name("../tests/test_datasets/test_cub4.dat");
     a.Cuboid_To_File(a.get_sample_name());

     Cuboid b;
     b = a.Cuboid_From_Sample();

     CHECK (a==b);
}