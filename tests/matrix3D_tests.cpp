#include"../tests/doctest/doctest.h"
#include"matrix3D.hpp"
#include"vector3D.hpp"

TEST_CASE("M 1.01: konstruktor bezparametryczny i przeciazenie operatorow << >>"){
    //double tab[3][3] = {{3,1}};
    Matrix3D a;
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 1.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 1.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 1.0000000000 * ");
}

TEST_CASE("M 1.02: konstruktor parametryczny i przeciazenie operatorow << >>"){
    double tab[3][3] = {{3,1,0},{3,1,0},{3,1,0}};
    Matrix3D a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 3.0000000000 * | 1.0000000000 * | 0.0000000000 * | 3.0000000000 * | 1.0000000000 * | 0.0000000000 * | 3.0000000000 * | 1.0000000000 * | 0.0000000000 * ");
}

TEST_CASE("M 1.03: konstruktor parametryczny i przeciazenie operatorow << >>"){
    double tab[3][3] = {{0.0003,0.0001,0},{0.0003,0.0001,0},{0.0003,0.0001,0}};
    Matrix3D a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 0.0003000000 * | 0.0001000000 * | 0.0000000000 * | 0.0003000000 * | 0.0001000000 * | 0.0000000000 * | 0.0003000000 * | 0.0001000000 * | 0.0000000000 * ");
}

TEST_CASE("M 1.04: konstruktor parametryczny i przeciazenie operatorow << >>"){
    double tab[3][3] = {{-0.0003,0.0001,0},{0.0003,-0.0001,0},{0,0,0}};
    Matrix3D a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| -0.0003000000 * | 0.0001000000 * | 0.0000000000 * | 0.0003000000 * | -0.0001000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * ");
}

