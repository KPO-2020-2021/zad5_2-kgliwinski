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

void Block::set_scale( double(&tab)[3])
{
    Vector3D vec(tab);
    scale = vec;
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
