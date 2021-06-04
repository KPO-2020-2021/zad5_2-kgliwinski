#include "../include/pyramid.hpp"

Pyramid::Pyramid()
{
    int i;
    double iter[4][3] = {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}};
    double tab[3] = {0.5, 0.5, 1};
    Vector3D tip(tab);
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        tops[1][i] = tip;
    }

    this->centre = special_points(this->cuts);
}

Pyramid::Pyramid(std::string const &sample, std::string const &final, Vector3D const &sca)
{
    *this = Pyramid();
    this->set_sample_name(sample);
    this->set_final_name(final);
    this->set_scale(sca);
    *this = this->scale_cub();
    this->centre = special_points(this->cuts);
}

double Pyramid::get_height() const
{
    double res;
    Vector3D diag;
    diag = tops[0][2] - tops[0][0];
    Vector3D point;
    res=1;
    return res;
}

Vector3D Pyramid::centre_point() const
{
    Vector3D point = get_basis_centre();
    return point;
}

Vector3D Pyramid::special_points(Vector3D (&vecs)[2]) const
{
    Vector3D cen = centre_point();
    Vector3D side = tops[0][2] - tops[0][1];
    side = side * 0.5;
    vecs[0] = cen - side;
    vecs[1] = cen + side;
    return cen;
}

Pyramid &Pyramid::operator=(const Cuboid &a)
{
    int i, j;
    Vector3D to_pyr[2][4];
    a.get_cub(to_pyr);
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            tops[i][j] = to_pyr[i][j];
        }
    }
    this->centre = this->special_points(this->cuts);
    return *this;
}