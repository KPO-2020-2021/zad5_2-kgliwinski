#include"../include/tent.hpp"

Tent::Tent()
{
    int i;
    double iter1[6][3] = {{1, 0, -0.5}, {0.5, sqrt(3) * 0.5, -0.5}, {-0.5, sqrt(3) * 0.5, -0.5}, {-1, 0, -0.5}, {-0.5, -sqrt(3) * 0.5, -0.5}, {0.5, -sqrt(3) * 0.5, -0.5}};
    double iter2[3] = {0,0,0.5};
    for (i = 0; i < 6; ++i)
    {
        tops[0][i] = Vector3D(iter1[i]);
        tops[1][i] = Vector3D(iter2);
    }
    this->centre = this->special_points(cuts);
}

Tent::Tent(std::string const &sample, std::string const &final, Vector3D const &sca)
{
    *this = Tent();
    this->set_sample_name(sample);
    this->set_final_name(final);
    this->set_scale(sca);
    *this = this->scale_pri();
    this->centre = special_points(this->cuts);
}

double Tent::get_height() const
{
    Vector3D ver = cuts[1] - cuts[0];
    double res = ver.get_len();
    return res;
}

Vector3D Tent::centre_point() const
{
    Vector3D cen;
    Vector3D tmp = cuts[1] - cuts[0];
    cen = cuts[0] + tmp*0.5;
    return cen;
}


Vector3D Tent::special_points(Vector3D (&vecs)[2]) const
{
    Vector3D diag = tops[0][3] - tops[0][0];
    vecs[0] = tops[0][0] + diag*0.5;
    vecs[1] = tops[1][0];
    return centre_point();
}

Tent& Tent::operator=(const Prism &a)
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

void Tent::print_name() const
{
    std::cout<<"Namiot \n";
}