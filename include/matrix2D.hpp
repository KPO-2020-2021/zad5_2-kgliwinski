#pragma once

#include "matrix.hpp"

/*!
 *  \file matrix2D.hpp
 *     \brief Zawiera deklaracje klasy Matrix2D
 */

/*!
 *  \class Matrix2D
 *     \brief Specyfikacja szablonu Matrix do 2D
 */

typedef Matrix<double, 2> Matrix2D;

/*!
 * Utowrzenie macierzy obrotu dla obrotu w 2D - przypisanie jej do danej macierzy             
 * Argumenty:                                                                
 *      \param[in] theta_rad - kat obrotu w stopniach                                 
 * Zwraca:                                                                   
 *      \param[out] this - przypisana do podanej macierzy macierz transformacji                                                     
 */
template <>
inline void Matrix<double, 2>::rotation_matrix(const double &angle);

#include"../src/matrix2D.cpp"
