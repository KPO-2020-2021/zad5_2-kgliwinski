#include "../include/volcano.hpp"

Volcano::Volcano()
{
    int i;
    double iter[6][3] = {{1, 0, -0.5}, {0.5, sqrt(3) * 0.5, -0.5}, {-0.5, sqrt(3) * 0.5, -0.5}, {-1, 0, -0.5}, {-0.5, -sqrt(3) * 0.5, -0.5}, {0.5, -sqrt(3) * 0.5, -0.5}};
    for (i = 0; i < 6; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][0] /= 3.0;
        iter[i][1] /= 3.0;
        iter[i][2] = 0.5;
        tops[1][i] = Vector3D(iter[i]);
    }
    this->centre = this->special_points(cuts);
}

Volcano::Volcano(std::string const &sample, std::string const &final, Vector3D const &sca)
{
    *this = Volcano();
    this->set_sample_name(sample);
    this->set_final_name(final);
    this->set_scale(sca);
    *this = this->scale_pri();
    this->centre = special_points(this->cuts);
}

double Volcano::get_height() const
{
    double tab[3] = {tops[1][0][0], tops[1][0][1], tops[0][0][2]};
    Vector3D tmp(tab);
    Vector3D ver = tops[1][0] - tmp;
    double res = ver.get_len();
    return res;
}

Vector3D Volcano::centre_point() const
{
    double tab[3] = {tops[1][0][0], tops[1][0][1], tops[0][0][2]};
    Vector3D tmp(tab);
    Vector3D ver = tops[1][0] - tmp;
    Vector3D res = cuts[0] + ver * 0.5;
    return res;
}

Vector3D Volcano::special_points(Vector3D (&vecs)[2]) const
{
    Vector3D diag = tops[0][3] - tops[0][0];
    vecs[0] = tops[0][0] + diag * 0.5;
    vecs[1] = centre_point();
    Vector3D cen = centre_point();
    return cen;
}

Volcano &Volcano::operator=(const Prism &a)
{
    int i, j;
    Vector3D to_pyr[2][6];
    a.get_pri(to_pyr);
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 6; ++j)
        {
            tops[i][j] = to_pyr[i][j];
        }
    }
    this->centre = this->special_points(this->cuts);
    return *this;
}