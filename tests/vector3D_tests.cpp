#include "../tests/doctest/doctest.h"

#include "vector3D.hpp"
// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.

TEST_CASE("V 1.01: Vector3D konstruktor bezparametryczny oraz przeciazenie strumienia wyjsciowego<<")
{
    Vector3D a;

    std::ostringstream out;
    out << a; //

    CHECK("[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.0000000000 ]\n" == out.str());
}

TEST_CASE("V 1.02: Vector3D konstruktor parametryczny oraz przeciazenie strumienia #include <cmath>wyjsciowego << i wejsciowego >>")
{
    Vector3D a;
    std::istringstream in("1.0 5.0 6.0");
    in >> a;
    std::ostringstream out;
    out << a; //

    CHECK("[ 1.0000000000 ]\n[ 5.0000000000 ]\n[ 6.0000000000 ]\n" == out.str());
}

TEST_CASE("V 1.03: Vector3D konstruktor parametryczny dla malych wartosci oraz przeciazenie strumienia wyjsciowego << i wejsciowego >>")
{
    Vector3D a;
    std::istringstream in("0.0000000001 0.0000000005 0.0000000005");
    in >> a;
    std::ostringstream out;
    out << a; //

    CHECK("[ 0.0000000001 ]\n[ 0.0000000005 ]\n[ 0.0000000005 ]\n" == out.str());
}

TEST_CASE("V 1.04: Vector3D konstruktor parametryczny dla duzych wartosci oraz przeciazenie strumienia wyjsciowego << i wejsciowego >>")
{
    Vector3D a;
    std::istringstream in("12345678 12345678 12345678");
    in >> a;
    std::ostringstream out;
    out << a; //

    CHECK("[ 12345678.0000000000 ]\n[ 12345678.0000000000 ]\n[ 12345678.0000000000 ]\n" == out.str());
}

TEST_CASE("V 1.05: Vector3D konstruktor parametryczny , operator przypisania")
{
    Vector3D a;
    std::istringstream in("1.0 5.0 6.0");
    in >> a;
    std::ostringstream out;
    Vector3D b = a;
    out << b; //

    CHECK("[ 1.0000000000 ]\n[ 5.0000000000 ]\n[ 6.0000000000 ]\n" == out.str());
}

TEST_CASE("V 1.06: Vector3D konstruktor parametryczny , operator przypisania 2")
{
    Vector3D a;
    std::istringstream in("1.0 5.0 6.0");
    in >> a;
    std::ostringstream out;
    Vector3D b = a;
    double tab[3] = {0, 0, 0};
    Vector3D c(tab);
    b = c;
    out << a; //

    CHECK("[ 1.0000000000 ]\n[ 5.0000000000 ]\n[ 6.0000000000 ]\n" == out.str());
}

TEST_CASE("V 1.07: Vector3D konstruktor parametryczny , operator przypisania 3")
{
    Vector3D a;
    std::istringstream in("1.0 5.0 6.0");
    in >> a;
    std::ostringstream out;
    Vector3D b = a;
    double tab[3] = {0, 0, 0};
    Vector3D c(tab);
    b = c;
    out << b; //
    std::ostringstream out2;
    out2 << a;
    CHECK("[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.0000000000 ]\n" == out.str());
    CHECK("[ 1.0000000000 ]\n[ 5.0000000000 ]\n[ 6.0000000000 ]\n" == out2.str());
}

TEST_CASE("V 2.01: Vector3D dodawanie wektorow")
{
    double tab[3][3] = {{4, 2, 1}, {2, 7, 1}, {6, 9, 2}};
    Vector3D a(tab[0]);
    Vector3D b(tab[1]);
    Vector3D res(tab[2]);

    Vector3D sum = a + b;
    CHECK(res == sum);
}

TEST_CASE("V 2.02: Vector3D dodawanie wektorow dla malych wartosci")
{
    double tab[3][3] = {{0.0000000004, 0.0000000002, 1}, {0.0000000002, 0.0000000007, 1}, {0.0000000006, 0.0000000009, 2}};
    Vector3D a(tab[0]);
    Vector3D b(tab[1]);
    Vector3D res(tab[2]);

    Vector3D sum = a + b;
    CHECK(res == sum);
}

