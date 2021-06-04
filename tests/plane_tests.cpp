#include "../tests/doctest/doctest.h"
#include "plane.hpp"

TEST_CASE("Pl 1.01: Konstruktor parametryczny, metody block::get_... 1")
{
    std::string s = "sname";
    std::string f = "fname";
    double tab[3] = {1,1,1};   
    Vector3D vec(tab);
    double x = 20, y = 20;
    Plane a(x,y,s,f);

    CHECK (a.get_sample_name() == "sname");
    CHECK (a.get_final_name() == "fname");
    CHECK (a.get_scale() == vec);
    double resx,resy;
    a.get_plane(resx,resy);
    CHECK(resx == x);
    CHECK(resy == y);
}

TEST_CASE("Pl 1.02: Konstruktor parametryczny, metody block::get_... 2")
{
    std::string s = "";
    std::string f = "";
    double tab[3] = {1,1,1};   
    Vector3D vec(tab);
    double x = 20, y = 20;
    Plane a(x,y,s,f);

    CHECK (a.get_sample_name() == "");
    CHECK (a.get_final_name() == "");
    CHECK (a.get_scale() == vec);
    double resx,resy;
    a.get_plane(resx,resy);
    CHECK(resx == x);
    CHECK(resy == y);
}

TEST_CASE("Pl 1.03: Konstruktor parametryczny, metody block::get_... 3")
{
    std::string s = "sname";
    std::string f = "fname";
    double tab[3] = {1,1,1};   
    Vector3D vec(tab);
    double x = 20, y = 20;
    Plane a(x,y,s,f);

    CHECK (a.get_sample_name() == "sname");
    CHECK (a.get_final_name() == "fname");
    CHECK (a.get_scale() == vec);
    double resx,resy;
    a.get_plane(resx,resy);
    CHECK(resx == x);
    CHECK(resy == y);
}

TEST_CASE("Pl 2.01: check_plane 1")
{
    std::string s = "sname";
    std::string f = "fname";
    double x = 10, y = 10;
    Plane a(x,y,s,f);

    CHECK(a.check_plane());
}
TEST_CASE("Pl 2.02: check_plane 2")
{
    std::string s = "sname";
    std::string f = "fname";
    double x = 9.999999999, y = 9.9999999999;
    Plane a(x,y,s,f);

    CHECK(!a.check_plane());
}
TEST_CASE("Pl 2.03: check_plane 3")
{
    std::string s = "sname";
    std::string f = "fname";
    double x = 104564567, y = 10635736;
    Plane a(x,y,s,f);

    CHECK(a.check_plane());
}

