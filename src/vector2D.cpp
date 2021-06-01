#pragma once
#include"vector2D.cpp"


template <>
inline Vector<double, 2> Vector<double, 2>::rotate(const double &theta) const
{
    Vector2D rotated;
    Matrix2D transformation;
    transformation.rotation_matrix(theta);
    rotated = transformation * *this;
    return rotated;
}


template <>
inline double Vector<double,2>::get_slope_angle() const
{
    double angle;
        angle = atan2(size[1], size[0]);
        angle *= 180 / PI;

    return angle;
}
