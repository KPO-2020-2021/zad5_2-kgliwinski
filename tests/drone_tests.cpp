#include"../tests/doctest/doctest.h"
#include"../include/drone.hpp"
#include <ctime>
#include <unistd.h>

std::string gen_random(const int len) {
    
    std::string tmp_s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    srand( (unsigned) time(NULL) * getpid());

    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    
    
    return tmp_s;
    
}

TEST_CASE("D 1.01: konstruktor bezparametryczny drona oraz operatora ==")
{
    Drone a;
    Drone b;

    CHECK (a==b);
    double tab2[3]={1,0,0};
    Vector3D res(tab2);
    CHECK (res == a.get_orien());
    CHECK (res == b.get_orien());
}

TEST_CASE("D 1.02: konstruktor bezparametryczny drona oraz operatora == 1")
{
    Drone a;
    Drone b;
    double tab[3] = {1223,124312,4124};
    Vector3D tr(tab);
    a = a.translation(tr);
    b = b.translation(tr);
    CHECK (a==b);    
    double tab2[3]={1,0,0};
    Vector3D res(tab2);
    CHECK (res == a.get_orien());
    CHECK (res == b.get_orien());
}

TEST_CASE("D 1.03: konstruktor bezparametryczny drona oraz operatora == 2")
{
    Drone a;
    Drone b;
    double tab[3] = {1223,124312,4124};
    Vector3D tr(tab);
    a = a.translation(tr);
    tab[0] = -12414;
    tr = Vector3D(tab);
    b = b.translation(tr);
    CHECK (!(a==b));
    double tab2[3]={1,0,0};
    Vector3D res(tab2);
    CHECK (res == a.get_orien());
    CHECK (res == b.get_orien());
}

TEST_CASE("D 2.01: setup_files() check_files() 1")
{
    int i,j;
    std::string tmp = "a";
    std::string b[2], r[4][2];
    for(i=0;i<2;++i)
    {
        b[i] = tmp;
        for(j=0;j<4;++j)
        {
            r[j][i] = tmp;
        }
    }
    Drone dron;
    dron.setup_filenames(b, r);
    std::string b2[2], r2[4][2];
    dron.get_filenames(b2,r2);
    for(i=0;i<2;++i)
    {
        CHECK(b[i] == b2[i]);
        for(j=0;j<4;++j)
        {
            CHECK(r[j][i] == r2[j][i]);
        }
    }  
}

TEST_CASE("D 2.02: setup_files() check_files() 2")
{
    int i,j;
    std::string tmp = gen_random(12);
    std::string b[2], r[4][2];
    for(i=0;i<2;++i)
    {
        b[i] = tmp;
        for(j=0;j<4;++j)
        {
            r[j][i] = tmp;
        }
    }
    Drone dron;
    dron.setup_filenames(b, r);
    std::string b2[2], r2[4][2];
    dron.get_filenames(b2,r2);
    for(i=0;i<2;++i)
    {
        CHECK(b[i] == b2[i]);
        for(j=0;j<4;++j)
        {
            CHECK(r[j][i] == r2[j][i]);
        }
    }  
}

TEST_CASE("D 2.03: setup_files() check_files() 3")
{
    int i,j;
    std::string tmp = "";
    std::string b[2], r[4][2];
    for(i=0;i<2;++i)
    {
        b[i] = tmp;
        for(j=0;j<4;++j)
        {
            r[j][i] = tmp;
        }
    }
    Drone dron;
    dron.setup_filenames(b, r);
    std::string b2[2], r2[4][2];
    dron.get_filenames(b2,r2);
    for(i=0;i<2;++i)
    {
        CHECK(b[i] == b2[i]);
        for(j=0;j<4;++j)
        {
            CHECK(r[j][i] == r2[j][i]);
        }
    }  
}
TEST_CASE("D 2.04: set_drone_pos() 1")
{
    double tab[3] = {1,1,10};
    Vector3D p(tab);
    Drone a;
    CHECK (a.set_drone_pos(p));
}

TEST_CASE("D 2.05: set_drone_pos() 2")
{
    double tab[3] = {1,1,-1};
    Vector3D p(tab);
    Drone a;
    CHECK (!a.set_drone_pos(p));
}

TEST_CASE("D 2.06: set_drone_pos() 3")
{
    double tab[3] = {1,1,2.499999};
    Vector3D p(tab);
    Drone a;
    CHECK (!a.set_drone_pos(p));
}

