#include"../tests/doctest/doctest.h"
#include"../include/scene.hpp"

TEST_CASE("S 1.01: konstruktor parametryczny sceny, przeciazenie == 1")
{
    double pos[3] = {1,2,3};
    double sca[3] = {10,10,10};
    Vector3D posi[2], scal[2];
    int i,j,k;
    for(i=0;i<2;++i)
    {
        posi[i] = Vector3D(pos);
        scal[i] = Vector3D(sca);
    }
    std::string bn[2][2];
    std::string sn[2][4][2];

    for(i=0;i<2;++i){
        for(j=0;j<2;++j)
        {
            bn[i][j] == "";
            for(k=0;k<4;++k){
                sn[i][k][j] == "";
            }
        }
    }
    Scene a(posi,scal,scal,bn,sn);
    Scene b(posi,scal,scal,bn,sn);
    CHECK (a == b);
}

TEST_CASE("S 1.02: konstruktor parametryczny sceny, przeciazenie == 2")
{
    double pos[3] = {14124,124124,124124};
    double sca[3] = {10,10,10};
    Vector3D posi[2], scal[2];
    int i,j,k;
    for(i=0;i<2;++i)
    {
        posi[i] = Vector3D(pos);
        scal[i] = Vector3D(sca);
    }
    std::string bn[2][2];
    std::string sn[2][4][2];

    for(i=0;i<2;++i){
        for(j=0;j<2;++j)
        {
            bn[i][j] == "";
            for(k=0;k<4;++k){
                sn[i][k][j] == "";
            }
        }
    }
    Scene a(posi,scal,scal,bn,sn);
    Scene b(posi,scal,scal,bn,sn);
    b.choose_drone(1);
    CHECK (a == b);
}

TEST_CASE("S 1.03: konstruktor parametryczny sceny, przeciazenie == 3")
{
    double pos[3] = {14124,124124,124124};
    double sca[2][3] = {{10,10,10},{11,11,11}};
    Vector3D posi[2], scal[2];
    int i,j,k;
    for(i=0;i<2;++i)
    {
        posi[i] = Vector3D(pos);
        scal[i] = Vector3D(sca[i]);
    }
    std::string bn[2][2];
    std::string sn[2][4][2];

    for(i=0;i<2;++i){
        for(j=0;j<2;++j)
        {
            bn[i][j] == "";
            for(k=0;k<4;++k){
                sn[i][k][j] == "";
            }
        }
    }
    Scene a(posi,scal,scal,bn,sn);
    Scene b(posi,scal,scal,bn,sn);
    CHECK (a == b);
}

TEST_CASE("S 2.01: std::list<std::shared_ptr<>> 1")
{
    double pos[3] = {1,2,3};
    double sca[3] = {10,10,10};
    Vector3D posi[2], scal[2];
    int i,j,k;
    for(i=0;i<2;++i)
    {
        posi[i] = Vector3D(pos);
        scal[i] = Vector3D(sca);
    }
    std::string bn[2][2];
    std::string sn[2][4][2];

    for(i=0;i<2;++i){
        for(j=0;j<2;++j)
        {
            bn[i][j] == "";
            for(k=0;k<4;++k){
                sn[i][k][j] == "";
            }
        }
    }
    Scene a(posi,scal,scal,bn,sn);
    a.init_objects(200,200);

    CHECK(a.get_objects_size() == 1);
}

TEST_CASE("S 2.02: std::list<std::shared_ptr<>> 1")
{
    double pos[3] = {1,2,3};
    double sca[3] = {10,10,10};
    Vector3D posi[2], scal[2];
    int i,j,k;
    for(i=0;i<2;++i)
    {
        posi[i] = Vector3D(pos);
        scal[i] = Vector3D(sca);
    }
    std::string bn[2][2];
    std::string sn[2][4][2];

    for(i=0;i<2;++i){
        for(j=0;j<2;++j)
        {
            bn[i][j] == "";
            for(k=0;k<4;++k){
                sn[i][k][j] == "";
            }
        }
    }
    Scene a(posi,scal,scal,bn,sn);
    a.init_objects(200,200);
    a.add_basic_objects();

    CHECK(a.get_objects_size() == 7);
}

TEST_CASE("S 3.01: get_active, get_filename_num")
{
    double pos[3] = {1,2,3};
    double sca[3] = {10,10,10};
    Vector3D posi[2], scal[2];
    int i,j,k;
    for(i=0;i<2;++i)
    {
        posi[i] = Vector3D(pos);
        scal[i] = Vector3D(sca);
    }
    std::string bn[2][2];
    std::string sn[2][4][2];

    for(i=0;i<2;++i){
        for(j=0;j<2;++j)
        {
            bn[i][j] == "";
            for(k=0;k<4;++k){
                sn[i][k][j] == "";
            }
        }
    }
    Scene a(posi,scal,scal,bn,sn);
    CHECK(a.get_active() == 0);
    CHECK(a.get_filename_num() == 0);
}

TEST_CASE("S 3.02: switch_create_filenames && get_filename_num")
{
    double pos[3] = {1,2,3};
    double sca[3] = {10,10,10};
    Vector3D posi[2], scal[2];
    int i,j,k;
    for(i=0;i<2;++i)
    {
        posi[i] = Vector3D(pos);
        scal[i] = Vector3D(sca);
    }
    std::string bn[2][2];
    std::string sn[2][4][2];

    for(i=0;i<2;++i){
        for(j=0;j<2;++j)
        {
            bn[i][j] == "";
            for(k=0;k<4;++k){
                sn[i][k][j] == "";
            }
        }
    }
    Scene a(posi,scal,scal,bn,sn);
    std::string s1,f1,s2,f2,s3,f3;
    a.switch_create_filenames(s1,f1,"Cuboid");
    CHECK(s1 == "Cuboid1.dat");
    CHECK(f1 == "Cuboid1.dat");
    CHECK(a.get_filename_num() == 1);
    a.switch_create_filenames(s2,f2,"Cuboid");
    CHECK(s2 == "Cuboid2.dat");
    CHECK(f2 == "Cuboid2.dat");
    CHECK(a.get_filename_num() == 2);
    a.switch_create_filenames(s3,f3,"");
    CHECK(s3 == "3.dat");
    CHECK(f3 == "3.dat");
    CHECK(a.get_filename_num() == 3);
}