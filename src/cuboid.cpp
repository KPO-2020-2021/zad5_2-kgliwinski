#include "cuboid.hpp"

Cuboid::Cuboid()
{
    int i;
    double iter[4][3] = {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 1;
        tops[1][i] = Vector3D(iter[i]);
    }
    this->centre = special_points(this->cuts); //ustawia centre point i cuts
}

Cuboid::Cuboid(const std::string &s_name, const std::string &f_name, const Vector3D &vec)
    : Block(s_name, f_name, vec)
{
    int i;
    double iter[4][3] = {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 1;
        tops[1][i] = Vector3D(iter[i]);
    }
    this->centre = special_points(this->cuts); //ustawia centre point i cuts
    *this = this->scale_cub();
}

Cuboid::Cuboid(Vector3D const (&tab)[2][4])
{
    int i;
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = tab[0][i];
        tops[1][i] = tab[1][i];
    }
    this->centre = special_points(this->cuts); //ustawia centre point i cuts
}

Cuboid::Cuboid(Vector3D const (&tab)[2][4], const std::string &s_name, const std::string &f_name, const Vector3D &vec)
    : Block(s_name, f_name, vec)
{
    int i;
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = tab[0][i];
        tops[1][i] = tab[1][i];
    }
    this->centre = special_points(this->cuts); //ustawia centre point i cuts
}

Cuboid::Cuboid(double (&tovec)[2][4][3])
{
    int i, j;
    Vector3D tab[2][4];
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            tab[0][i] = Vector3D(tovec[0][i]);
            tab[1][i] = Vector3D(tovec[1][i]);
        }
    }
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = tab[0][i];
        tops[1][i] = tab[1][i];
    }
    this->centre = special_points(this->cuts); //ustawia centre point i cuts
}

Cuboid::Cuboid(double (&tovec)[2][4][3], const std::string &s_name, const std::string &f_name, const Vector3D &vec)
    : Block(s_name, f_name, vec)
{
    int i, j;
    Vector3D tab[2][4];
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            tab[0][i] = Vector3D(tovec[0][i]);
            tab[1][i] = Vector3D(tovec[1][i]);
        }
    }
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = tab[0][i];
        tops[1][i] = tab[1][i];
    }
    this->centre = special_points(this->cuts); //ustawia centre point i cuts
}

bool Cuboid::check_cub() const
{
    if (!(check_vec_opp() && check_vec_perp() && check_vec_len()))
        return 0;
    return 1;
}

void Cuboid::get_vec_opp(Vector3D (&vecs)[3][2]) const
{
    vecs[0][0] = tops[0][1] - tops[0][0];
    vecs[0][1] = tops[1][2] - tops[1][3];

    vecs[1][0] = tops[1][1] - tops[0][1];
    vecs[1][1] = tops[1][3] - tops[0][3];

    vecs[2][0] = tops[0][3] - tops[0][0];
    vecs[2][1] = tops[1][2] - tops[1][1];
}

bool Cuboid::check_vec_opp() const
{
    int i;
    Vector3D opp[3][2];
    this->get_vec_opp(opp);
    for (i = 0; i < 3; ++i)
    {
        if (!(opp[i][0] == opp[i][1]))
            return 0;
    }
    return 1;
}

bool Cuboid::check_vec_len() const
{
    int i, j;
    Vector3D opp[3][2];
    this->get_vec_opp(opp);
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 2; ++j)
        {
            if (opp[i][j].get_len() == 0)
                return 0;
        }
    }
    return 1;
}

void Cuboid::get_vec_len(double (&tab)[3][2]) const
{
    int i;
    Vector3D opp[3][2];
    this->get_vec_opp(opp);
    for (i = 0; i < 3; ++i)
    {
        tab[i][0] = opp[i][0].get_len();
        tab[i][1] = opp[i][1].get_len();
    }
    if (tab[0] < tab[1])
    {
        double tmp[2] = {tab[0][0], tab[0][1]};
        tab[0][0] = tab[1][0];
        tab[0][1] = tab[1][1];
        tab[1][0] = tmp[1];
        tab[1][1] = tmp[0];
    }
}

