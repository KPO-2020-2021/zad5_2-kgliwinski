#pragma once
#include"../include/matrix3D.hpp"


template <>
inline Matrix<double,3> Matrix<double, 3>::rotation_matrix(const double & angle, const char &axis) const
{
double rad = angle *PI/180; //konwersja ze stopni na radiany
switch (axis){
    case 'x':
    {
        double tab[3][3] = {{1,0         ,0          }, 
                            {0,cos(rad),-sin(rad)}, 
                            {0,sin(rad),cos(rad)}};
        Matrix3D rotation(tab);
        return rotation;
        break;
    }
    case 'y':
    {
        double tab[3][3] = {{cos(rad) ,0,sin(rad)},
                            {0          ,1,0         }, 
                            {-sin(rad),0,cos(rad)}};
        Matrix3D rotation(tab);
        return rotation;
        break;
    }
    case 'z':
    {
        double tab[3][3] = {{cos(rad),-sin(rad),0},
                            {sin(rad), cos(rad),0},
                            {0         ,0          ,1}};
        Matrix3D rotation(tab);
        return rotation;
        break;
    }
    default:
    {
        Matrix3D rotation; //utworzenie macierzy jednostkowej (aby nie zmieniala nic przy mnozeniu)
        return rotation;   //brak komunikatu bledu, znajdzie sie on w menu
        break;
    }
}
}

template <>
inline Vector<double,3> Matrix<double,3>::apply_matrix_to_rotation(const Vector<double,3> &to_rot) const{
Matrix3D mat = *this;
Vector3D tmp ;

tmp = mat * to_rot;

return tmp;
}