TEST_CASE("D 2.07: set_scale_all() 1")
{
    double tab[3] = {100,100,100};
    Vector3D p(tab);
    Drone a;
    a.set_scale_all(p,p);
    int i;
    Cuboid body;
    Prism rotors[4];
    Vector3D x;
    a.get_dro(body, rotors, x);
    CHECK (body.get_scale() == p);
    for (i=0;i<4;++i)
    {
        CHECK (rotors[i].get_scale() == p);
    }
}

TEST_CASE("D 2.08: set_scale_all() 2")
{
    double tab[3] = {100,100,100};
    Vector3D p(tab);
    Drone a;
    Matrix3D mat;
    mat = mat.rotation_matrix(234,'x');
    mat = mat.rotation_matrix(234,'y') * mat;
    mat = mat.rotation_matrix(234,'z') * mat;
    a = a.rotation_around_cen(mat);
    a.set_scale_all(p,p);
    int i;
    Cuboid body;
    Prism rotors[4];
    Vector3D x;
    a.get_dro(body, rotors, x);
    CHECK (body.get_scale() == p);
    for (i=0;i<4;++i)
    {
        CHECK (rotors[i].get_scale() == p);
    }
}

TEST_CASE("D 2.09: set_scale_all() 3")
{
    double tab[3] = {100,100,100};
    Vector3D p(tab);
    Drone a;
    a.set_scale_all(p,p);
    Matrix3D mat;
    mat = mat.rotation_matrix(234,'x');
    mat = mat.rotation_matrix(234,'y') * mat;
    mat = mat.rotation_matrix(234,'z') * mat;
    a = a.rotation_around_cen(mat);
    int i;
    Cuboid body;
    Prism rotors[4];
    Vector3D x;
    a.get_dro(body, rotors, x);
    CHECK (body.get_scale() == p);
    for (i=0;i<4;++i)
    {
        CHECK (rotors[i].get_scale() == p);
    }
}

TEST_CASE("D 3.01: check_dro() 1")
{
    Drone a;
    CHECK (a.check_dro());
}



TEST_CASE("D 3.02: check_dro() 2")
{
    Drone a;
    double tab[3] = {232,123,123};
    Vector3D sca(tab);
    a.set_scale_all(sca,sca);
    a = a.scale_dro();
    CHECK (!a.check_dro());
}

TEST_CASE("D 3.03: check_dro() 3")
{
    Drone a;
    double tab1[3] = {1233,123,123};
    double tab2[3] = {1,2,3};
    Vector3D vec1(tab1), vec2(tab2);
    a.set_scale_all(vec1,vec2);
    a = a.scale_dro();
    CHECK (!a.check_dro());
}

TEST_CASE("D 4.01: Drone rotation 1")
{
    Drone a,b;
    Matrix3D mat;
    mat = mat.rotation_matrix(360,'z');
    a.rotation_around_cen(mat);
    CHECK (a==b);
    double tab[3]={1,0,0};
    Vector3D res(tab);
    CHECK (res == a.get_orien());
}

TEST_CASE("D 4.02: Drone rotation 2")
{
    Drone a,b;
    Matrix3D mat;
    mat = mat.rotation_matrix(60,'z');
    a.rotation_around_cen(mat);
    CHECK (a.get_orien().get_len() == 1);
}

TEST_CASE("D 4.03: Drone rotation 3")
{
    Drone a,b;
    Matrix3D mat;
    mat = mat.rotation_matrix(60,'z');
    a.rotation_around_cen(mat);
    CHECK (a.get_orien().get_len() == 1);
}

TEST_CASE("D 4.04: Drone rotation 4")
{
    Drone a,b;
    Matrix3D mat;
    mat = mat.rotation_matrix(65135,'y');
    a.rotation_around_cen(mat);
    CHECK (a.get_orien().get_len() == 1);
}

TEST_CASE("D 4.05: Drone rotation 5")
{
    Drone a,b;
    Matrix3D mat;
    mat = mat.rotation_matrix(451413,'x');
    a.rotation_around_cen(mat);
    CHECK (a.get_orien().get_len() == 1);
}

TEST_CASE("D 5.01: Drone::get_body_height()")
{
    Drone a,b;
    Matrix3D mat;
    CHECK (a.get_body_height() == 5);
}