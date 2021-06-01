#pragma once
#include "vector.hpp"
#include "vector3D.hpp"
#include <iostream>
#include <cstdlib>
/*!
 * \file  matrix.hpp
 *  
 *  Plik zawiera definicję klasy reprezentujacej macierz
 *  o wymiarach SIZExSIZE
 */



/*! \class Matrix
 *  \brief Opisuje macierz SIZExSIZE
 */
template<typename type, unsigned int SIZE>
class Matrix {

private:
/*!
 * \brief Tablica wartosci macierzy
 */
    type value[SIZE][SIZE];               

public:


/*!
 *  \brief Konstruktor klasy Matrix.                                                
 *  Argumenty:                                                               
 *      Brak argumentow.                                                     
 *  Zwraca:                                                                  
 *      \param[out] Matrix jednostkowa                                       
 */
    Matrix();                               // Konstruktor klasy

/*!
 *  \brief Konstruktor parametryczny klasy Matrix.                                  
 *  Argumenty:                                                               
 *      \param[in] tmp - dwuwymiarowa tablica z elementami typu type.                 
 *  Zwraca:                                                                  
 *      \param[out] Matrix wypelniona wartosciami podanymi w argumencie.                
 */
    Matrix(type [SIZE][SIZE]);            // Konstruktor klasy

/*!
 *  \brief Destruktor klasy Matrix.                                                 
 *  Argumenty:                                                               
 *      Brak argumentow.                                                     
 *  Zwraca:                                                                  
 *      \post Usuwa klase                                                          
 */
    ~Matrix();                              // Destruktor klasy


/*!
 *  \brief Realizuje mnozenie macierzy przez wektor. (gdzie mnozenie jest typu vector*matrix)
 *          Mimo ze definicja moze na to nie wskazywac (!)                               
 *  Argumenty:                                                               
 *      \param[in] this - macierz, czyli pierwszy skladnik mnozenia,                    
 *      \param[in] tmp - wektor, czyli drugi skladnik mnozenia.                           
 *  Zwraca:                                                                  
 *      \param[out] result - Iloczyn dwoch skladnikow przekazanych jako wektor.                   
 */
    Vector<type,SIZE> operator * (Vector<type,SIZE> const  &tmp) const;           // Operator mnożenia macierzy przez wektor
/*!
 *  \brief Przeciążenie dodawania macierzy                                                         
 *  Argumenty:                                                               
 *      \param[in] this - macierz, czyli pierwszy skladnik dodawania,                    
 *      \param[in] v - wektor, czyli drugi skladnik dodawania.                                              
 *  Zwraca:                                                                  
 *      \param[out] Macierz - iloczyn dwóch podanych macierzy.                 
 */
    Matrix operator + (Matrix tmp);

/*!
 *  \brief Przeciążenie odejmowania macierzy                                                         
 *  Argumenty:                                                               
 *      \param[in] this - macierz, czyli pierwszy skladnik dodawania,                    
 *      \param[in] v - wektor, czyli drugi skladnik dodawania.                                              
 *  Zwraca:                                                                  
 *      \param[out] Macierz - iloczyn dwóch podanych macierzy.                 
 */
    Matrix operator - (Matrix tmp);

/*!
 *  \brief Przeciążenie == macierzy                                                         
 *  Argumenty:                                                               
 *      \param[in] this - macierz, ktora porownujemy                   
 *      \param[in] tmp - macierz, z ktora porownujemy                                                          
 *  Zwraca:                                                                  
 *      \retval true - jesli sa rowne
 *      \retval false - jesli nie sa                
 */
    bool operator == (Matrix const &tmp) const;

/*!
 *  \brief Funktor macierzy                                                         
 *  Argumenty:                                                               
 *      \param[in] row - numer wiersza.                                                 
 *      \param[in] column - numer kolumny.                                              
 *  Zwraca:                                                                  
 *      \param[out] value Wartosc macierzy w danym miejscu tablicy.                            
 */
    type  &operator () (unsigned int row, unsigned int column);
    
/*!
 *  \brief Funktor macierzy                                                         
 *  Argumenty:                                                               
 *      \param[in] row - numer wiersza.                                                 
 *      \param[in] column - numer kolumny.                                              
 *  Zwraca:                                                                  
 *      \param[out] Wartosc macierzy w danym miejscu tablicy jako stala.                 
 */
    const type &operator () (unsigned int row, unsigned int column) const;

/*!
 *  \brief Zwraca macierz schodkowa utworzona przez eliminacje gaussa                                                        
 *  Argumenty:                                                               
 *      \param[in] this - macierz dla ktorej chcemy przeprowadzic operacje                                                           
 *  Zwraca:                                                                  
 *      \param[out] mat - macierz schodkowa              
 */
    Matrix gauss() const;

/*!
 *  \brief Zwraca wyznacznik macierzy                                                       
 *  Argumenty:                                                               
 *      \param[in] this - macierz, ktorej wyznacznik liczymy                                                             
 *  Zwraca:                                                                  
 *      \param[out] det - wyznacznik               
 */
    type determinant() const;

/*!
 *  \brief Zwraca wynik mnozenia dwoch macierzy                                                      
 *  Argumenty:                                                               
 *      \param[in] this - macierz 1 (L)
 *      \param mat - macierz 2 (P)                                                             
 *  Zwraca:                                                                  
 *      \param[out] res - wynik mnozenia macierzy               
 */
    Matrix operator*(Matrix const &mat) const;

    void rotation_matrix(const type & angle);   //2D rotation

    Matrix rotation_matrix(const type & angle, const char &axis) const; //3D rotation

    Vector<type,SIZE> apply_matrix_to_rotation(const Vector<type,SIZE> &rotation) const; //3D rotation

/*!
 *  \brief ZADANIE DO MODYFIKACJI
 *          Tworzy macierz 4x4 zdolna do jednoczesnego obrotu i przesuniecia wektora                                                      
 *          Zdefiniowana w macierz4D.hpp            
 */
    void rotate_and_translate(const double & alpha, const double & beta, const double & gamma, const Vector3D &tran) ;
};


/*!
 *  \brief Przeciazenie operatora >>                                                
 *  Argumenty:                                                               
 *      \param[in] in - strumien wejsciowy,                                             
 *      \param[in] mat - macierz. 
 *  Zwraca:
 *      \param[out] in - strumien wejsciowy                                                       
 */
template<typename type, unsigned int SIZE>
std::istream &operator>>(std::istream &in, Matrix<type,SIZE> &mat);

/*!
 *  \brief Przeciazenie operatora <<                                                
 *  Argumenty:                                                               
 *      \param[in] out - strumien wyjsciowy,                                            
 *      \param[in] mat - macierz.     
 *  Zwraca:
 *      \param[out] out - strumien wyjsciowy                                                  
 */
template<typename type, unsigned int SIZE>
std::ostream &operator<<(std::ostream &out, Matrix<type,SIZE> const &mat);



#include"../src/matrix.tpp"