TEST_CASE("V 2.03: Vector3D dodawanie wektorow dla malych wartosci (dokladnosc ponizej E-10)")
{
    double tab[3][3] = {{0.00000000004, 0.00000000002, 1}, {0.00000000002, 0.00000000007, 1}, {0.00000000006, 0.00000000009, 2}};
    Vector3D a(tab[0]);
    Vector3D b(tab[1]);
    Vector3D res(tab[2]);

    Vector3D sum = a + b;
    CHECK(res == sum);
}

TEST_CASE("V 2.04: Vector3D dodawanie wektorow dla duzych wartosci, granicze wartosci")
{
    double tab[3][3] = {{99999, 99999, 1}, {1, 1, 1}, {100000, 100000, 2}};
    Vector3D a(tab[0]);
    Vector3D b(tab[1]);
    Vector3D res(tab[2]);

    Vector3D sum = a + b;
    CHECK(res == sum);
}

TEST_CASE("V 3.01: Vector3D odejmowanie wektorow")
{
    double tab[3][3] = {{4, 2, 1}, {2, 7, 0}, {2, -5, 1}};
    Vector3D a(tab[0]);
    Vector3D b(tab[1]);
    Vector3D res(tab[2]);

    Vector3D sum = a - b;
    CHECK(res == sum);
}

TEST_CASE("V 3.02: Vector3D odejmowanie wektorow dla malych wartosci")
{
    double tab[3][3] = {{0.0000000004, 0.0000000002, 1}, {0.0000000002, 0.0000000007, 0}, {0.0000000002, -0.0000000005, 1}};
    Vector3D a(tab[0]);
    Vector3D b(tab[1]);
    Vector3D res(tab[2]);

    Vector3D sum = a - b;
    CHECK(res == sum);
}

TEST_CASE("V 3.03: Vector3D odejmowanie wektorow dla malych wartosci (dokladnosc ponizej E-10)")
{
    double tab[3][3] = {{0.00000000004, 0.00000000002, 1}, {0.00000000002, 0.00000000007, 0}, {0.00000000004, -0.00000000005, 1}};
    Vector3D a(tab[0]);
    Vector3D b(tab[1]);
    Vector3D res(tab[2]);

    Vector3D sum = a + b;
    CHECK(res == sum);
}

TEST_CASE("V 3.04: Vector3D odejmowanie wektorow dla duzych wartosci, granicze wartosci")
{
    double tab[3][3] = {{99999, 99999, 1}, {1, 1, 0}, {100000, 100000, 1}};
    Vector3D a(tab[2]);
    Vector3D b(tab[0]);
    Vector3D res(tab[1]);

    Vector3D sum = a - b;
    CHECK(res == sum);
}

TEST_CASE("V 4.01: Vector3D mnozenie wektorow przez skalar")
{
    double tab[2][3] = {{4, 2, 1}, {136, 68, 34}};
    double tmp;
    Vector3D a(tab[0]);
    tmp = 34;
    Vector3D b = a * tmp;
    Vector3D res(tab[1]);

    CHECK(res == b);
}

TEST_CASE("V 4.02: Vector3D mnozenie wektorow przez maly skalar")
{
    double tab[2][3] = {{4, 2, 1}, {0.000000004, 0.0000000002, 0.0000000001}};
    double tmp;
    Vector3D a(tab[0]);
    tmp = 0.000000001;
    Vector3D b = a * tmp;
    Vector3D res(tab[1]);

    CHECK(res == b);
}

TEST_CASE("V 4.03: Vector3D mnozenie wektorow przez 0")
{
    double tab[2][3] = {{4, 2, 1}, {0, 0, 0}};
    double tmp;
    Vector3D a(tab[0]);
    tmp = 0;
    Vector3D b = a * tmp;
    Vector3D res(tab[1]);

    CHECK(res == b);
}

TEST_CASE("V 4.04: Vector3D mnozenie wektora zerowego przez skalar")
{
    double tab[2][3] = {{0, 0, 0}, {0, 0, 0}};
    double tmp;
    Vector3D a(tab[0]);
    tmp = 1231234;
    Vector3D b = a * tmp;
    Vector3D res(tab[1]);

    CHECK(res == b);
}

