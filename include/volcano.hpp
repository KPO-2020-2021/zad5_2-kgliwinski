#pragma once
#include "prism.hpp"

/*!
 * \file  volcano.hpp
 *  \brief Plik zawiera definicję klasy reprezentujacej wulkan, jest deformacja obiektu Prism.

 */

/*!
 *  \class volcano
 *  \brief Opisuje graniastoslup szesciokatny o podwyzszonym srodku gornej podstawy.
 *          Jest klasa dziedziczaca z klasy Prism, w praktyce jest jego deformacja. \n
 *          rozni sie tym, ze zarowno gorna jak i dolna podstawa maja bok bedacy szesciakatem foremnym,
 *          z ta roznica, ze gorna podstawa ma bok trzykrotnie krotszy. Ponadto, cuts[1] oraz centre staja sie
 *          punktem wspolnym i leza w polowie wysokosci figury na jej srodku geometrycznym.
 */
class Volcano : public Prism
{
public:
   /*!
 *  \brief Konstruktor bezparametryczny klasy Volcano.
 *          Dolna podstawa jest identyczna jak w bezparametrycznym Prism,
 *          gorna jest zeskalowana o 0.5. cuts[] i centre jak w opisie.
 *     \post Zwraca 13 wierzcholkow                                   
 */
   Volcano();

   /*!
 *  \brief Konstruktor parametryczny klasy Volcano.
 *          Powstaje ostroslup jak z konstruktora parametrycznego, dodaja sie jednak
 *          pola klasy Block oraz skaluje figure
 *     \param[in] sample - docelowo sample_name
 *     \param[in] final - docelowo final_name
 *     \param[in] sca - docelowo scale
 *     \post Zwraca szesc wiercholkow, oraz przeskalowany przez zadana skale graniastoslup                                   
 */
   Volcano(std::string const &sample, std::string const &final, Vector3D const &sca);

   /*!
 *  \brief Metoda zwracajaca wysokosc Volcano
 *      \param[out] res - wysokosc                          
 */
   double get_height() const override;

   /*!
 *  \brief Metoda zwracajaca punkt centralny Volcano                                                                                
 *     \return point - Vector3D wskazujacy ze srodka ukladu wspolrzednych
 *                     na punkt centralny figury                              
 */
   Vector3D centre_point() const override;

   /*!
 *  \brief Metoda zwracajaca punkty specjalne Volcano : 
 *        - cuts[0] jest przecieciem przekatnych dolnej podstawy graniastoslupa \n
 *        - cuts[1] i centre leza w polowie wysokosci figury
 *      \param[in] vecs - tablica wektorow do ktorych program zwroci wartosci                                                    
 *     \post - metoda ustawia wartosci w polach tablicy
 *     \return - metoda zwraca punkt centre                         
 */
   Vector3D special_points(Vector3D (&vecs)[2]) const override;

   /*!
 *  \brief Przeciazenie operatora przypisania, umozliwia stosowanie metod
 *          typu Prism na obiekcie typu Volcano      
 *  \param[in] a - przypisywany graniastoslup                 
 *   \post Przypisuje figure                                                                                          
 */
   Volcano &operator=(const Prism &a);

   /*!
 *  \brief Zwraca nazwe obiektu                                                    
 */
   void print_name() const override;
};