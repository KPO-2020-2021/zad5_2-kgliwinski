#pragma once
#include <iostream>

/*!
 * \file  count.hpp
 *  
 *  \brief Plik zawiera definicję klasy reprezentujacej counter,
 *          pozwalajacy na liczenie instancji stworzonych klas.
 *          Uzyta technika CRTP - https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern
 */

/*! \class Count
 *  \brief Pozwala na liczenie instancji stworzonych obiektow
 */
template <typename T>
class Count
{
protected:
/*!
 * \brief Zlicza wszystkie stworzone obiekty danej klasy
 */
    static inline int objects_created = 0;
/*!
 * \brief Zlicza wszystkie zywe (aktywne) obiekty danej klasy
 */
    static inline int objects_alive = 0;

    public:
/*!
 * \brief Przy stworzeniu klasy zlicza objects_created i objects_alive
 */
    Count();

/*!
 * \brief Przy stworzeniu const klasy zlicza objects_created i objects_alive
 */
    Count(const Count&);
    
/*!
 * \brief Przy destrukcji klasy zmniejsza objects_alive
 */
    ~Count();
    

/*!
 * \brief Zwraca odpowiednie wartosci
 *      \param[in] created - tu zostaje przypisana objects_created
 *      \param[in] alive - tu zostaje przypisana objects_alive
 *  \post przypisuje parametrom z wejscia odpowiednie wartosci
 */
    void get_count(int &created, int &alive) const;

/*!
 * \brief Wypisuje odpowiednie wartosci klasy na standardowym wyjsciu
 */
    void print_count() const;

/*!
 * \brief Wyzerowuje pola klasy. Przeznaczona do testow.
 */
    void zero_count();
};

#include"../src/count.tpp"