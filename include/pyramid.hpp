#pragma once
#include "cuboid.hpp"
/*!
 * \file  pyramid.hpp
 *  \brief Plik zawiera definicję klasy reprezentujacej graniastoslup o podstawie o 6 wierzcholkach
 *  w przestrzeni trojwymiarowej
 */

/*!
 *  \class Pyramid
 *  \brief Opisuje ostroslup o podstawie prostokatnej w przestrzeni trojmwymiarowej
 *          Jest klasa dziedziczaca z klasy Cuboid
 */
class Pyramid : public Cuboid
{
public:
    /*!
 *  \brief Konstruktor bezparametryczny klasy Pyramid.
 *          Powstaly ostroslupa ma jeden prostokat "tworzacy":
 *          p1 = [0][0] = (0,0,0), [0][1] =  (1,0,0), [0][2] = (1,1,0), [0][3] = (0,1,0)      
 *         Oraz jeden gorny wierzcholek (0.5,0.5,1)  
 *     \post Zwraca piec wiercholkow                                   
 */
    Pyramid();

    /*!
 *  \brief Konstruktor parametryczny klasy Pyramid.
 *          Powstaly ostroslupa ma jeden prostokat "tworzacy":
 *          p1 = [0][0] = (0,0,0), [0][1] =  (1,0,0), [0][2] = (1,1,0), [0][3] = (0,1,0)      
 *         Oraz jeden gorny wierzcholek.
 *     \param[in] sample - docelowo sample_name
 *     \param[in] final - docelowo final_name
 *     \param[in] sca - docelowo scale
 *     \post Zwraca piec wiercholkow, oraz przeskalowany przez zadana skale stozek                                   
 */
    Pyramid(std::string const &sample, std::string const &final, Vector3D const &sca);

    /*!
 *  \brief Metoda zwracajaca punkt centralny (czyli taki, ktorego odleglosci
 *         do kazdego wierzcholka sa rowne) Pyramid. Zgodnie z geometria
 *         ostroslupa, lezy on na przecieciu jego przekatnych lub w polowie
 *         jednej z przekatnych, z czego korzysta ta metoda                                                                                                        
 *     \return point - Vector3D wskazujacy ze srodka ukladu wspolrzednych
 *                     na punkt centralny ostroslupau                               
 */
    Vector3D centre_point() const;

    /*!                           
 *    \brief Metoda zwraca wysokosc ostroslupa                                                           
 *     \return Wysokosc ostroslupa                               
 */
    double get_height() const;

    /*!
 *  \brief Metoda zwracajaca punkty specjalne ostroslupau : cuts (czyli
 *         te ktore sa przecieciami przekatnych dwoch przeciwleglych
 *         scian ostroslupa) oraz punkt centre                                        
 *      \param[in] vecs - tablica wektorow do ktorych program zwroci wartosci                                                              
 *     \post - metoda ustawia wartosci w polach tablicy
 *     \return - metoda zwraca punkt centre                         
 */
    Vector3D special_points(Vector3D (&vecs)[2]) const;


    /*!
 *  \brief Metoda skalujaca o wektor scale bedacy
 *         czlonkiem klasy block                         
 *   \return Zwraca zeskalowany ostroslup                                                                                           
 */
    Pyramid scale_pyr() const;

    /*!
 *  \brief Przeciazenie operatora przypisania, umozliwia stosowanie metod
 *          typu Cuboid na obiekcie typu Pyramid       
 *  \param[in] a - przypisywany ostroslupa                 
 *   \post Przypisuje figure                                                                                          
 */
    Pyramid& operator= (const Cuboid &a);

};