TEST_CASE("V 5.01: Vector3D dzielenie wektorow przez skalar")
{
    double tab[2][3] = {{4, 2, 2}, {2, 1, 1}};
    double tmp;
    Vector3D a(tab[0]);
    tmp = 2;
    Vector3D b = a / tmp;
    Vector3D res(tab[1]);

    CHECK(res == b);
}

TEST_CASE("V 5.02: Vector3D dzielenie wektorow przez maly skalar")
{
    double tab[2][3] = {{4, 2, 1}, {40000000000, 20000000000, 10000000000}};
    double tmp;
    Vector3D a(tab[0]);
    tmp = 0.000000001;
    Vector3D b = a / tmp;
    Vector3D res(tab[1]);

    CHECK(!(a == b));
}

TEST_CASE("V 5.03: Vector3D dzielenie wektorow przez 0")
{
    double tab[2][3] = {{4, 2, 1}, {4, 2, 1}};
    double tmp;
    Vector3D a(tab[0]);
    tmp = 0;
    Vector3D b = a / tmp;
    Vector3D res(tab[1]);

    CHECK(res == b); //nothing happened
}

TEST_CASE("V 5.04: Vector3D dzielenie wektora zerowego przez skalar")
{
    double tab[2][3] = {{0, 0, 0}, {0, 0, 0}};
    double tmp;
    Vector3D a(tab[0]);
    tmp = 1231234;
    Vector3D b = a * tmp;
    Vector3D res(tab[1]);

    CHECK(res == b);
}
/*
TEST_CASE("V 6.01: Vector3D::rotate"){
    double tab[2][2] = {{3,4},{-4,3}};
    double ang;
    Vector3D a(tab[0]);
    ang =90;
    Vector3D b = a.rotate(ang);
    Vector3D res(tab[1]);
    
        CHECK((res == b));
}

TEST_CASE("V 6.02: Vector3D::rotate by 0"){
    double tab[2][2] = {{3,4},{3,4}};
    double ang;
    Vector3D a(tab[0]);
    ang =0;
    Vector3D b = a.rotate(ang);
    Vector3D res(tab[1]);

        CHECK((res == b));
}


TEST_CASE("V 6.03: Vector3D::rotate by 360 deg"){
    double tab[2][2] = {{3,4},{3,4}};
    double ang;
    Vector3D a(tab[0]);
    ang =360;
    Vector3D b = a.rotate(ang);
    Vector3D res(tab[1]);
    
        CHECK((res == b));
}


TEST_CASE("V 6.04: Vector3D::rotate by 36000000 deg"){
    double tab[2][2] = {{3,4},{3,4}};
    double ang;
    Vector3D a(tab[0]);
    ang =36000000;
    Vector3D b = a.rotate(ang);
    Vector3D res(tab[1]);
    
        CHECK((res == b));
}

TEST_CASE("V 6.05: Vector3D::rotate by 180 deg"){
    double tab[2][2] = {{3,4},{-3,-4}};
    double ang;
    Vector3D a(tab[0]);
    ang =180;
    Vector3D b = a.rotate(ang);
    Vector3D res(tab[1]);
    
        CHECK((res == b));
}
*/

TEST_CASE("V 7.01: Vector3D::modulus2")
{
    double tab[2][3] = {{3, 4, 1}};
    double res;
    Vector3D a(tab[0]);
    res = 26;

    CHECK((res == a.modulus2()));
}

TEST_CASE("V 7.02: Vector3D::modulus2 small")
{
    double tab[2][3] = {{0.003, 0.004, 1}};
    double res;
    Vector3D a(tab[0]);
    res = 1.000025;

    CHECK((abs(res - a.modulus2()) <= 0.0001));
}

TEST_CASE("V 7.03: Vector3D::modulus2 zero")
{
    double tab[2][3] = {{0, 0, 0}};
    double res;
    Vector3D a(tab[0]);
    res = 0;

    CHECK((res == a.modulus2()));
}

TEST_CASE("V 7.04: Vector3D::modulus2 neg")
{
    double tab[2][3] = {{-3, -4, 1}};
    double res;
    Vector3D a(tab[0]);
    res = 26;

    CHECK((res == a.modulus2()));
}

