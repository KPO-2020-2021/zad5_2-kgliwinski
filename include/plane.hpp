#pragma once
#include "block.hpp"

/*!
 * \file  plane.hpp
 *  
 *  \brief Plik zawiera definicję klasy reprezentujacej plaska powierzchnie,
 *         obslugujacej zapis do plikow
 */

/*!
 *  \class Plane
 *  \brief Opisuje plaska powierzchnie w 3D reprezentujaca powierzchnie marsa,
 *          plasczyzna docelowo rysuje sie w gnuplocie w zakresach [0,range_x] x [0,range_y],
 *          stad klasa ma pola tylko range_x i range_y
 */
class Plane : public Block
{

private:
    /*!
 *  \brief Zmienna reprezentujaca zakres x rysowanej w gnuplocie plaszczyzny
 */
    double range_x;

    /*!
 *  \brief Zmienna reprezentujaca zakres y rysowanej w gnuplocie plaszczyzny
 */
    double range_y;

public:
    /*!
 *  \brief Konstruktor parametryczny klasy Plane. Przeznaczony do konstrukcji plaszczyzny
 *         razem z polami rodzica Block      
 *      \param[in] x - docelowo range_x
 *      \param[in] y - docelowo range_y                                                                                                 
 *      \param[in] s_name - docelowo sample_name z klasy Block
 *      \param[in] f_name - docelowo final_name z klasy Block                                                                                                         
 *     \post Zwraca zakresy x,y oraz pola klasy Block, (scale pozostaje [1,1,1])                                 
 */
    Plane(double const &x, double const &y, const std::string &s_name, const std::string &f_name);

    /*!
 *  \brief Metoda zwracajaca pola klasy Plane 
 *      \param[in] x - do tej zmiennej zwraca range_x
 *      \param[in] y - do tej zmiennej zwraca range_y                                                                                                                                                                                                        
 *     \post Zwraca zakresy x,y do zmiennych x i y                               
 */
    void get_plane(double &x, double &y) const;

    /*!
 *  \brief Metoda sprawdzajaca Plane 
 *     \pre Zakresy x,y musza wynosic co najmniej 10                                                                                                                                                                                                     
 *     \retval true - jesli poprawne
 *     \retval false - w przeciwnym wypadku                               
 */
    bool check_plane()const;
/*!
 * \brief Metoda tworzy plaszczyzne z podanych zakresow
 */
    bool make_plane() const;
};