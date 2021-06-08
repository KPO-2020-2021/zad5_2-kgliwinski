#pragma once
#include "cuboid.hpp"

/*!
 * \file  triangluar.hpp
 *  \brief Plik zawiera definicję klasy reprezentujacej graniastoslup z 
 *          trojkatem prostokatnym w podstawie
 */

/*!
 *  \class Triangluar
 *  \brief Opisuje graniastoslup o podstawie trojkatnej w przestrzeni trojwymiarowej
 *          Jest klasa dziedziczaca z klasy Cuboid, w praktyce jest jego deformacja
 */
class Triangular : public Cuboid
{
public:
   /*!
 *  \brief Konstruktor bezparametryczny klasy Triangular.
 *          Powstaly graniastoslup ma jeden prostokat "tworzacy":
 *          p1 = [0][0] = (0,0,0), [0][1] =  (1,0,0), [0][2] = (1,1,0), [0][3] = (0,1,0)      
 *         Dwie sciany boczne sa trojkatami prostokatnymi (w definicji graniastoslupa trojkatnego
 *             bylyby to jego podstawy)
 *     \post Zwraca szesc wiercholkow                                   
 */
   Triangular();

   /*!
 *  \brief Konstruktor parametryczny klasy Triangular.
 *          Powstaje ostroslup jak z konstruktora parametrycznego, dodaja sie jednak
 *          pola klasy Block oraz skaluje figure
 *     \param[in] sample - docelowo sample_name
 *     \param[in] final - docelowo final_name
 *     \param[in] sca - docelowo scale
 *     \post Zwraca szesc wiercholkow, oraz przeskalowany przez zadana skale graniastoslup                                   
 */
   Triangular(std::string const &sample, std::string const &final, Vector3D const &sca);

   /*!
 *  \brief Metoda zwracajaca punkty specjalne Triangular : cuts (czyli
 *         te ktore sa przecieciami przekatnych dwoch przeciwleglych
 *         scian ostroslupa) oraz punkt centre                                        
 *      \param[in] vecs - tablica wektorow do ktorych program zwroci wartosci                                                              
 *     \post - metoda ustawia wartosci w polach tablicy
 *     \return - metoda zwraca punkt centre                         
 */
   Vector3D special_points(Vector3D (&vecs)[2]) const override;

   /*!
 *  \brief Przeciazenie operatora przypisania, umozliwia stosowanie metod
 *          typu Cuboid na obiekcie typu Triangular       
 *  \param[in] a - przypisywany graniastoslup                 
 *   \post Przypisuje figure                                                                                          
 */
   Triangular &operator=(const Cuboid &a);

   /*!
 *  \brief Zwraca nazwe obiektu                                                    
 */
   void print_name() const override;
};