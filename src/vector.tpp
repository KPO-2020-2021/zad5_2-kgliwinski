#pragma once
#include "../include/vector.hpp"

template <typename type, unsigned int SIZE>
Vector<type, SIZE>::Vector()
{
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        size[i] = 0.0;
    }
}

template <typename type, unsigned int SIZE>
Vector<type, SIZE>::Vector(type tmp[SIZE])
{
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        size[i] = tmp[i];
    }
}
template <typename type, unsigned int SIZE>
void Vector<type, SIZE>::get_vec(type (&tab)[SIZE]) const
{
    unsigned int i;
    for (i = 0; i < SIZE; ++i)
    {
        tab[i] = size[i];
    }
}

template <typename type, unsigned int SIZE>
Vector<type, SIZE> Vector<type, SIZE>::operator+(const Vector<type, SIZE> &v) const
{
    Vector result;
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] + v[i];
    }
    return result;
}

template <typename type, unsigned int SIZE>
Vector<type, SIZE> Vector<type, SIZE>::operator-(const Vector<type, SIZE> &v) const
{
    Vector result;
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] - v[i];
    }
    return result;
}

template <typename type, unsigned int SIZE>
Vector<type, SIZE> Vector<type, SIZE>::operator*(const type &tmp) const
{
    Vector result;
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] * tmp;
    }
    return result;
}

template <typename type, unsigned int SIZE>
Vector<type, SIZE> Vector<type, SIZE>::operator/(const type &tmp) const
{
    Vector result;
    if (tmp == 0)
    {
        std::cerr << "ERROR: Nie mozna dzielic przez 0" << std::endl;
        return *this;
    }
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] / tmp;
    }

    return result;
}

template <typename type, unsigned int SIZE>
bool Vector<type, SIZE>::operator==(const Vector<type, SIZE> &v) const
{
    unsigned int i;
    for (i = 0; i < SIZE; i++)
    {
        if (!((abs(size[i] - v.size[i]) <= 0.000001)))
            return 0;
    }
    return 1;
}

template <typename type, unsigned int SIZE>
const type &Vector<type, SIZE>::operator[](unsigned int index) const
{
    if (index < 0 || index >= SIZE)
    {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return size[index];
}

template <typename type, unsigned int SIZE>
type &Vector<type, SIZE>::operator[](unsigned int index)
{
    return const_cast<type &>(const_cast<const Vector *>(this)->operator[](index));
}

template <typename type, unsigned int SIZE>
Vector<type, SIZE> Vector<type, SIZE>::scale_vec(const Vector &vec) const
{
    unsigned int i;
    Vector res=*this;
    for (i=0;i<SIZE;++i)
    {
        res[i] *= vec[i];
    }
    return res;
}

template <typename type, unsigned int SIZE>
std::ostream &operator<<(std::ostream &out, Vector<type, SIZE> const &tmp)
{
    out.precision(10);
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        out << "[ ";
        out << std::setw(10) << std::fixed << std::setprecision(10) << tmp[i];
        out << " ]\n";
    }
    return out;
}

template <typename type, unsigned int SIZE>
std::istream &operator>>(std::istream &in, Vector<type, SIZE> &tmp)
{
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        in >> tmp[i];
    }
    return in;
}

template <typename type, unsigned int SIZE>
type Vector<type, SIZE>::modulus2() const
{
    unsigned int i;
    type result = 0;

    for (i = 0; i < SIZE; i++)
    {
        result += pow(size[i], 2);
    }
    return result;
}

template <typename type, unsigned int SIZE>
type Vector<type, SIZE>::get_len() const
{
    type len, mod2;
    Vector tmp;
    tmp = *this;
    mod2 = tmp.modulus2();
    len = pow(mod2, 1.0 / 2);

    return len;
}
template <typename type, unsigned int SIZE>
type Vector<type, SIZE>::scalar_prod(Vector<type, SIZE> const &vec) const
{
    type res;
    unsigned int i;
    res = 0;
    for (i = 0; i < SIZE; ++i)
    {
        res += size[i] * vec.size[i];
    }
    return res;
}
