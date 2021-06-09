#pragma once

#include "matrix.hpp"
#include "vector3D.hpp"
/*!
 *  \file matrix3D.hpp
 *     \brief Zawiera deklaracje klasy Matrix3D
 */

/*!
 *  \class Matrix3D
 *     \brief Specyfikacja szablonu Matrix do 3D
 */

typedef Matrix<double, 3> Matrix3D;


/*!
 * Utowrzenie macierzy obrotu dla obrotu w 3D - przypisanie jej do danej macierzy             
 * Argumenty:                                                                
 *      \param[in] angle - kat obrotu w stopniach
 *      \param[in] axis - wybrana os obrotu (x,y lub z)                                
 * Zwraca:                                                                   
 *      \param[out] rotation - macierz transformacji                                                     
 */
template <>
inline Matrix<double,3> Matrix<double, 3>::rotation_matrix(const double & angle, const char &axis) const;



/*!
 * \brief Obrot wektora o zadane 3 katy wokol okreslonych osi (x,y,z) w 3D             
 * Argumenty:                                                                
 *      \param[in] to_rot - Vector3D ktory chcemy obrocic                               
 * Zwraca:                                                                   
 *      \param[out] rotated - obrocony wektor                                                      
 */
template <>
inline Vector<double,3> Matrix<double,3>::apply_matrix_to_rotation(const Vector<double,3> &to_rot) const;

#include"../src/matrix3D.cpp"

