#include "../tests/doctest/doctest.h"
#include "vector3D.hpp"

TEST_CASE("Count 1")
{
    Vector3D tmp;
    tmp.zero_count(); //zerowanie licznika
    Vector3D a,b,c,d,e;
    int cou,ali;
    a.get_count(cou,ali);
    CHECK (cou == 5);
    CHECK (ali ==5);
}

TEST_CASE("Count 2")
{
    Vector3D tmp;
    tmp.zero_count(); //zerowanie licznika
    Vector3D a[17], b;
    int cou,ali;
    b.get_count(cou,ali);
    CHECK (cou == 18);
    CHECK (ali ==18);
}

TEST_CASE("Count 3")
{
    Vector3D tmp;
    //bez zerowania
    Vector3D a[17], b, c[12], d;
    int cou,ali;
    b.get_count(cou,ali);
    CHECK (cou == 50);
    CHECK (ali ==31);
}

/* W tym momencie jest 50 zywych wektorow*/
TEST_CASE("Count 4")
{
    Vector3D tmp;
    Vector3D a,b[99];
    int cou,ali;
    a.get_count(cou,ali);
    CHECK (cou == 151);
    CHECK (ali == 100);
}

TEST_CASE("Count 5")
{
    Vector3D tmp;
    tmp.zero_count(); //znowy wyzerowanie
    Vector3D a,b,c,d,e;
    int cou,ali;
    a.get_count(cou,ali);
    CHECK (cou == 5);
    CHECK (ali ==5);
}