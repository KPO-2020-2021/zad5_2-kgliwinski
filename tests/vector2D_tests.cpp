
#include"../tests/doctest/doctest.h"

#include"vector2D.hpp"
// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.

TEST_CASE("V 1.01: Vector2D konstruktor bezparametryczny oraz przeciazenie strumienia wyjsciowego<<"){
Vector2D a;

    std::ostringstream out;
    out << a; // 

    CHECK("[ 0.0000000000 ]\n[ 0.0000000000 ]\n" == out.str());
}


TEST_CASE("V 1.02: Vector2D konstruktor parametryczny oraz przeciazenie strumienia #include <cmath>wyjsciowego << i wejsciowego >>"){
    Vector2D a;
    std::istringstream in("1.0 5.0");
    in >> a;
    std::ostringstream out;
    out << a; // 

    CHECK("[ 1.0000000000 ]\n[ 5.0000000000 ]\n" == out.str());
}

TEST_CASE("V 1.03: Vector2D konstruktor parametryczny dla malych wartosci oraz przeciazenie strumienia wyjsciowego << i wejsciowego >>"){
    Vector2D a;
    std::istringstream in("0.0000000001 0.0000000005");
    in >> a;
    std::ostringstream out;
    out << a; // 

    CHECK("[ 0.0000000001 ]\n[ 0.0000000005 ]\n" == out.str());
}

TEST_CASE("V 1.04: Vector2D konstruktor parametryczny dla duzych wartosci oraz przeciazenie strumienia wyjsciowego << i wejsciowego >>"){
    Vector2D a;
    std::istringstream in("12345678 12345678");
    in >> a;
    std::ostringstream out;
    out << a; // 

    CHECK("[ 12345678.0000000000 ]\n[ 12345678.0000000000 ]\n" == out.str());
}

TEST_CASE("V 2.01: Vector2D dodawanie wektorow"){
    double tab[3][2] = {{4,2},{2,7}, {6,9}};
    Vector2D a(tab[0]);
    Vector2D b(tab[1]);
    Vector2D res(tab[2]);

    Vector2D sum = a+b;
    CHECK(res == sum);
}

TEST_CASE("V 2.02: Vector2D dodawanie wektorow dla malych wartosci"){
    double tab[3][2] = {{0.0000000004,0.0000000002},{0.0000000002,0.0000000007}, {0.0000000006,0.0000000009}};
    Vector2D a(tab[0]);
    Vector2D b(tab[1]);
    Vector2D res(tab[2]);

    Vector2D sum = a+b;
    CHECK(res == sum);
}

TEST_CASE("V 2.03: Vector2D dodawanie wektorow dla malych wartosci (dokladnosc ponizej E-10)"){
    double tab[3][2] = {{0.00000000004,0.00000000002},{0.00000000002,0.00000000007}, {0.00000000006,0.00000000009}};
    Vector2D a(tab[0]);
    Vector2D b(tab[1]);
    Vector2D res(tab[2]);

    Vector2D sum = a+b;
    CHECK(res == sum);
}

TEST_CASE("V 2.04: Vector2D dodawanie wektorow dla duzych wartosci, granicze wartosci"){
    double tab[3][2] = {{99999,99999},{1,1},{100000,100000}};
    Vector2D a(tab[0]);
    Vector2D b(tab[1]);
    Vector2D res(tab[2]);

    Vector2D sum = a+b;
    CHECK(res == sum);
}

TEST_CASE("V 3.01: Vector2D odejmowanie wektorow"){
    double tab[3][2] = {{4,2},{2,7}, {2,-5}};
    Vector2D a(tab[0]);
    Vector2D b(tab[1]);
    Vector2D res(tab[2]);

    Vector2D sum = a-b;
    CHECK(res == sum);
}

TEST_CASE("V 3.02: Vector2D odejmowanie wektorow dla malych wartosci"){
    double tab[3][2] = {{0.0000000004,0.0000000002},{0.0000000002,0.0000000007}, {0.0000000002,-0.0000000005}};
    Vector2D a(tab[0]);
    Vector2D b(tab[1]);
    Vector2D res(tab[2]);

    Vector2D sum = a-b;
    CHECK(res == sum);
}