TEST_CASE("V 8.01: Vector3D::get_len ")
{
    double tab[2][3] = {{1, 2, 2}};
    double res;
    Vector3D a(tab[0]);
    res = 3;

    CHECK((res == a.get_len()));
}

TEST_CASE("V 8.02: Vector3D::get_len small")
{
    double tab[2][3] = {{0.001, 0.002, 0.002}};
    double res;
    Vector3D a(tab[0]);
    res = 0.003;
    CHECK((abs(res - a.get_len())) <= 0.00001);
}

TEST_CASE("V 8.03: Vector3D::get_len zero")
{
    double tab[2][3] = {{0, 0, 0}};
    double res;
    Vector3D a(tab[0]);
    res = 0;

    CHECK((res == a.get_len()));
}

TEST_CASE("V 8.04: Vector3D::get_len neg")
{
    double tab[2][3] = {{-5, -12, 0}};
    double res;
    Vector3D a(tab[0]);
    res = 13;

    CHECK((res == a.get_len()));
}

/*
TEST_CASE("V 9.01: Vector3D::get_slope_angle "){
    double tab[2][2] = {{1,1}};
    double res;
    Vector3D a(tab[0]);
    res = 45.0;

    CHECK (abs(res - a.get_slope_angle())<= 0.000001);
}

TEST_CASE("V 9.02: Vector3D::get_slope_angle 0"){
    double tab[2][2] = {{0,0}};
    double res;
    Vector3D a(tab[0]);
    res = 0;

    CHECK (abs(res - a.get_slope_angle())<= 0.000001);
}

TEST_CASE("V 9.03: Vector3D::get_slope_angle 90 deg"){
    double tab[2][2] = {{0,1}};
    double res;
    Vector3D a(tab[0]);
    res = 90;

    CHECK (abs(res - a.get_slope_angle())<= 0.000001);
}
*/
TEST_CASE("V 10.01: operator []")
{
    double tab[2][3] = {{3, 1, 0}};
    double res;
    Vector3D a(tab[0]);
    res = 3;

    CHECK(abs(res - a[0]) <= 0.000001);
}

TEST_CASE("V 10.02: operator []")
{
    double tab[2][3] = {{3, 1, 0}};
    double res;
    Vector3D a(tab[0]);
    res = 1;

    CHECK(abs(res - a[1]) <= 0.000001);
}

TEST_CASE("V 10.02: operator []")
{
    double tab[2][3] = {{3, 1, 0}};
    double res;
    Vector3D a(tab[0]);
    res = 0;

    CHECK(abs(res - a[2]) <= 0.000001);
}

TEST_CASE("V 10.03: operator const []")
{
    double tab[2][2] = {{3, 1}};
    double res;
    Vector3D a(tab[0]);
    res = 1;

    double b = a[1];
    CHECK(abs(res - b) <= 0.000001);
}

TEST_CASE("V 11.01: scalar_prod()")
{
    double tab[3] = {3, 1, 7};
    double tab2[3] = {3, 1, 2};
    double res;
    Vector3D a(tab);
    Vector3D b(tab2);
    res = 24;

    CHECK(abs(res - a.scalar_prod(b)) <= 0.000001);
}

TEST_CASE("V 11.01: scalar_prod() 1")
{
    double tab[3] = {3, 1, 7};
    double tab2[3] = {3, 1, 2};
    double res;
    Vector3D a(tab);
    Vector3D b(tab2);
    res = 24;

    CHECK(abs(res - a.scalar_prod(b)) <= 0.000001);
}

TEST_CASE("V 11.02: scalar_prod() 2")
{
    double tab[3] = {3, 1, -7};
    double tab2[3] = {3, 1, 2};
    double res;
    Vector3D a(tab);
    Vector3D b(tab2);
    res = -4;

    CHECK(abs(res - a.scalar_prod(b)) <= 0.000001);
}

TEST_CASE("V 11.03: scalar_prod() 3")
{
    double tab[3] = {0, 0, 0};
    double tab2[3] = {0, 0, 0};
    double res;
    Vector3D a(tab);
    Vector3D b(tab2);
    res = 0;

    CHECK(abs(res - a.scalar_prod(b)) <= 0.000001);
}

