#include"../include/matrix4D.hpp"

template <>
inline void Matrix<double, 4>::rotate_and_translate(const double & alpha, const double & beta, const double & gamma, const Vector3D &tran) 
{
    double tab[4][4] = {{cos(alpha)*cos(beta),  cos(alpha)*sin(beta)*sin(gamma)-sin(alpha)*cos(gamma),    cos(alpha)*sin(beta)*cos(gamma)+ sin(alpha)*sin(gamma),   tran[0]},
                        {sin(alpha)*cos(beta),  sin(alpha)*sin(beta)*sin(gamma)+cos(alpha)*cos(gamma),    sin(alpha)*sin(beta)*cos(gamma)- cos(alpha)*sin(gamma),   tran[1]},
                        {-sin(beta)          ,  cos(beta)*sin(gamma)                                 ,    cos(beta)*cos(gamma)                                  ,   tran[2]},
                        {0                   ,  0                                                    ,    0                                                     ,   1      }};
    *this = Matrix4D(tab);

}