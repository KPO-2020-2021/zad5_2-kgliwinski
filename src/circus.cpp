#include "../include/circus.hpp"

Circus::Circus()
{
    int i;
    double iter[6][3] = {{1, 0, -0.5}, {0.5, sqrt(3) * 0.5, -0.5}, {-0.5, sqrt(3) * 0.5, -0.5}, {-1, 0, -0.5}, {-0.5, -sqrt(3) * 0.5, -0.5}, {0.5, -sqrt(3) * 0.5, -0.5}};
    for (i = 0; i < 6; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 0.5;
        tops[1][i] = Vector3D(iter[i]);
    }
    centre = this->special_points(cuts); //ustawienie centrum i specjalnych punktow
}

Circus::Circus(std::string const &sample, std::string const &final, Vector3D const &sca)
{
    *this = Circus();
    this->set_sample_name(sample);
    this->set_final_name(final);
    this->set_scale(sca);
    *this = this->scale_pri();
    this->centre = special_points(this->cuts);
}

Vector3D Circus::special_points(Vector3D (&vecs)[2]) const
{
    Vector3D cen = this->centre_point();
    Vector3D side = tops[1][0] - tops[0][0];
    side = side * 0.5;
    vecs[0] = cen - side;
    vecs[1] = cen + side*2;
    return cen;
}

Circus &Circus::operator=(const Prism &a)
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

void Circus::print_name() const
{
    std::cout<<"Cyrk \n";
}