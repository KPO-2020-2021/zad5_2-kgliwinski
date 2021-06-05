#pragma once
#include "prism.hpp"

/*!
 * \file  circus.hpp
 *  \brief Plik zawiera definicję klasy reprezentujacej Prism z podwyzszonym centrum,
 *          na ksztalt przypomina cyrk
 */

/*!
 *  \class Circus
 *  \brief Opisuje graniastoslup szesciokatny o podwyzszonym srodku gornej podstawy.
 *          Jest klasa dziedziczaca z klasy Prism, w praktyce jest jego deformacja. \n
 *          Dla uproszczenia wysokosc jest liczona tak samo jak w Prism mimo ze w rzeczywistosci
 *          obiekt bedzie wyzszy. W implementacji nie gra to roli.
 */
class Circus : public Prism
{
public:
    /*!
 *  \brief Konstruktor bezparametryczny klasy Circus.
 *          Dolna podstawa jest identyczna jak w bezparametrycznym Prism,
 *          cuts[1] jest deformowany i przesuwany na wysokosc 
 *     \post Zwraca szesc wiercholkow                                   
 */
    Circus();

    /*!
 *  \brief Konstruktor parametryczny klasy Circus.
 *          Powstaje ostroslup jak z konstruktora parametrycznego, dodaja sie jednak
 *          pola klasy Block oraz skaluje figure
 *     \param[in] sample - docelowo sample_name
 *     \param[in] final - docelowo final_name
 *     \param[in] sca - docelowo scale
 *     \post Zwraca szesc wiercholkow, oraz przeskalowany przez zadana skale graniastoslup                                   
 */
    Circus(std::string const &sample, std::string const &final, Vector3D const &sca);

    /*!
 *  \brief Metoda zwracajaca punkty specjalne graniastoslupa : 
 *        - cuts[0] jest przecieciem przekatnych dwoch przeciwleglych
 *          podstaw graniastoslupa \n
 *        - cuts[1] jest punktem centre przeniesionym o wysokosc graniastoslupa w gore \n
 *        - punkt centre \n
 *      \param[in] vecs - tablica wektorow do ktorych program zwroci wartosci                                                    
 *     \post - metoda ustawia wartosci w polach tablicy
 *     \return - metoda zwraca punkt centre                         
 */
    Vector3D special_points(Vector3D (&vecs)[2]) const override;

        /*!
 *  \brief Przeciazenie operatora przypisania, umozliwia stosowanie metod
 *          typu Prism na obiekcie typu Circus       
 *  \param[in] a - przypisywany graniastoslup                 
 *   \post Przypisuje figure                                                                                          
 */
    Circus &operator=(const Prism &a);
};