#include"../include/plane.hpp"

Plane::Plane(double const &x, double const &y, const std::string &s_name, const std::string &f_name) 
: Block(s_name, f_name)
{
    range_x = x;
    range_y = y;
}

void Plane::get_plane(double &x, double &y) const
{
    x = range_x;
    y = range_y;
}

bool Plane::check_plane() const
{
    if (!check_block())
        return 0;
    if (range_x<10 || range_y <10)
        return 0;
    return 1;
}

bool Plane::make_plane() const
{
    int i,j;
    std::ofstream filestrm;
    filestrm.open(sample_name);
    if (!filestrm.is_open())
    {
        std::cerr << ":(  Operacja otwarcia do zapisu \"" << sample_name << "\"" << std::endl
                  << ":(  nie powiodla sie." << std::endl;
        return false;
    }

    for (i = 0; i <= range_x; i+=10)
    {
        for(j=0;j<=range_y;j+=10)
        {
                filestrm << std::setw(10) << std::fixed << std::setprecision(10) << j << " " << i << " " << 0 << std::endl;
        }
        filestrm<<std::endl;
    }
    return 1;
}