void Cuboid::get_vec_perp(Vector3D (&vecs)[2][3]) const
{
    vecs[0][0] = tops[0][2] - tops[0][1];
    vecs[0][1] = tops[1][1] - tops[0][1];
    vecs[0][2] = tops[0][0] - tops[0][1];

    vecs[1][0] = tops[1][0] - tops[1][3];
    vecs[1][1] = tops[0][3] - tops[1][3];
    vecs[1][2] = tops[1][2] - tops[1][3];
}

bool Cuboid::check_vec_perp() const
{
    int i;
    Vector3D vecs[2][3];
    this->get_vec_perp(vecs);
    for (i = 0; i < 2; ++i)
    {
        if (!(vecs[i][0].scalar_prod(vecs[i][1]) <= 0.0000000001))
            return 0;
        if (!(vecs[i][0].scalar_prod(vecs[i][2]) <= 0.0000000001))
            return 0;
        if (!(vecs[i][1].scalar_prod(vecs[i][2]) <= 0.0000000001))
            return 0;
    }
    return 1;
}

std::ostream &operator<<(std::ostream &out, Cuboid const &Cub)
{
    out.precision(10);
    Vector3D vecs[2][4];
    Cub.get_cub(vecs);
    out << "Wierzcholek A: " << std::endl
        << vecs[0][0] << std::endl;
    out << "Wierzcholek B: " << std::endl
        << vecs[0][1] << std::endl;
    out << "Wierzcholek C: " << std::endl
        << vecs[0][2] << std::endl;
    out << "Wierzcholek D: " << std::endl
        << vecs[0][3] << std::endl;
    out << "Wierzcholek E: " << std::endl
        << vecs[1][0] << std::endl;
    out << "Wierzcholek F: " << std::endl
        << vecs[1][1] << std::endl;
    out << "Wierzcholek G: " << std::endl
        << vecs[1][2] << std::endl;
    out << "Wierzcholek H: " << std::endl
        << vecs[1][3] << std::endl;

    return out;
}

void Cuboid::get_cub(Vector3D (&tab)[2][4]) const
{
    int i;
    for (i = 0; i < 4; ++i)
    {
        tab[0][i] = tops[0][i];
        tab[1][i] = tops[1][i];
    }
}

void Cuboid::get_cub(double (&tab)[2][4][3]) const
{
    int i, j;
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            tab[0][i][j] = tops[0][i][j];
            tab[1][i][j] = tops[1][i][j];
        }
    }
}

double Cuboid::get_height() const
{
    double res;
    Vector3D ver = tops[1][3] - tops[0][3];
    res = ver.get_len();
    return res;
}

Vector3D Cuboid::get_basis_centre() const
{
    Vector3D diag;
    diag = tops[0][2] - tops[0][0];
    Vector3D point;
    point = tops[0][0] + diag * 0.5;
    return point;
}

bool Cuboid::operator==(const Cuboid &cub) const
{
    int i, j;
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            if (!(tops[i][j] == cub.tops[i][j]))
                return 0;
        }
    }
    return 1;
}

Cuboid Cuboid::translation(Vector3D const &tran) const
{
    int i, j;
    Cuboid translated = *this;

    for (i = 0; i < 2; ++i)
    {
        translated.cuts[i] = cuts[i] + tran;
        for (j = 0; j < 4; ++j)
        {
            translated.tops[i][j] = tops[i][j] + tran;
            translated.centre = centre + tran;
        }
    }
    return translated;
}

Cuboid Cuboid::translation_to_O() const
{
    Cuboid translated = *this;
    int i, j;
    Vector3D tran = centre * (-1);
    for (i = 0; i < 2; ++i)
    {
        translated.cuts[i] = cuts[i] + tran;
        for (j = 0; j < 4; ++j)
        {
            translated.tops[i][j] = tops[i][j] + tran;
        }
    }
    translated.centre = centre + tran;
    return translated;
}

Cuboid Cuboid::rotation(Matrix3D const &mat) const
{
    int i, j;
    Cuboid rotated = *this;
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            rotated.tops[i][j] = mat.apply_matrix_to_rotation(tops[i][j]);
            rotated.cuts[i] = mat.apply_matrix_to_rotation(cuts[i]);
            rotated.centre = mat.apply_matrix_to_rotation(centre);
        }
    }
    return rotated;
}