TEST_CASE("V 11.04: scalar_prod() 4")
{
    double tab[3] = {-3, 1, -7};
    double tab2[3] = {3, 1, 2};
    double res;
    Vector3D a(tab);
    Vector3D b(tab2);
    res = -22;

    CHECK(abs(res - a.scalar_prod(b)) <= 0.000001);
}

TEST_CASE("V 11.05: scalar_prod() 5")
{
    double tab[3] = {-3, -1, -7};
    double tab2[3] = {-3, -1, -2};
    double res;
    Vector3D a(tab);
    Vector3D b(tab2);
    res = 24;

    CHECK(abs(res - a.scalar_prod(b)) <= 0.000001);
}

TEST_CASE("V 12.01: get_vec 1")
{
    double tab[3] = {-3, 1, -7};
    Vector3D a(tab);
    double tab2[3];
    a.get_vec(tab2);
    int i;
    for (i = 0; i < 3; ++i)
    {
        CHECK(tab[i] == tab2[i]);
    }
}

TEST_CASE("V 12.02: get_vec 2")
{
    double tab[3] = {-1231, 3214, 415413};
    Vector3D a(tab);
    double tab2[3];
    a.get_vec(tab2);
    int i;
    for (i = 0; i < 3; ++i)
    {
        CHECK(tab[i] == tab2[i]);
    }
}

TEST_CASE("V 12.03: get_vec 3")
{
    double tab[3] = {-0.00000003, 2142141, -0.0092419847};
    Vector3D a(tab);
    double tab2[3];
    a.get_vec(tab2);
    int i;
    for (i = 0; i < 3; ++i)
    {
        CHECK(tab[i] == tab2[i]);
    }
}

TEST_CASE("V 12.04: get_vec 4")
{
    double tab[3] = {1244, 423525, 0.000003};
    Vector3D a(tab);
    double tab2[3];
    a.get_vec(tab2);
    int i;
    for (i = 0; i < 3; ++i)
    {
        CHECK(tab[i] == tab2[i]);
    }
}

TEST_CASE("V 12.05: get_vec 5")
{
    double tab[3] = {0, 0, 0};
    Vector3D a(tab);
    double tab2[3];
    a.get_vec(tab2);
    int i;
    for (i = 0; i < 3; ++i)
    {
        CHECK(tab[i] == tab2[i]);
    }
}

TEST_CASE("V 13.01: scale_vec 1")
{
    double tab[3] = {0, 0, 0};
    Vector3D a(tab);
    double tab2[3] = {1, 2, 3};
    Vector3D b(tab2);
    double res_tab[3] = {0,0,0};
    Vector3D res(res_tab);
    a = a.scale_vec(b);
    CHECK (a == res);
}

TEST_CASE("V 13.02: scale_vec 2")
{
    double tab[3] = {1, 1, 1};
    Vector3D a(tab);
    double tab2[3] = {1, 2, 3};
    Vector3D b(tab2);
    double res_tab[3] = {1,2,3};
    Vector3D res(res_tab);
    a = a.scale_vec(b);
    CHECK (a == res);
}

TEST_CASE("V 13.03: scale_vec 3")
{
    double tab[3] = {2, 2, 2};
    Vector3D a(tab);
    double tab2[3] = {1, 2, 3};
    Vector3D b(tab2);
    double res_tab[3] = {2,4,6};
    Vector3D res(res_tab);
    a = a.scale_vec(b);
    CHECK (a == res);
}

TEST_CASE("V 13.04: scale_vec 4")
{
    double tab[3] = {-1, -1, -1};
    Vector3D a(tab);
    double tab2[3] = {1, 2, 3};
    Vector3D b(tab2);
    double res_tab[3] = {-1,-2,-3};
    Vector3D res(res_tab);
    a = a.scale_vec(b);
    CHECK (a == res);
}

TEST_CASE("V 13.05: scale_vec 5")
{
    double tab[3] = {-0.0000000001, -0.0000000001, -0.0000000001};
    Vector3D a(tab);
    double tab2[3] = {1, 2, 3};
    Vector3D b(tab2);
    double res_tab[3] = {-0.0000000001,-0.0000000002,-0.0000000003};
    Vector3D res(res_tab);
    a = a.scale_vec(b);
    CHECK (a == res);
}

