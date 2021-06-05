#include "../tests/doctest/doctest.h"
#include "vector3D.hpp"
#include <list>
#include <vector>

TEST_CASE("Count 1")
{
    Vector3D tmp;
    tmp.zero_count(); //zerowanie licznika
    Vector3D a, b, c, d, e;
    int cou, ali;
    a.get_count(cou, ali);
    CHECK(cou == 5);
    CHECK(ali == 5);
}

TEST_CASE("Count 2")
{
    Vector3D tmp;
    tmp.zero_count(); //zerowanie licznika
    Vector3D a[17], b;
    int cou, ali;
    b.get_count(cou, ali);
    CHECK(cou == 18);
    CHECK(ali == 18);
}

TEST_CASE("Count 3")
{
    Vector3D tmp;
    //bez zerowania
    Vector3D a[17], b, c[12], d;
    int cou, ali;
    b.get_count(cou, ali);
    CHECK(cou == 50);
    CHECK(ali == 31);
}

/* W tym momencie jest 50 zywych wektorow*/
TEST_CASE("Count 4")
{
    Vector3D tmp;
    Vector3D a, b[99];
    int cou, ali;
    a.get_count(cou, ali);
    CHECK(cou == 151);
    CHECK(ali == 100);
}

TEST_CASE("Count 5")
{
    Vector3D tmp;
    tmp.zero_count(); //znowu wyzerowanie
    Vector3D a, b, c, d, e;
    int cou, ali;
    a.get_count(cou, ali);
    CHECK(cou == 5);
    CHECK(ali == 5);
}

TEST_CASE("Count: std::list<> 1")
{
    Vector3D tmp;
    tmp.zero_count(); //znowu wyzerowanie
    std::list<Vector3D> l;
    l.push_back(Vector3D());
    int cou, ali;
    l.front().get_count(cou, ali);
    CHECK(cou == 2); //przy przypisaniu tworzy sie jeden, kolejny w liscie
    CHECK(ali == 1); //Vector3D z przypisania sie ususwa po dokonaniu przypisania
}

TEST_CASE("Count: std::list<> 2")
{
    Vector3D tmp;
    int i;
    tmp.zero_count(); //znowu wyzerowanie
    std::list<Vector3D> l;
    for (i = 0; i < 5; ++i)
        l.push_back(Vector3D());
    int cou, ali;
    l.front().get_count(cou, ali);
    CHECK(cou == 10); //przy przypisaniu tworzy sie jeden x5, kolejny w liscie
    CHECK(ali == 5); //Vector3D z przypisania sie ususwa po dokonaniu przypisania
}

TEST_CASE("Count: std::vector<> 1")
{
    Vector3D tmp;
    tmp.zero_count(); //znowu wyzerowanie
    std::vector<Vector3D> l;
    l.push_back(Vector3D());
    int cou, ali;
    l.front().get_count(cou, ali);
    CHECK(cou == 2); //przy przypisaniu tworzy sie jeden, kolejny w liscie
    CHECK(ali == 1); //Vector3D z przypisania sie ususwa po dokonaniu przypisania
}

TEST_CASE("Count: std::vector<> 2")
{
    Vector3D tmp;
    int i;
    tmp.zero_count(); //znowu wyzerowanie
    std::vector<Vector3D> l;
    for (i = 0; i < 5; ++i)
        l.push_back(Vector3D());
    int cou, ali;
    l.front().get_count(cou, ali);
    CHECK(cou == 17);
    CHECK(ali == 5);
}