Cuboid Cuboid::rotation_around_cen(Matrix3D const &mat) const
{
    int i, j;
    Cuboid rotated = *this;
    rotated = this->translation_to_O();
    for (i = 0; i < 2; ++i)
    {
        rotated.cuts[i] = mat.apply_matrix_to_rotation(rotated.cuts[i]);
        for (j = 0; j < 4; ++j)
        {
            rotated.tops[i][j] = mat.apply_matrix_to_rotation(rotated.tops[i][j]);
            rotated.centre = mat.apply_matrix_to_rotation(rotated.centre);
        }
    }
    rotated = rotated.translation(this->centre);
    return rotated;
}

Vector3D Cuboid::centre_point() const
{
    Vector3D diag;
    diag = tops[1][2] - tops[0][0];
    Vector3D point;
    point = tops[0][0] + diag * 0.5;
    return point;
}

Vector3D Cuboid::special_points(Vector3D (&vecs)[2]) const
{
    Vector3D cen = centre_point();
    Vector3D side = tops[0][2] - tops[0][1];
    side = side * 0.5;
    vecs[0] = cen - side;
    vecs[1] = cen + side;
    return cen;
}

void Cuboid::print_cuboid(std::ostream &out) const
{
    int i, j, k;
    out.precision(10);
    double vecs[2][4][3];
    this->get_cub(vecs);
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            for (k = 0; k < 3; ++k)
            {
                out << std::setw(10) << std::fixed << std::setprecision(10) << vecs[i][j][k] << " ";
            }
            if (j == 1 || j == 3)
                out << std::endl;
            out << std::endl;
        }
    }
    for (i = 0; i < 1; ++i)
    {
        for (j = 0; j < 2; ++j)
        {
            for (k = 0; k < 3; ++k)
            {
                out << std::setw(10) << std::fixed << std::setprecision(10) << vecs[i][j][k] << " ";
            }
            out << std::endl;
        }
    }
}

void Cuboid::print_cuboid_weird(std::ostream &out) const
{
    double tab[2][4][3];
    int i, j, k;
    tops[0][0].get_vec(tab[0][0]); //W1
    tops[0][1].get_vec(tab[0][1]); //W2
    tops[0][3].get_vec(tab[0][2]); //W3
    tops[0][2].get_vec(tab[0][3]); //W4
    tops[1][3].get_vec(tab[1][0]); //W5
    tops[1][2].get_vec(tab[1][1]); //W6
    tops[1][0].get_vec(tab[1][2]); //W7
    tops[1][1].get_vec(tab[1][3]); //W8

    out.precision(10);
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            for (k = 0; k < 3; ++k)
            {
                out << std::setw(10) << std::fixed << std::setprecision(10) << tab[i][j][k] << " ";
            }
            if (j == 1 || j == 3)
                out << std::endl;
            out << std::endl;
        }
    }
    for (i = 0; i < 1; ++i)
    {
        for (j = 0; j < 2; ++j)
        {
            for (k = 0; k < 3; ++k)
            {
                out << std::setw(10) << std::fixed << std::setprecision(10) << tab[i][j][k] << " ";
            }
            out << std::endl;
        }
    }
}

void Cuboid::print_cuboid_3D(std::ostream &out) const
{

    double tab[2][4][3];
    double cen[3];
    double spec[2][3];
    int i, j, k;
    tops[0][1].get_vec(tab[0][0]); //W1
    tops[0][2].get_vec(tab[0][1]); //W2
    tops[0][0].get_vec(tab[0][2]); //W3
    tops[0][3].get_vec(tab[0][3]); //W4
    tops[1][0].get_vec(tab[1][0]); //W5
    tops[1][3].get_vec(tab[1][1]); //W6
    tops[1][1].get_vec(tab[1][2]); //W7
    tops[1][2].get_vec(tab[1][3]); //W8
    centre.get_vec(cen);
    cuts[0].get_vec(spec[0]);
    cuts[1].get_vec(spec[1]);
    out.precision(10);
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            if (j == 0 || j == 2)
            {
                out << std::setw(10) << std::fixed << std::setprecision(10) << spec[0][0] << " " << spec[0][1] << " " << spec[0][2] << " \n";
            }
            for (k = 0; k < 3; ++k)
            {
                out << std::setw(10) << std::fixed << std::setprecision(10) << tab[i][j][k] << " ";
            }
            out << std::endl;
            if (j == 1 || j == 3)
            {
                out << std::setw(10) << std::fixed << std::setprecision(10) << spec[1][0] << " " << spec[1][1] << " " << spec[1][2] << " \n";
            }
            if (j == 1 || j == 3)
                out << std::endl;
        }
    }
    for (i = 0; i < 1; ++i)
    {
        for (j = 0; j < 2; ++j)
        {
            if (j == 0 || j == 2)
            {
                out << std::setw(10) << std::fixed << std::setprecision(10) << spec[0][0] << " " << spec[0][1] << " " << spec[0][2] << " \n";
            }
            for (k = 0; k < 3; ++k)
            {
                out << std::setw(10) << std::fixed << std::setprecision(10) << tab[i][j][k] << " ";
            }
            out << std::endl;
            if (j == 1 || j == 3)
            {
                out << std::setw(10) << std::fixed << std::setprecision(10) << spec[1][0] << " " << spec[1][1] << " " << spec[1][2] << " \n";
            }
            if (j == 1 || j == 3)
                out << std::endl;
        }
    }
}