TEST_CASE("M 1.05: konstruktor parametryczny i przeciazenie operatorow << >>"){
    double tab[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    Matrix3D a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * ");
}

TEST_CASE("M 1.06:  przeciazenie operatorow << >>"){
    double tab[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    Matrix3D a(tab);
    std::istringstream in("1 2 3 4 5 6 7 8 9");
    in >> a;
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 1.0000000000 * | 2.0000000000 * | 3.0000000000 * | 4.0000000000 * | 5.0000000000 * | 6.0000000000 * | 7.0000000000 * | 8.0000000000 * | 9.0000000000 * ");
}

TEST_CASE("M 2.01: operator * (vector)"){
    double tab[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    double vec[3] = {1,2,3};
    Matrix3D a(tab);
    Vector3D b(vec);

    Vector3D c(vec);

    CHECK (c==(a*b));
}

TEST_CASE("M 2.02: operator * (vector) zero"){
    double tab[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    double vec[3] = {0,0,0};
    Matrix3D a(tab);
    Vector3D b(vec);

    Vector3D c(vec);

    CHECK (c==(a*b));
}

TEST_CASE("M 2.03: operator * (vector) neg"){
    double tab[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    double vec[3] = {1,-1,1};
    double res[3] = {2,5,8};
    Matrix3D a(tab);
    Vector3D b(vec);

    Vector3D c(res);

    CHECK (c==(a*b));
}

TEST_CASE("M 3.01: operator +"){
    double tab[3][3] = {{1,2,0},{3,4,0},{0,0,0}};
    double tab2[3][3] = {{4,3,0},{2,1,0},{0,0,0}};
    double res[3][3] = {{5,5,0},{5,5,0},{0,0,0}};

    Matrix3D a(tab);
    Matrix3D b(tab2);

    Matrix3D c(res);

    CHECK (c==(a+b));
}

TEST_CASE("M 3.02: operator + 0"){
    double tab[3][3] = {{1,2,0},{3,4,0},{0,0,0}};
    double tab2[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    double res[3][3] = {{1,2,0},{3,4,0},{0,0,0}};

    Matrix3D a(tab);
    Matrix3D b(tab2);

    Matrix3D c(res);

    CHECK (c==(a+b));
}

TEST_CASE("M 3.03: operator + small"){
    double tab[3][3] = {{1,2,0},{3,4,0},{0,0,0}};
    double tab2[3][3] = {{0.0000000001,0.0000000001,0},{0.0000000001,0.0000000001,0},{0,0,0}};
    double res[3][3] = {{1.0000000001,2.0000000001,0},{3.0000000001,4.0000000001,0},{0,0,0}};

    Matrix3D a(tab);
    Matrix3D b(tab2);

    Matrix3D c(res);

    CHECK (c==(a+b));
}

TEST_CASE("M 4.01: operator ()"){
    double tab[3][3] = {{1,2,0},{3,4,0},{0,0,0}};
    double res = 1;

    Matrix3D a(tab);

    CHECK (res == a(0,0));
}

TEST_CASE("M 4.02: operator ()"){
    double tab[3][3] = {{1,0.00002,0},{3,4,0},{0,0,0}};
    double res = 0.00002;

    Matrix3D a(tab);

    CHECK (res == a(0,1));
}

TEST_CASE("M 4.03: operator ()"){
    double tab[3][3] = {{1,2,0},{-3,4,0},{0,0,0}};
    double res = -3;

    Matrix3D a(tab);

    CHECK (res == a(1,0));
}

TEST_CASE("M 4.04: operator ()"){
    double tab[3][3] = {{1,2,0},{-3,0,0},{0,0,0}};
    double res = 0;

    Matrix3D a(tab);

    CHECK (res == a(1,1));
}

TEST_CASE("M 5.01: Matrix3D::gauss()"){
    double tab[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    double tab2[3][3] = {{1,2,3},{0,-3,-6},{0.6,0,-0.6}};
    Matrix3D a(tab);
    Matrix3D b(tab2);

    CHECK ((a.gauss()) == b);
}

TEST_CASE("M 5.02: Matrix3D::gauss() 2"){
    double tab[3][3] = {{3,2},{3,4}};
    double tab2[3][3] = {{3,2},{0,2}};
    Matrix3D a(tab);
    Matrix3D b(tab2);

    CHECK ((a.gauss()) == b);
}

TEST_CASE("M 5.03: Matrix3D::determinant() 1"){
    double tab[3][3] = {{1,2},{3,4}};
    Matrix3D a(tab);
    double det; 
    det = 0;
    CHECK ((a.determinant()) == det);
}

TEST_CASE("M 5.04: Matrix3D::determinant() 2"){
    double tab[3][3] = {{3,2},{3,4}};
    Matrix3D a(tab);
    double det; 
    det = 0;
    CHECK ((a.determinant()) == det);
}

TEST_CASE("M 6.01: Matrix3D::multiply() 1"){
    double tab[3][3] = {{3,2,1},{3,4,1},{1,1,1}};
    Matrix3D a(tab);  //macierz jednostkowa
    Matrix3D b;
    double tab_res[3][3] = {{3,2,1},{3,4,1},{1,1,1}};
    Matrix3D res(tab_res);
    CHECK (a*b == res);
}

TEST_CASE("M 6.02: Matrix3D::multiply() 2"){
    double tab[3][3] = {{1,2},{3,4}};
    Matrix3D a(tab);  //macierz jednostkowa
    Matrix3D b(tab);
    double tab_res[3][3] = {{7,10},{15,22}};
    Matrix3D res(tab_res);
    CHECK (a*b == res);
}

TEST_CASE("M 6.03: Matrix3D::multiply() 3"){
    double tab[3][3] = {{4,2,4},{4,21,4},{6,9,8}};
    double tab2[3][3] = {{1,3,2},{4,2,1},{4,3,2}};
    Matrix3D a(tab);  //macierz jednostkowa
    Matrix3D b(tab2);
    double tab_res[3][3] = {{28,28,18},{104,66,37},{74,60,37}};
    Matrix3D res(tab_res);
    CHECK (a*b == res);
}

TEST_CASE("M 7.01: 3D rotation x"){
    Matrix3D a;
    a = a.rotation_matrix(90,'x');
    double tab[3][3] = {{1,0,0},{0,0,-1},{0,1,0}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("M 7.02: 3D rotation x 2"){
    Matrix3D a;
    a = a.rotation_matrix(180,'x');
    double tab[3][3] = {{1,0,0},{0,-1,0},{0,0,-1}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("M 7.03: 3D rotation x 3"){
    Matrix3D a;
    a = a.rotation_matrix(450,'x');
    double tab[3][3] = {{1,0,0},{0,0,-1},{0,1,0}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("M 7.04: 3D rotation y"){
    Matrix3D a;
    a = a.rotation_matrix(0,'y');
    double tab[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("M 7.05: 3D rotation y 2"){
    Matrix3D a;
    a = a.rotation_matrix(135,'y');
    double tab[3][3] = {{-sqrt(2)/2,0,sqrt(2)/2},{0,1,0},{-sqrt(2)/2,0,-sqrt(2)/2}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("M 7.06: 3D rotation y 3"){
    Matrix3D a;
    a = a.rotation_matrix(60,'y');
    double tab[3][3] = {{1/2,0,sqrt(3)/2},{0,1,0},{-sqrt(3)/2,0,1/2}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("M 7.07: 3D rotation z"){
    Matrix3D a;
    a = a.rotation_matrix(360,'z');
    double tab[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("M 7.08: 3D rotation z 2"){
    Matrix3D a;
    a = a.rotation_matrix(360000000,'z');
    double tab[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("M 7.09: 3D rotation z 3"){
    Matrix3D a;
    a = a.rotation_matrix(-360000000,'z');
    double tab[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("M 7.10: 3D rotation multiple axis"){
    Matrix3D a;
    a = a.rotation_matrix(90,'z');
    a = a * a.rotation_matrix(90,'y');
    a = a * a.rotation_matrix(90,'x');
    double tab[3][3] = {{0,0,1},{0,1,0},{-1,0,0}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("M 7.11: 3D rotation multiple axis"){
    Matrix3D a;
    a = a.rotation_matrix(0,'z');
    a = a * a.rotation_matrix(0,'y');
    a = a * a.rotation_matrix(0,'x');
    double tab[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("M 8.01: Matrix3D::apply_matrix_to_rotation() 1"){
    Matrix3D a;
    a = a.rotation_matrix(90,'z');
    double tab[3] = {1,1,1};
    Vector3D vec(tab);
    vec = a.apply_matrix_to_rotation(vec);
    double tab_res[3] = {-1,1,1}; 
    Vector3D res(tab_res);
    CHECK (vec == res);
}

TEST_CASE("M 8.02: Matrix3D::apply_matrix_to_rotation() 2"){
    Matrix3D a;
    a = a.rotation_matrix(30,'y');
    double tab[3] = {1,1,1};
    Vector3D vec(tab);
    vec = a.apply_matrix_to_rotation(vec);
    double tab_res[3] = {1.366025404,1,0.366025404}; 
    Vector3D res(tab_res);
    CHECK (vec == res);
}

TEST_CASE("M 8.03: Matrix3D::apply_matrix_to_rotation() 3"){
    Matrix3D a;
    a = a.rotation_matrix(135,'x');
    double tab[3] = {1,1,1};
    Vector3D vec(tab);
    vec = a.apply_matrix_to_rotation(vec);
    double tab_res[3] = {1,-1.414213562,0}; 
    Vector3D res(tab_res);
    CHECK (vec == res);
}

TEST_CASE("M 8.04: Matrix3D::apply_matrix_to_rotation() multiple 1"){
    Matrix3D a;
    a = a.rotation_matrix(90,'x');
    a = a * a.rotation_matrix(90,'y');
    a = a * a.rotation_matrix(90,'z');
    double tab[3] = {1,1,1};
    Vector3D vec(tab);
    vec = a.apply_matrix_to_rotation(vec);
    double tab_res[3] = {1,-1,1}; 
    Vector3D res(tab_res);
    CHECK (vec == res);
}

TEST_CASE("M 8.05: Matrix3D::apply_matrix_to_rotation() multiple 2"){
    Matrix3D a;
    a = a.rotation_matrix(135,'z');
    a = a * a.rotation_matrix(135,'y');
    a = a * a.rotation_matrix(135,'x');
    double tab[3] = {1,1,1};
    Vector3D vec(tab);
    vec = a.apply_matrix_to_rotation(vec);
    double tab_res[3] = {1.5,-0.5,-0.7071067812}; 
    Vector3D res(tab_res);
    CHECK (vec == res);
}

TEST_CASE("M 8.06: Matrix3D::apply_matrix_to_rotation() multiple 3"){
    Matrix3D a;
    a = a.rotation_matrix(270,'z');
    a = a * a.rotation_matrix(180,'y');
    a = a * a.rotation_matrix(135,'x');
    double tab[3] = {1,1,1};
    Vector3D vec(tab);
    vec = a.apply_matrix_to_rotation(vec);
    double tab_res[3] = {-1.414213562,1,0}; 
    Vector3D res(tab_res);
    CHECK (vec == res);
}

TEST_CASE("M 8.07: Matrix3D::apply_matrix_to_rotation() multiple 4"){
    Matrix3D a;
    a = a.rotation_matrix(270,'z');
    a = a * a.rotation_matrix(180,'y');
    a = a * a.rotation_matrix(135,'x');
    double tab[3] = {2,1,3};
    Vector3D vec(tab);
    vec = a.apply_matrix_to_rotation(vec);
    double tab_res[3] = {-2.828427125,2,1.414213562}; 
    Vector3D res(tab_res);
    CHECK (vec == res);
}

TEST_CASE("M 8.08: Matrix3D::apply_matrix_to_rotation() multiple 5"){
    Matrix3D a;
    a = a.rotation_matrix(270,'x');
    a = a * a.rotation_matrix(180,'y');
    a = a * a.rotation_matrix(135,'z');
    double tab[3] = {2,1,3};
    Vector3D vec(tab);
    vec = a.apply_matrix_to_rotation(vec);
    double tab_res[3] = {2.121320344,-3,-0.707106781}; 
    Vector3D res(tab_res);
    CHECK (vec == res);
}

TEST_CASE("M 8.09: Matrix3D::apply_matrix_to_rotation() multiple 6"){
    Matrix3D a;
    a = a.rotation_matrix(270,'x');
    a = a * a.rotation_matrix(180,'x');
    a = a * a.rotation_matrix(135,'x');
    double tab[3] = {2,1,3};
    Vector3D vec(tab);
    vec = a.apply_matrix_to_rotation(vec);
    double tab_res[3] = {2,1.414213562,-2.828427125}; 
    Vector3D res(tab_res);
    CHECK (vec == res);
}

TEST_CASE("M 8.10: Matrix3D::apply_matrix_to_rotation() multiple 6"){
    Matrix3D a;
    a = a.rotation_matrix(270,'y');
    a = a * a.rotation_matrix(180,'y');
    a = a * a.rotation_matrix(135,'y');
    double tab[3] = {6,1,13};
    Vector3D vec(tab);
    vec = a.apply_matrix_to_rotation(vec);
    double tab_res[3] = {-13.43502884,1,-4.949747468}; 
    Vector3D res(tab_res);
    CHECK (vec == res);
}