TEST_CASE("V 3.03: Vector2D odejmowanie wektorow dla malych wartosci (dokladnosc ponizej E-10)"){
    double tab[3][2] = {{0.00000000004,0.00000000002},{0.00000000002,0.00000000007}, {0.00000000004,-0.00000000005}};
    Vector2D a(tab[0]);
    Vector2D b(tab[1]);
    Vector2D res(tab[2]);

    Vector2D sum = a+b;
    CHECK(res == sum);
}

TEST_CASE("V 3.04: Vector2D odejmowanie wektorow dla duzych wartosci, granicze wartosci"){
    double tab[3][2] = {{99999,99999},{1,1},{100000,100000}};
    Vector2D a(tab[2]);
    Vector2D b(tab[0]);
    Vector2D res(tab[1]);

    Vector2D sum = a-b;
    CHECK(res == sum);
}

TEST_CASE("V 4.01: Vector2D mnozenie wektorow przez skalar"){
    double tab[2][2] = {{4,2},{136,68}};
    double tmp;
    Vector2D a(tab[0]);
    tmp =34;
    Vector2D b = a*tmp;
    Vector2D res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("V 4.02: Vector2D mnozenie wektorow przez maly skalar"){
    double tab[2][2] = {{4,2},{0.000000004,0.0000000002}};
    double tmp;
    Vector2D a(tab[0]);
    tmp =0.000000001;
    Vector2D b = a*tmp;
    Vector2D res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("V 4.03: Vector2D mnozenie wektorow przez 0"){
    double tab[2][2] = {{4,2},{0,0}};
    double tmp;
    Vector2D a(tab[0]);
    tmp =0;
    Vector2D b = a*tmp;
    Vector2D res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("V 4.04: Vector2D mnozenie wektora zerowego przez skalar"){
    double tab[2][2] = {{0,0},{0,0}};
    double tmp;
    Vector2D a(tab[0]);
    tmp =1231234;
    Vector2D b = a*tmp;
    Vector2D res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("V 5.01: Vector2D dzielenie wektorow przez skalar"){
    double tab[2][2] = {{4,2},{2,1}};
    double tmp;
    Vector2D a(tab[0]);
    tmp =2;
    Vector2D b = a/tmp;
    Vector2D res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("V 5.02: Vector2D dzielenie wektorow przez maly skalar"){
    double tab[2][2] = {{4,2},{40000000000,20000000000}};
    double tmp;
    Vector2D a(tab[0]);
    tmp =0.000000001;
    Vector2D b = a/tmp;
    Vector2D res(tab[1]);

        CHECK(!(a == b));

}

TEST_CASE("V 5.03: Vector2D dzielenie wektorow przez 0"){
    double tab[2][2] = {{4,2},{4,2}};
    double tmp;
    Vector2D a(tab[0]);
    tmp =0;
    Vector2D b = a/tmp;
    Vector2D res(tab[1]);

    CHECK(res == b);    //nothing happened
}

TEST_CASE("V 5.04: Vector2D dzielenie wektora zerowego przez skalar"){
    double tab[2][2] = {{0,0},{0,0}};
    double tmp;
    Vector2D a(tab[0]);
    tmp =1231234;
    Vector2D b = a*tmp;
    Vector2D res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("V 6.01: Vector2D::rotate"){
    double tab[2][2] = {{3,4},{-4,3}};
    double ang;
    Vector2D a(tab[0]);
    ang =90;
    Vector2D b = a.rotate(ang);
    Vector2D res(tab[1]);
    
        CHECK((res == b));
}

TEST_CASE("V 6.02: Vector2D::rotate by 0"){
    double tab[2][2] = {{3,4},{3,4}};
    double ang;
    Vector2D a(tab[0]);
    ang =0;
    Vector2D b = a.rotate(ang);
    Vector2D res(tab[1]);

        CHECK((res == b));
}


TEST_CASE("V 6.03: Vector2D::rotate by 360 deg"){
    double tab[2][2] = {{3,4},{3,4}};
    double ang;
    Vector2D a(tab[0]);
    ang =360;
    Vector2D b = a.rotate(ang);
    Vector2D res(tab[1]);
    
        CHECK((res == b));
}


TEST_CASE("V 6.04: Vector2D::rotate by 36000000 deg"){
    double tab[2][2] = {{3,4},{3,4}};
    double ang;
    Vector2D a(tab[0]);
    ang =36000000;
    Vector2D b = a.rotate(ang);
    Vector2D res(tab[1]);
    
        CHECK((res == b));
}

TEST_CASE("V 6.05: Vector2D::rotate by 180 deg"){
    double tab[2][2] = {{3,4},{-3,-4}};
    double ang;
    Vector2D a(tab[0]);
    ang =180;
    Vector2D b = a.rotate(ang);
    Vector2D res(tab[1]);
    
        CHECK((res == b));
}


TEST_CASE("V 7.01: Vector2D::modulus2"){
    double tab[2][2] = {{3,4}};
    double res;
    Vector2D a(tab[0]);
    res = 25;
    
        CHECK((res == a.modulus2()));
}

TEST_CASE("V 7.02: Vector2D::modulus2 small"){
    double tab[2][2] = {{0.003,0.004}};
    double res;
    Vector2D a(tab[0]);
    res = 0.000025;

        CHECK((abs(res - a.modulus2())<=0.0001));
}

TEST_CASE("V 7.03: Vector2D::modulus2 zero"){
    double tab[2][2] = {{0,0}};
    double res;
    Vector2D a(tab[0]);
    res = 0;
    
        CHECK((res == a.modulus2()));
}

TEST_CASE("V 7.04: Vector2D::modulus2 neg"){
    double tab[2][2] = {{-3,-4}};
    double res;
    Vector2D a(tab[0]);
    res = 25;
    
        CHECK((res == a.modulus2()));
}

TEST_CASE("V 8.01: Vector2D::get_len "){
    double tab[2][2] = {{3,4}};
    double res;
    Vector2D a(tab[0]);
    res = 5;
    
        CHECK((res == a.get_len()));
}

TEST_CASE("V 8.02: Vector2D::get_len small"){
    double tab[2][2] = {{0.003,0.004}};
    double res;
    Vector2D a(tab[0]);
    res = 0.005;
    
        CHECK((res == a.get_len()));
}

TEST_CASE("V 8.03: Vector2D::get_len zero"){
    double tab[2][2] = {{0,0}};
    double res;
    Vector2D a(tab[0]);
    res = 0;
    
        CHECK((res == a.get_len()));
}

TEST_CASE("V 8.04: Vector2D::get_len neg"){
    double tab[2][2] = {{-5,-12}};
    double res;
    Vector2D a(tab[0]);
    res = 13;
    
        CHECK((res == a.get_len()));
}

TEST_CASE("V 9.01: Vector2D::get_slope_angle "){
    double tab[2][2] = {{1,1}};
    double res;
    Vector2D a(tab[0]);
    res = 45.0;

    CHECK (abs(res - a.get_slope_angle())<= 0.000001);
}

TEST_CASE("V 9.02: Vector2D::get_slope_angle 0"){
    double tab[2][2] = {{0,0}};
    double res;
    Vector2D a(tab[0]);
    res = 0;

    CHECK (abs(res - a.get_slope_angle())<= 0.000001);
}

TEST_CASE("V 9.03: Vector2D::get_slope_angle 90 deg"){
    double tab[2][2] = {{0,1}};
    double res;
    Vector2D a(tab[0]);
    res = 90;

    CHECK (abs(res - a.get_slope_angle())<= 0.000001);
}

TEST_CASE("V 10.01: operator []"){
    double tab[2][2] = {{3,1}};
    double res;
    Vector2D a(tab[0]);
    res = 3;

    CHECK (abs(res - a[0])<= 0.000001);
}

TEST_CASE("V 10.02: operator []"){
    double tab[2][2] = {{3,1}};
    double res;
    Vector2D a(tab[0]);
    res = 1;

    CHECK (abs(res - a[1])<= 0.000001);
}

TEST_CASE("V 10.03: operator const []"){
    double tab[2][2] = {{3,1}};
    double res;
    Vector2D a(tab[0]);
    res = 1;

    double b = a[1];
    CHECK (abs(res - b)<= 0.000001);
}
