#include "../include/count.hpp"

template <typename T>
Count<T>::Count()
{
    objects_created++;
    objects_alive++;
}

template <typename T>
Count<T>::Count(const Count &)
{
    objects_created++;
    objects_alive++;
}

template <typename T>
Count<T>::~Count()
{
    objects_alive--;
}
template <typename T>
void Count<T>::get_count(int &created, int &alive) const
{
    created = objects_created;
    alive = objects_alive;
}
template <typename T>
void Count<T>::print_count() const
{
    std::cout << "Aktualna ilosc obiektow Vector3D: " << objects_alive << std::endl;
    std::cout << "  Laczna ilosc obiektow Vector3D: " << objects_created << std::endl;
}
template <typename T>
void Count<T>::zero_count()
{
    objects_alive = 0;
    objects_created = 0;
}