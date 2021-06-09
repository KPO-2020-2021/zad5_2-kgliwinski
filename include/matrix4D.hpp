#pragma once
#include "matrix.hpp"

/*!
 *  \file matrix4D.hpp
 *     \brief Zawiera deklaracje klasy Matrix4D
 */

/*!
 *  \class Matrix4D
 *     \brief Specyfikacja szablonu Matrix do 4D
 */

typedef Matrix<double, 4> Matrix4D;

/*!
 * Utowrzenie macierzy obrotu dla obrotu + translacji 3D - przypisanie jej do danej macierzy             
 * Argumenty:                                                                
 *      \param[in] alpha - kat obrotu wokol x
 *      \param[in] beta - kat obrotu wokol y
 *      \param[in] gamma - kat obrotu wokol z
 *      \param[in] tran - Vector3D z parametrami (odpowiednio) x,y,z translacji                                
 * Zwraca:                                                                   
 *      \param[out] rotation - macierz transformacji + translacji                                                     
 */
template <>
inline void Matrix<double, 4>::rotate_and_translate(const double & alpha, const double & beta, const double & gamma, const Vector3D &tran) ;


#include"../src/matrix4D.cpp"