Cuboid Cuboid::Cuboid_From_Sample() const
{
    Vector3D tab[2][4];
    std::ifstream file;
    file.open(sample_name);
    int i, j;
    Vector3D read[2][4];
    Vector3D bin;
    j = 0;
    for (i = 0; i < 2; ++i)
    {
        if (i == 1)
            j = 1;
        file >> bin;
        file >> read[j][0];
        file >> read[j][1];
        file >> bin;
        file >> bin;
        file >> read[j][2];
        file >> read[j][3];
        file >> bin;
    }
    tab[0][1] = read[0][0];
    tab[0][2] = read[0][1];
    tab[0][0] = read[0][2];
    tab[0][3] = read[0][3];
    tab[1][0] = read[1][0];
    tab[1][3] = read[1][1];
    tab[1][1] = read[1][2];
    tab[1][2] = read[1][3];
    Cuboid pri(tab);
    pri.set_sample_name(this->get_sample_name());
    pri.set_final_name(this->get_final_name());
    return pri;
}

bool Cuboid::Cuboid_To_File(const std::string &filename) const
{
    std::ofstream filestrm;

    filestrm.open(filename);
    if (!filestrm.is_open())
    {
        std::cerr << ":(  Operacja otwarcia do zapisu \"" << filename << "\"" << std::endl
                  << ":(  nie powiodla sie." << std::endl;
        return false;
    }
    std::ostringstream out;
    print_cuboid_3D(filestrm);

    filestrm.close();
    return !filestrm.fail();
}

Cuboid Cuboid::scale_cub() const
{
    int i, j;
    Cuboid res;
    res = this->translation_to_O();
    for (i = 0; i < 2; ++i)
    {
        res.cuts[i] = res.cuts[i].scale_vec(scale);
        for (j = 0; j < 4; ++j)
        {
            res.tops[i][j] = res.tops[i][j].scale_vec(scale);
        }
    }
    res.centre = res.centre.scale_vec(scale);
    return res;
}

Cuboid Cuboid::scale_cub(Vector3D const &scal) const
{
    int i, j;
    Cuboid res;
    res = this->translation_to_O();
    for (i = 0; i < 2; ++i)
    {
        res.cuts[i] = res.cuts[i].scale_vec(scal);
        for (j = 0; j < 4; ++j)
        {
            res.tops[i][j] = res.tops[i][j].scale_vec(scal);
        }
    }
    res.centre = res.centre.scale_vec(scal);
    return res;
}

void Cuboid::print_name() const
{
    std::cout << "Plaskowyz \n";
}

void Cuboid::print_pos() const
{
    Vector3D cen = get_basis_centre();
    std::cout << "(" << std::setw(2) << std::fixed << std::setprecision(2) << cen[0];
    std::cout << ", " << std::setw(2) << std::fixed << std::setprecision(2) << cen[1] << ") ";
}

Vector3D Cuboid::get_pos() const
{
    return get_basis_centre();
}

void Cuboid::switch_pos(const double &x, const double &y)
{
    Vector3D oldpos = get_pos();
    double tab[3] = {x, y, 0};
    Vector3D newpos(tab);
    Vector3D tran = newpos - oldpos;
    *this = this->translation(tran);
    Cuboid_To_File(final_name);
}
