#include "../tests/doctest/doctest.h"
#include "prism.hpp"

TEST_CASE("P 1.01: konstruktor bezparametryczny prostopadloscianu i przeciazenie operatora <<")
{
     //double tab[2][2] = {{3,1}};
     Prism a;
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

TEST_CASE("P 1.02: konstruktor parametryczny graniastoslupa (przeciazenie z double) i przeciazenie operatora <<")
{
     int i, j, k;
     double tab[2][6][3];
     for (i = 0; i < 2; ++i)
     {
          for (j = 0; j < 6; ++j)
          {
               for (k = 0; k < 3; ++k)
               {
                    tab[i][j][k] = 1.0;
               }
          }
     }
     Prism a(tab);
     std::ostringstream out;
     out << a; //
     std::ostringstream out2;
     out2 << "Wierzcholek A1: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek B1: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek C1: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek D1: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek E1: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek F1: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek A2: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek B2: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek C2: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek D2: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek E2: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek F2: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     CHECK(out.str() == out2.str());
}

TEST_CASE("P 1.03: konstruktor parametryczny graniastoslupa (przeciazenie z vector) i przeciazenie operatora <<")
{
     int i, j;
     double tab_vec[3] = {1, 2, 3};
     Vector3D tab[2][6];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               tab[i][j] = Vector3D(tab_vec);
          }
     }
     Prism a(tab);
     std::ostringstream out;
     out << a; //
     std::ostringstream out2;
     out2 << "Wierzcholek A1: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek B1: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek C1: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek D1: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek E1: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek F1: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek A2: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek B2: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek C2: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek D2: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek E2: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek F2: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     CHECK(out.str() == out2.str());
}

TEST_CASE("P 1.04: konstruktor parametryczny graniastoslupa (przeciazenie z vector) i przeciazenie operatora << neg")
{
     int i, j;
     double tab_vec[3] = {-1, -2, -3};
     Vector3D tab[2][6];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               tab[i][j] = Vector3D(tab_vec);
          }
     }
     Prism a(tab);
     std::ostringstream out;
     out << a; //
     std::ostringstream out2;
     out2 << "Wierzcholek A1: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek B1: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek C1: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek D1: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek E1: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek F1: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek A2: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek B2: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek C2: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek D2: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek E2: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek F2: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     CHECK(out.str() == out2.str());
}

TEST_CASE("P 1.05: konstruktor parametryczny graniastoslupa (przeciazenie z vector) i przeciazenie operatora << smol")
{
     int i, j;
     double tab_vec[3] = {-0.0000000001, -0.0000000002, -0.0000000003};
     Vector3D tab[2][6];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               tab[i][j] = Vector3D(tab_vec);
          }
     }
     Prism a(tab);
     std::ostringstream out;
     out << a; //
     std::ostringstream out2;
     out2 << "Wierzcholek A1: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek B1: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek C1: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek D1: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek E1: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek F1: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek A2: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek B2: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek C2: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek D2: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek E2: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek F2: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     CHECK(out.str() == out2.str());
}

TEST_CASE("P 1.08: konstruktor parametryczny graniastoslupa (przeciazenie z vector) z przypisaniem pol klasy Block")
{
     int i, j;
     double tab_vec[3] = {1, 2, 3};
     Vector3D tab[2][6];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               tab[i][j] = Vector3D(tab_vec);
          }
     }
     std::string s = "sname";
     std::string f = "fname";
     Vector3D vec;
     Prism a(tab, s, f, vec);

     CHECK(a.get_sample_name() == "sname");
     CHECK(a.get_final_name() == "fname");
     CHECK(a.get_scale() == vec);
}

TEST_CASE("P 1.09: konstruktor parametryczny graniastoslupa (przeciazenie z vector) z przypisaniem pol klasy Block")
{
     int i, j;
     double tab_vec[3] = {1, 2, 3};
     Vector3D tab[2][6];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               tab[i][j] = Vector3D(tab_vec);
          }
     }
     std::string s = "sname123";
     std::string f = "fname123";
     Vector3D vec(tab[0][0]);
     Prism a(tab, s, f, vec);

     CHECK(a.get_sample_name() == "sname123");
     CHECK(a.get_final_name() == "fname123");
     CHECK(a.get_scale() == vec);
}

TEST_CASE("P 1.10: Prism przeciazenie operatora ==")
{

     Prism a, b;

     CHECK(a == b);
}

