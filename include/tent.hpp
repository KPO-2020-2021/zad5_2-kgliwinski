#pragma once
#include "prism.hpp"

/*!
 * \file  tent.hpp
 *  \brief Plik zawiera definicję klasy reprezentujacej Prism bez gornej podstawy,
 *          =Ksztaltem przypomina namiot
 */

/*!
 *  \class Tent
 *  \brief Opisuje ostroslup szesciokatny prawidlowy (moze miec nieregularna podstawe)
 *          Jest klasa dziedziczaca z klasy Prism, w praktyce jest jego deformacja. \n
 */
class Tent : public Prism
{
public:
    /*!
 *  \brief Konstruktor bezparametryczny klasy Tent.
 *          Dolna podstawa jest identyczna jak w bezparametrycznym Prism,
 *          wierzcholki gornej podstawy sa skupione w jednym punkcie. 
 *     \post Zwraca 7 wiercholkow                                   
 */
    Tent();

    /*!
 *  \brief Konstruktor parametryczny klasy Tent.
 *          Powstaje ostroslup jak z konstruktora parametrycznego, dodaja sie jednak
 *          pola klasy Block oraz skaluje figure
 *     \param[in] sample - docelowo sample_name
 *     \param[in] final - docelowo final_name
 *     \param[in] sca - docelowo scale
 *     \post Zwraca szesc wiercholkow, oraz przeskalowany przez zadana skale graniastoslup                                   
 */
    Tent(std::string const &sample, std::string const &final, Vector3D const &sca);

    /*!
 *  \brief Metoda zwracajaca wysokosc Tent
 *      \param[out] res - wysokosc                          
 */
    double get_height() const override;

    /*!
 *  \brief Metoda zwracajaca punkt centralny Tent                                                                                
 *     \return point - Vector3D wskazujacy ze srodka ukladu wspolrzednych
 *                     na punkt centralny graniastoslupa                              
 */
    Vector3D centre_point() const override;

    /*!
 *  \brief Metoda zwracajaca punkty specjalne Tent : cuts (jedna jest punktem przeciecia przekatnych
 *          dolnej podstawy, druga wierzcholkiem figury) oraz punkt centre                                     
 *      \param[in] vecs - tablica wektorow do ktorych program zwroci wartosci                                                    
 *     \post - metoda ustawia wartosci w polach tablicy
 *     \return - metoda zwraca punkt centre                         
 */
    Vector3D special_points(Vector3D (&vecs)[2]) const override;

    /*!
 *  \brief Przeciazenie operatora przypisania, umozliwia stosowanie metod
 *          typu Prism na obiekcie typu Tent       
 *  \param[in] a - przypisywany graniastoslup                 
 *   \post Przypisuje figure                                                                                          
 */
    Tent &operator=(const Prism &a);
};