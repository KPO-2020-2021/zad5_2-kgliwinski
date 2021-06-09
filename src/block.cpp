#include "../include/block.hpp"

Block::Block()
{
    sample_name = "";
    final_name = "";
    double tab[3] = {1, 1, 1};
    Vector3D vec(tab);
    scale = vec;
}

Block::Block(const std::string &s_name, const std::string &f_name, const Vector3D &vec)
{
    sample_name = s_name;
    final_name = f_name;
    scale = vec;
}

Block::Block(const std::string &s_name, const std::string &f_name)
{
    sample_name = s_name;
    final_name = f_name;
    double tab[3] = {1, 1, 1};
    Vector3D vec(tab);
    scale = vec;
}

void Block::set_sample_name(const std::string &name)
{
    sample_name = name;
}

void Block::set_final_name(const std::string &name)
{
    final_name = name;
}

void Block::set_scale(const Vector3D &vec)
{
    scale = vec;
}

void Block::set_scale(double (&tab)[3])
{
    Vector3D vec(tab);
    scale = vec;
}

bool Block::check_block() const
{
    int i;
    if (sample_name == "" || final_name == "")
        return 0;
    for (i = 0; i < 3; ++i)
    {
        if (scale[i] <= 0)
            return 0;
    }
    return 1;
}

std::string Block::get_sample_name() const
{
    return sample_name;
}

std::string Block::get_final_name() const
{
    return final_name;
}

Vector3D Block::get_scale() const
{
    return scale;
}

void Block::print_name() const
{
    std::cout << "Niezdefiniowany obiekt\n";
}

void Block::print_pos() const
{
    std::cout<<"Nieznana pozycja ";
}

Vector3D Block::get_pos() const
{
    double tab[3] = {0,0,0};
    return Vector3D(tab);
}

void Block::switch_pos(const double &x, const double &y)
{
    std::cout<<"Brak metody"<<x<<" "<<y<<"\n";
}