TEST_CASE("P 1.11: Prism przeciazenie operatora == 2")
{
     int i;
     double iter[6][3] = {{2, 0, -0.5}, {0.5, sqrt(3) * 0.5, -0.5}, {-0.5, sqrt(3) * 0.5, -0.5}, {-1, 0, -0.5}, {-0.5, -sqrt(3) * 0.5, -0.5}, {0.5, -sqrt(3) * 0.5, -0.5}};
     Vector3D tops[2][6];
     for (i = 0; i < 6; ++i)
     {
          tops[0][i] = Vector3D(iter[i]);
          iter[i][2] = 0.5;
          tops[1][i] = Vector3D(iter[i]);
     }
     Prism a(tops), b(tops);

     CHECK(a == b);
}

TEST_CASE("P 1.12: Prism przeciazenie operatora == 3 smol")
{
     int i;
     double iter[6][3] = {{0.0000002, 0, -0.5}, {0.5, sqrt(3) * 0.5, -0.0000000005}, {-0.0000000005, sqrt(3) * 0.000000005, -0.00000005}, {-1, 0, -0.5}, {-0.5, -sqrt(3) * 0.000000005, -0.000000005}, {0.5, -sqrt(3) * 0.00000005, -0.0000000005}};
     Vector3D tops[2][6];
     for (i = 0; i < 6; ++i)
     {
          tops[0][i] = Vector3D(iter[i]);
          iter[i][2] = 0.5;
          tops[1][i] = Vector3D(iter[i]);
     }
     Prism a(tops), b(tops);

     CHECK(a == b);
}

TEST_CASE("P 2.01: get_pri przeciazenie dla Vector3D ")
{
     int i, j;
     double tab_vec[3] = {1, 2, 3};
     Vector3D tab[2][6];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               tab[i][j] = Vector3D(tab_vec);
          }
     }
     Prism a(tab);
     Vector3D res[2][6];

     a.get_pri(res);
     for (i = 0; i < 2; ++i)
     {
          for (j = 0; j < 6; j++)
          {
               CHECK(res[i][j] == tab[i][j]);
          }
     }
}

TEST_CASE("P 2.02: get_pri przeciazenie dla Vector3D neg")
{
     int i, j;
     double tab_vec[3] = {-1, -2, -3};
     Vector3D tab[2][6];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               tab[i][j] = Vector3D(tab_vec);
          }
     }
     Prism a(tab);
     Vector3D res[2][6];

     a.get_pri(res);
     for (i = 0; i < 2; ++i)
     {
          for (j = 0; j < 6; j++)
          {
               CHECK(res[i][j] == tab[i][j]);
          }
     }
}

TEST_CASE("P 2.03: get_pri przeciazenie dla Vector3D smol")
{
     int i, j;
     double tab_vec[3] = {-0.0000000001, -0.0000000002, -0.0000000003};
     Vector3D tab[2][6];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               tab[i][j] = Vector3D(tab_vec);
          }
     }
     Prism a(tab);
     Vector3D res[2][6];

     a.get_pri(res);
     for (i = 0; i < 2; ++i)
     {
          for (j = 0; j < 6; j++)
          {
               CHECK(res[i][j] == tab[i][j]);
          }
     }
}

TEST_CASE("P 2.04: get_pri przeciazenie dla double ")
{
     int i, j, k;
     double tab[2][6][3];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               for (k = 0; k < 3; ++k)
               {
                    tab[i][j][k] = k + 1;
               }
          }
     }
     Prism a(tab);
     double res[2][6][3];

     a.get_pri(res);
     for (i = 0; i < 2; ++i)
     {
          for (j = 0; j < 6; j++)
          {
               for (k = 0; k < 3; ++k)
               {
                    CHECK(res[i][j][k] == tab[i][j][k]);
               }
          }
     }
}

TEST_CASE("P 2.05: get_pri przeciazenie dla double small")
{
     int i, j, k;
     double tab[2][6][3];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               for (k = 0; k < 3; ++k)
               {
                    tab[i][j][k] = 0.0000000001 * (k + 1);
               }
          }
     }
     Prism a(tab);
     double res[2][6][3];

     a.get_pri(res);
     for (i = 0; i < 2; ++i)
     {
          for (j = 0; j < 6; j++)
          {
               for (k = 0; k < 3; ++k)
               {
                    CHECK(res[i][j][k] == tab[i][j][k]);
               }
          }
     }
}
TEST_CASE("P 2.06: get_pri przeciazenie dla double neg ")
{
     int i, j, k;
     double tab[2][6][3];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               for (k = 0; k < 3; ++k)
               {
                    tab[i][j][k] = -1 * (k + 1);
               }
          }
     }
     Prism a(tab);
     double res[2][6][3];

     a.get_pri(res);
     for (i = 0; i < 2; ++i)
     {
          for (j = 0; j < 6; j++)
          {
               for (k = 0; k < 3; ++k)
               {
                    CHECK(res[i][j][k] == tab[i][j][k]);
               }
          }
     }
}


