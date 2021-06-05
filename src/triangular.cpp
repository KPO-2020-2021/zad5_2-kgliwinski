#include"../include/triangular.hpp"

Triangular::Triangular()
{
    int i;
    double iter[4][3] = {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}};
    double tab[3] = {0.5, 0.5, 1};
    Vector3D tip(tab);
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 1;
        tops[1][i] = Vector3D(iter[i]);
    }
    tops[1][0] = tops[1][3];
    tops[1][1] = tops[1][2];
    this->centre = this->special_points(cuts);
}

Triangular::Triangular(std::string const &sample, std::string const &final, Vector3D const &sca)
{
    *this = Triangular();
    this->set_sample_name(sample);
    this->set_final_name(final);
    this->set_scale(sca);
    *this = this->scale_cub();
    this->centre = special_points(this->cuts);
}

Vector3D Triangular::special_points(Vector3D (&vecs)[2]) const
{
    Vector3D cen = centre_point();
    Vector3D side = tops[0][2] - tops[0][1];
    side = side * 0.5;
    vecs[0] = cen;
    vecs[1] = cen + side;
    return cen;
}

Triangular &Triangular::operator=(const Cuboid &a)
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