#include"../include/matrix2D.hpp"


template <>
inline void Matrix<double, 2>::rotation_matrix(const double &angle)
{
    double angle_rad = angle * PI / 180;
    double tmp[][2] = {{cos(angle_rad), -sin(angle_rad)}, {sin(angle_rad), cos(angle_rad)}};
    Matrix2D transformation(tmp);
    *this = transformation;
}