TEST_CASE("P 2.07: get_height 1")
{
Prism a;
CHECK (a.get_height() == 1);
}

TEST_CASE("P 2.08: get_special_points 1")
{
Prism a;
Vector3D cuts[2], cen;
a.get_special_points(cuts,cen);
double tab1[3] = {0,0,-0.5};
double tab2[3] = {0,0,0.5};
double tab3[3] = {0,0,0};
Vector3D res1(tab1), res2(tab2), cen1(tab3);
CHECK(res1 == cuts[0]);
CHECK(res2 == cuts[1]);
CHECK(cen == cen1);
}

TEST_CASE("P 2.09: get_special_points 2")
{
Prism a;
double sca[3] = {1,1,1};
a.set_scale(sca);
a = a.scale_pri();
Vector3D cuts[2], cen;
a.get_special_points(cuts,cen);
double tab1[3] = {0,0,-0.5};
double tab2[3] = {0,0,0.5};
double tab3[3] = {0,0,0};
Vector3D res1(tab1), res2(tab2), cen1(tab3);
CHECK(res1 == cuts[0]);
CHECK(res2 == cuts[1]);
CHECK(cen == cen1);
}

TEST_CASE("P 2.10: get_special_points 3")
{
Prism a;
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


TEST_CASE("P 3.01: Prism::translation() 1")
{
     int i, j;
     double tab[3] = {1, 1, 1};
     Vector3D tran(tab);
     Prism a;
     a = a.translation(tran);
     double iter[6][3] = {{1, 0, -0.5}, {0.5, sqrt(3) * 0.5, -0.5}, {-0.5, sqrt(3) * 0.5, -0.5}, {-1, 0, -0.5}, {-0.5, -sqrt(3) * 0.5, -0.5}, {0.5, -sqrt(3) * 0.5, -0.5}};
     for (i = 0; i < 6; ++i)
     {
          for (j = 0; j < 3; ++j)
          {
               iter[i][j] += 1;
          }
     }
     Vector3D tops[2][6];
     for (i = 0; i < 6; ++i)
     {

          tops[0][i] = Vector3D(iter[i]);
          iter[i][2] = 1.5;
          tops[1][i] = Vector3D(iter[i]);
     }
     Prism res(tops);
     CHECK(a == res);
}

TEST_CASE("P 3.02: Prism::translation() 2 neg")
{
     int i, j;
     double tab[3] = {-1, -2, -3};
     Vector3D tran(tab);
     Prism a;
     a = a.translation(tran);
     double iter[6][3] = {{1, 0, -0.5}, {0.5, sqrt(3) * 0.5, -0.5}, {-0.5, sqrt(3) * 0.5, -0.5}, {-1, 0, -0.5}, {-0.5, -sqrt(3) * 0.5, -0.5}, {0.5, -sqrt(3) * 0.5, -0.5}};
     for (i = 0; i < 6; ++i)
     {
          for (j = 0; j < 3; ++j)
          {
               iter[i][j] -= (j + 1);
          }
     }
     Vector3D tops[2][6];
     for (i = 0; i < 6; ++i)
     {

          tops[0][i] = Vector3D(iter[i]);
          iter[i][2] = -2.5;
          tops[1][i] = Vector3D(iter[i]);
     }
     Prism res(tops);
     CHECK(a == res);
}

TEST_CASE("P 3.03: Prism::translation() 3 smol")
{
     int i, j;
     double tab[3] = {0.00000001, 0.00000001, 0.00000001};
     Vector3D tran(tab);
     Prism a;
     a = a.translation(tran);
     double iter[6][3] = {{1, 0, -0.5}, {0.5, sqrt(3) * 0.5, -0.5}, {-0.5, sqrt(3) * 0.5, -0.5}, {-1, 0, -0.5}, {-0.5, -sqrt(3) * 0.5, -0.5}, {0.5, -sqrt(3) * 0.5, -0.5}};
     for (i = 0; i < 6; ++i)
     {
          for (j = 0; j < 3; ++j)
          {
               iter[i][j] += 0.00000001;
          }
     }
     Vector3D tops[2][6];
     for (i = 0; i < 6; ++i)
     {

          tops[0][i] = Vector3D(iter[i]);
          iter[i][2] = 0.50000001;
          tops[1][i] = Vector3D(iter[i]);
     }
     Prism res(tops);
     CHECK(a == res);
}

TEST_CASE("P 3.04: Prism::translation_of_lower_cen() 1")
{
     int i, j;
     double tab[3] = {0.00000001, 0.00000001, 0.00000001};
     Vector3D tran(tab);
     Prism a;
     a = a.translation(tran);
     double iter[6][3] = {{1, 0, -0.5}, {0.5, sqrt(3) * 0.5, -0.5}, {-0.5, sqrt(3) * 0.5, -0.5}, {-1, 0, -0.5}, {-0.5, -sqrt(3) * 0.5, -0.5}, {0.5, -sqrt(3) * 0.5, -0.5}};
     for (i = 0; i < 6; ++i)
     {
          for (j = 0; j < 3; ++j)
          {
               iter[i][j] += 0.00000001;
          }
     }
     Vector3D tops[2][6];
     for (i = 0; i < 6; ++i)
     {

          tops[0][i] = Vector3D(iter[i]);
          iter[i][2] = 0.50000001;
          tops[1][i] = Vector3D(iter[i]);
     }
     Prism res(tops);
     CHECK(a == res);
}

TEST_CASE("P 3.05: Prism::translation_of_lower_cen() 2")
{
     int i, j;
     double tab[3] = {-234, -234, -234};
     Vector3D tran(tab);
     Prism a;
     a = a.translation(tran);
     double iter[6][3] = {{1, 0, -0.5}, {0.5, sqrt(3) * 0.5, -0.5}, {-0.5, sqrt(3) * 0.5, -0.5}, {-1, 0, -0.5}, {-0.5, -sqrt(3) * 0.5, -0.5}, {0.5, -sqrt(3) * 0.5, -0.5}};
     for (i = 0; i < 6; ++i)
     {
          for (j = 0; j < 3; ++j)
          {
               iter[i][j] += -234;
          }
     }
     Vector3D tops[2][6];
     for (i = 0; i < 6; ++i)
     {

          tops[0][i] = Vector3D(iter[i]);
          iter[i][2] = -233.5;
          tops[1][i] = Vector3D(iter[i]);
     }
     Prism res(tops);
     CHECK(a == res);
}

TEST_CASE("P 4.01: Prism::centre_point() 1")
{
     Prism a;
     Vector3D cen = a.centre_point();
     double tab[3] = {0, 0, 0};
     Vector3D res(tab);
     CHECK(cen == res);
}

TEST_CASE("P 4.02: Prism::centre_point() 2")
{
     Prism a;
     double tab[3] = {1, 1, 1};
     Vector3D tran(tab);
     a = a.translation(tran);
     Vector3D res = a.centre_point();
     CHECK(tran == res);
}

TEST_CASE("P 4.03: Prism::centre_point() 3")
{
     Prism a;
     double tab[3] = {1, 21, -111};
     Vector3D tran(tab);
     a = a.translation(tran);
     Vector3D res = a.centre_point();
     CHECK(tran == res);
}

TEST_CASE("P 4.04: Prism::centre_point() 4")
{
     Prism a;
     double tab[3] = {0.000001, 0.000021, -1234111};
     Vector3D tran(tab);
     a = a.translation(tran);
     Vector3D res = a.centre_point();
     CHECK(tran == res);
}

TEST_CASE("P 4.05: Prism::special_points() 1")
{
     Prism a;
     Vector3D pts[2];
     Vector3D cen = a.special_points(pts);
     double tab[3] = {0, 0, 0};
     Vector3D res(tab);
     double one[3] = {0, 0, -1};
     double two[3] = {0, 0, 1};
     Vector3D one_pt(one);
     Vector3D two_pt(two);

     CHECK(cen == res);
     CHECK(one_pt == pts[0]);
     CHECK(two_pt == pts[1]);
}

TEST_CASE("P 4.06: Prism::special_points() 2")
{
     Prism a;
     double tran[3] = {1, 2, 3};
     Vector3D trans(tran);
     a = a.translation(trans);
     Vector3D pts[2];
     Vector3D cen = a.special_points(pts);
     double tab[3] = {1, 2, 3};
     Vector3D res(tab);
     double one[3] = {1, 2, 2};
     double two[3] = {1, 2, 4};
     Vector3D one_pt(one);
     Vector3D two_pt(two);

     CHECK(cen == res);
     CHECK(one_pt == pts[0]);
     CHECK(two_pt == pts[1]);
}

TEST_CASE("P 4.07: Prism::special_points() 3")
{
     Prism a;
     double tran[3] = {-1, -2, -3};
     Vector3D trans(tran);
     a = a.translation(trans);
     Vector3D pts[2];
     Vector3D cen = a.special_points(pts);
     double tab[3] = {-1, -2, -3};
     Vector3D res(tab);
     double one[3] = {-1, -2, -4};
     double two[3] = {-1, -2, -2};
     Vector3D one_pt(one);
     Vector3D two_pt(two);

     CHECK(cen == res);
     CHECK(one_pt == pts[0]);
     CHECK(two_pt == pts[1]);
}

TEST_CASE("P 4.08: Prism::special_points() 4")
{
     Prism a;
     double tran[3] = {0.0000000001, 0.0000000002, 0.0000000003};
     Vector3D trans(tran);
     a = a.translation(trans);
     Vector3D pts[2];
     Vector3D cen = a.special_points(pts);
     double tab[3] = {0.0000000001, 0.0000000002, 0.0000000003};
     Vector3D res(tab);
     double one[3] = {0.0000000001, 0.0000000002, 0.0000000002};
     double two[3] = {0.0000000001, 0.0000000002, 0.0000000004};
     Vector3D one_pt(one);
     Vector3D two_pt(two);

     CHECK(cen == res);
     CHECK(one_pt == pts[0]);
     CHECK(two_pt == pts[1]);
}

TEST_CASE("P 5.01: Prism::rotation_around_cen() 1")
{
     Prism a, b;
     Matrix3D rot;
     for (int i = 0; i < 6; ++i)
     {
          rot = rot.rotation_matrix(60, 'x');
          b = a.rotation_around_cen(rot);
          CHECK(a == b);
     }
}

TEST_CASE("P 5.02: Prism::rotation_around_cen() 2")
{
     Prism a, b;
     Matrix3D rot;
     double tab[3] = {1, 2, 3};
     Vector3D tran(tab);
     a.translation(tran);
     for (int i = 0; i < 6; ++i)
     {
          rot = rot.rotation_matrix(60, 'x');
          b = a.rotation_around_cen(rot);
          CHECK(a == b);
     }
}

TEST_CASE("P 5.03: Prism::rotation_around_cen() 3")
{
     Prism a, b;
     Matrix3D rot;
     double tab[3] = {-1, -2, -3};
     Vector3D tran(tab);
     a.translation(tran);
     for (int i = 0; i < 6; ++i)
     {
          rot = rot.rotation_matrix(60, 'x');
          b = a.rotation_around_cen(rot);
          CHECK(a == b);
     }
}

TEST_CASE("P 5.04: Prism::rotation_around_cen() 4")
{
     Prism a, b;
     Matrix3D rot;
     double tab[3] = {-0.000001, -0.02, -0.000003};
     Vector3D tran(tab);
     a.translation(tran);
     for (int i = 0; i < 6; ++i)
     {
          rot = rot.rotation_matrix(60, 'x');
          b = a.rotation_around_cen(rot);
          CHECK(a == b);
     }
}

TEST_CASE("P 6.01: Prism::scale_pri() 1")
{
     Prism a;
     double tab[3] = {1, 1, 1};
     a.set_scale(tab);
     Prism b = a.scale_pri();

     CHECK(a == b);
}

TEST_CASE("P 6.02: Prism::scale_pri() 2")
{
     Prism a;
     double tab[3] = {100, 100, 100};
     int i;
     Vector3D top[2][6];
     double iter[6][3] = {{100, 0, -50}, {50, sqrt(3) * 50, -50}, {-50, sqrt(3) * 50, -50}, {-100, 0, -50}, {-50, -sqrt(3) * 50, -50}, {50, -sqrt(3) * 50, -50}};
     for (i = 0; i < 6; ++i)
     {
          top[0][i] = Vector3D(iter[i]);
          iter[i][2] = 50;
          top[1][i] = Vector3D(iter[i]);
     }
     Prism pri(top);
     a.set_scale(tab);
     Prism b = a.scale_pri();

     CHECK(pri == b);
}



TEST_CASE("P 6.03: Prism::scale_pri() 3")
{
     Prism a;
     double tab[3] = {0.1, 0.1, 0.1};
     int i;
     Vector3D top[2][6];
     double iter[6][3] = {{0.1, 0, -0.05}, {0.05, 0.1*sqrt(3) * 0.5, -0.05}, {-0.05, sqrt(3) * 0.05, -0.05}, {-0.1, 0, -0.05}, {-0.05, -sqrt(3) * 0.05, -0.05}, {0.05, -sqrt(3) * 0.05, -0.05}};
     for (i = 0; i < 6; ++i)
     {
          top[0][i] = Vector3D(iter[i]);
          iter[i][2] = 0.05;
          top[1][i] = Vector3D(iter[i]);
     }
     Prism pri(top);
     a.set_scale(tab);
     Prism b = a.scale_pri();

     CHECK(pri == b);
}


TEST_CASE("P 6.04: Prism::scale_pri(Vector3D) 1")
{
     Prism a;
     double tab[3] = {1, 1, 1};
     Vector3D s(tab);
     Prism b = a.scale_pri(s);

     CHECK(a == b);
}

TEST_CASE("P 6.05: Prism::scale_pri(Vector3D) 2")
{
     Prism a;
     double tab[3] = {100, 100, 100};
     int i;
     Vector3D top[2][6];
     double iter[6][3] = {{100, 0, -50}, {50, sqrt(3) * 50, -50}, {-50, sqrt(3) * 50, -50}, {-100, 0, -50}, {-50, -sqrt(3) * 50, -50}, {50, -sqrt(3) * 50, -50}};
     for (i = 0; i < 6; ++i)
     {
          top[0][i] = Vector3D(iter[i]);
          iter[i][2] = 50;
          top[1][i] = Vector3D(iter[i]);
     }
     Prism pri(top);
     Vector3D s(tab);
     Prism b = a.scale_pri(s);

     CHECK(pri == b);
}



TEST_CASE("P 6.06: Prism::scale_pri(Vector3D) 3")
{
     Prism a;
     double tab[3] = {0.1, 0.1, 0.1};
     int i;
     Vector3D top[2][6];
     double iter[6][3] = {{0.1, 0, -0.05}, {0.05, 0.1*sqrt(3) * 0.5, -0.05}, {-0.05, sqrt(3) * 0.05, -0.05}, {-0.1, 0, -0.05}, {-0.05, -sqrt(3) * 0.05, -0.05}, {0.05, -sqrt(3) * 0.05, -0.05}};
     for (i = 0; i < 6; ++i)
     {
          top[0][i] = Vector3D(iter[i]);
          iter[i][2] = 0.05;
          top[1][i] = Vector3D(iter[i]);
     }
     Prism pri(top);
     Vector3D s(tab);
     Prism b = a.scale_pri(s);;

     CHECK(pri == b);
}

TEST_CASE("P 7.01 [ASERCJE]: Prism get_vec_ver() i check_vec_ver() 1")
{
     Prism a;
     int i;
     Vector3D tab[6];
     a.get_vec_ver(tab);
     double tab_res[3] = {0,0,1};
     Vector3D res[6];
     for (i=0;i<6;++i)
     {
          res[i] = Vector3D(tab_res);
     }

     for (i=0;i<6;++i)
     {
          CHECK (res[i] == tab[i]);
     }
     CHECK (a.check_vec_ver());
     CHECK (a.check_pri());
}

TEST_CASE("P 7.02 [ASERCJE]: Prism get_vec_ver() i check_vec_ver() 2")
{
     Prism a;
     int i;
     Vector3D tab[6];
     double trans[3] = {124,124124,12343};
     a = a.translation(Vector3D(trans));
     a.get_vec_ver(tab);
     double tab_res[3] = {0,0,1};
     Vector3D res[6];
     for (i=0;i<6;++i)
     {
          res[i] = Vector3D(tab_res);
     }

     for (i=0;i<6;++i)
     {
          CHECK (res[i] == tab[i]);
     }
     CHECK (a.check_vec_ver());
     CHECK (a.check_pri());
}

TEST_CASE("P 7.03 [ASERCJE]: Prism get_vec_ver() i check_vec_ver() 3")
{
     Prism a;
     int i;
     Vector3D tab[6];
     double trans[3] = {124,124124,12343};
     a = a.translation(Vector3D(trans));
     Matrix3D rot;
     rot = rot.rotation_matrix(60, 'x');
     a = a.rotation_around_cen(rot);
     a.get_vec_ver(tab);
     double tab_res[3] = {0,0,1};
     Vector3D res[6];
     for (i=0;i<6;++i)
     {
          res[i] = Vector3D(tab_res);
     }

     for (i=0;i<6;++i)
     {
          CHECK (res[i] == tab[i]);
     }
     CHECK (a.check_vec_ver());
     CHECK (a.check_pri());
}

TEST_CASE("P 7.04 [ASERCJE]: Prism get_vec_ver() i check_vec_ver() 4")
{
     Prism a;
     double scale_tab[3] = {100,100,100};
     a.set_scale(scale_tab);
     a = a.scale_pri();
     int i;
     Vector3D tab[6];
     double trans[3] = {124,124124,12343};
     a = a.translation(Vector3D(trans));
     Matrix3D rot;

     a.get_vec_ver(tab);
     double tab_res[3] = {0,0,100};
     Vector3D res[6];
     for (i=0;i<6;++i)
     {
          res[i] = Vector3D(tab_res);
     }

     for (i=0;i<6;++i)
     {
          CHECK (res[i] == tab[i]);
     }
     CHECK (a.check_vec_ver());
     CHECK (a.check_pri());
}

TEST_CASE("P 7.05 [ASERCJE]: Prism get_vec_ver() i check_vec_ver() 5")
{
     Prism a;
     double scale_tab[3] = {100,100,100};
     a.set_scale(scale_tab);
     a = a.scale_pri();
     int i;
     Vector3D tab[6];
     double trans[3] = {124,124124,12343};
     a = a.translation(Vector3D(trans));
     Matrix3D rot;

     a.get_vec_ver(tab);
     double tab_res[3] = {0,0,100};
     Vector3D res[6];
     for (i=0;i<6;++i)
     {
          res[i] = Vector3D(tab_res);
     }

     for (i=0;i<6;++i)
     {
          CHECK (res[i] == tab[i]);
     }
     CHECK (a.check_vec_ver());
     CHECK (a.check_pri());
}

TEST_CASE("P 7.06 [ASERCJE]: check_vec_ver() 1 - with rotation")
{
     Prism a;
     double scale_tab[3] = {100,100,100};
     a.set_scale(scale_tab);
     a = a.scale_pri();
     double trans[3] = {124,124124,12343};
     a = a.translation(Vector3D(trans));
     Matrix3D rot;
     rot = rot.rotation_matrix(60, 'x');
     a = a.rotation_around_cen(rot);
     CHECK (a.check_vec_ver());
     CHECK (a.check_pri());
}

TEST_CASE("P 7.07 [ASERCJE]: check_vec_ver() 2 - with rotation")
{
     Prism a;
     double scale_tab[3] = {1410,1410,1410};
     a.set_scale(scale_tab);
     a = a.scale_pri();
     double trans[3] = {-124,124124,-12343};
     a = a.translation(Vector3D(trans));
     Matrix3D rot;
     rot = rot.rotation_matrix(60, 'x');
     rot = rot.rotation_matrix(0, 'y');
     a = a.rotation_around_cen(rot);
     CHECK (a.check_vec_ver());
     CHECK (a.check_pri());
}

TEST_CASE("P 7.08 [ASERCJE]: check_vec_ver() 3 - with rotation")
{
     Prism a;
     double scale_tab[3] = {100,100,100};
     a.set_scale(scale_tab);
     a = a.scale_pri();
     double trans[3] = {124,124124,12343};
     a = a.translation(Vector3D(trans));
     Matrix3D rot;
     rot = rot.rotation_matrix(60, 'x');
     rot = rot * rot.rotation_matrix(1241, 'y');
     rot = rot * rot.rotation_matrix(-27163, 'z');
     a = a.rotation_around_cen(rot);
     CHECK (a.check_vec_ver());
     CHECK (a.check_pri());
}

TEST_CASE("P 7.09 [ASERCJE]: get_vec_pairs() i check_vec_pairs 1")
{
     int i,j;
     Prism a;
     Vector3D vec[2][3][2];
     a.get_vec_pairs(vec);
     Vector3D tmp[3];
     double tab[3][3] = {{-0.5,sqrt(3)*0.5,0},{-1,0,0},{-0.5,-sqrt(3)*0.5,0}};
     for (i=0;i<3;++i)
     {
          tmp[i] = Vector3D(tab[i]);
     }
     for(i=0;i<2;++i)
    {
        for(j=0;j<3;++j)
        {
            CHECK(vec[i][j][0] == tmp[j]);
            CHECK(vec[i][j][1] == tmp[j]*(-1));
        }
    }
     CHECK (a.check_vec_pairs());
     CHECK (a.check_pri());
}

TEST_CASE("P 7.10 [ASERCJE]: get_vec_pairs() i check_vec_pairs 2")
{
     int i,j;
     Prism a;
     double tr[3] = {131224,4124.124,-2414};
     Vector3D trans(tr);
     a = a.translation(trans);
     Vector3D vec[2][3][2];
     a.get_vec_pairs(vec);
     Vector3D tmp[3];
     double tab[3][3] = {{-0.5,sqrt(3)*0.5,0},{-1,0,0},{-0.5,-sqrt(3)*0.5,0}};
     for (i=0;i<3;++i)
     {
          tmp[i] = Vector3D(tab[i]);
     }
     for(i=0;i<2;++i)
    {
        for(j=0;j<3;++j)
        {
            CHECK(vec[i][j][0] == tmp[j]);
            CHECK(vec[i][j][1] == tmp[j]*(-1));
        }
    }
     CHECK (a.check_vec_pairs());
     CHECK (a.check_pri());
}

TEST_CASE("P 7.11 [ASERCJE]: get_vec_pairs() i check_vec_pairs 3")
{
     int i,j;
     Prism a;
     double tr[3] = {131224,4124.124,-2414};
     Vector3D trans(tr);
     a = a.translation(trans);
     Matrix3D rot;
     rot = rot.rotation_matrix(60, 'x');
     rot = rot.rotation_matrix(0, 'y');
     a = a.rotation_around_cen(rot);
     Vector3D vec[2][3][2];
     a.get_vec_pairs(vec);
     Vector3D tmp[3];
     double tab[3][3] = {{-0.5,sqrt(3)*0.5,0},{-1,0,0},{-0.5,-sqrt(3)*0.5,0}};
     for (i=0;i<3;++i)
     {
          tmp[i] = Vector3D(tab[i]);
     }
     for(i=0;i<2;++i)
    {
        for(j=0;j<3;++j)
        {
            CHECK(vec[i][j][0] == tmp[j]);
            CHECK(vec[i][j][1] == tmp[j]*(-1));
        }
    }
     CHECK (a.check_vec_pairs());
     CHECK (a.check_pri());
}

TEST_CASE("P 8.01 : Prism::print_prism_3D() oraz Prism::read_prism_3D()")
{
     Prism a;
     a.set_sample_name("../tests/test_datasets/test_pri.dat");
     a.Prism_To_File(a.get_sample_name());

     Prism b;
     b = a.Prism_From_Sample();

     CHECK (a==b);
}

TEST_CASE("P 8.02 : Prism::print_prism_3D() oraz Prism::read_prism_3D() 2")
{
     Prism a;
     double tab[3] = {100,100,100};
     Vector3D sc(tab);
     a = a.scale_pri(sc);
     a.set_sample_name("../tests/test_datasets/test_pri2.dat");
     a.Prism_To_File(a.get_sample_name());

     Prism b;
     b = a.Prism_From_Sample();

     CHECK (a==b);
}

TEST_CASE("P 8.03 : Prism::print_prism_3D() oraz Prism::read_prism_3D() 3")
{
     Prism a;
     double tab[3] = {100,100,100};
     Vector3D sc(tab);
     a = a.scale_pri(sc);
     a = a.translation(sc);
     a.set_sample_name("../tests/test_datasets/test_pri3.dat");
     a.Prism_To_File(a.get_sample_name());

     Prism b;
     b = a.Prism_From_Sample();

     CHECK (a==b);
}

TEST_CASE("P 8.04 : Prism::print_prism_3D() oraz Prism::read_prism_3D() 4")
{
     Prism a;
     double tab[3] = {100,100,100};
     Vector3D sc(tab);
     a = a.scale_pri(sc);
     a = a.translation(sc);
     Matrix3D mat;
     mat = mat.rotation_matrix(5132, 'x');
     mat = mat.rotation_matrix(124, 'y') * mat;
     a = a.rotation_around_cen(mat);
     a.set_sample_name("../tests/test_datasets/test_pri4.dat");
     a.Prism_To_File(a.get_sample_name());

     Prism b;
     b = a.Prism_From_Sample();

     CHECK (a==b);
}

TEST_CASE("P 8.05 : Prism::print_prism_3D() oraz Prism::read_prism_3D() 5")
{
     Prism a;
     double tab[3] = {100,100,100};
     Vector3D sc(tab);
     a = a.scale_pri(sc);
     a = a.translation(sc);
     Matrix3D mat;
     mat = mat.rotation_matrix(5132, 'x');
     mat = mat.rotation_matrix(124, 'y') * mat;
     for(int i=0;i<100;++i)
          a = a.rotation_around_cen(mat);
     a.set_sample_name("../tests/test_datasets/test_pri5.dat");
     a.Prism_To_File(a.get_sample_name());

     Prism b;
     b = a.Prism_From_Sample();

     CHECK (a==b);
}