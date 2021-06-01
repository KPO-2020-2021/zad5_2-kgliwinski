#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include"count.hpp"

constexpr double PI = 3.14159265;
/*!
 * \file  vector.hpp
 *  
 *  Plik zawiera definicję klasy reprezentujacej wektor
 *  o wymiarach SIZEx1
 */

/*! \class Vector
 *  \brief Opisuje wektor o SIZE-wierszach
 */

template <typename type, unsigned int SIZE> 
class Vector: public Count<Vector<type,SIZE>> {

private:
/*!
 * \brief Tablica wektora
 */
    type size[SIZE];     

public:

/*!
 *  \brief Konstruktor klasy Vector.        
                                        
 *  Argumenty:                                                               
 *      Brak argumentow.                                                     
 *  Zwraca:                                                                  
 *      \param[out] this -  Wektory wypelniony wartoscia 0.                                      
 */
    Vector();

/*!
 *  \brief Konstruktor klasy Vector.                                                
 *  Argumenty:                                                               
 *      \param[in] tmp - Jednowymiarowa tablica typu zz.                            
 *  Zwraca:                                                                  
 *      \param[in] this - Tablice wypelniona wartosciami podanymi w argumencie.                
 */
    Vector(type [SIZE]);


/*!
 *  \brief Realizuje dodawanie dwoch wektorow.                                      
 *  Argumenty:                                                               
 *      \param[in] this - pierwszy skladnik dodawania,                                  
 *      \param[in] v - drugi skladnik dodawania.                                        
 *  Zwraca:                                                                  
 *      \param[out] result - Sume dwoch skladnikow przekazanych jako wskaznik                     
 *      na parametr.                                                         
 */
    Vector operator + (const Vector &v) const;

/*!
 *  \brief Realizuje odejmowanie dwoch wektorow.                                    
 *  Argumenty:                                                               
 *      \param[in] this - pierwszy skladnik odejmowania,                                
 *      \param[in] v - drugi skladnik odejmowania.                                      
 *  Zwraca:                                                                  
 *      \param[in] result - Roznice dwoch skladnikow przekazanych jako wskaznik                  
 *      na parametr.                                                         
 */
    Vector operator - (const Vector &v) const;

/*!
 *  \brief Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.              
 *  Argumenty:                                                               
 *      \param[in] this - pierwszy skladnik mnozenia (wektor),                          
 *      \param[in] v - drugi skladnik mnozenia (liczba typu type).                    
 *  Zwraca:                                                                  
 *      \param[in] result - Iloczyn dwoch skladnikow przekazanych jako wskaznik                  
 *      na parametr.                                                         
 */
    Vector operator * (const type &tmp) const;

/*!
 *  \brief Realizuje dzielenie dwoch wektorow.                                      
 *  Argumenty:                                                               
 *      \param[in] this - licznik dzielenia,                                            
 *      \param[in] v - mianownik dzielenia.                                             
 *  Zwraca:                                                                  
 *      \param[in] result - Iloraz dwoch skladnikow przekazanych jako wskaznik                   
 *      na parametr.                                                         
 */
    Vector operator / (const type &tmp) const;

/*!
 *  \brief Sprawdza czy wektory sa rowne                                      
 *  Argumenty:                                                               
 *      \param[in] this - l,                                            
 *      \param[in] v - r.                                             
 *  Zwraca:                                                                  
 *     \retval true - sa rowne
 *     \retval false - nie sa rowne                                                        
 */
    bool operator == (const Vector &v) const;

/*!
 *  \brief Skaluje wektor o inny wektors                                     
 *  Argumenty:                                                               
 *      \param[in] vec - wektor przez ktory ma zostac przeskalowany
 *                       obiekt                                          
 *  Zwraca:                                                                  
 *     \return - przeskalowany wektor                                                        
 */
    Vector scale_vec(const Vector &vec) const;

    Vector rotate(const type &theta) const; //2D rotation

/*!
 * \brief Zwraca kwadrat modulu wektora                                             
 * Argumenty:                                                                
 *      Brak                                                                 
 * Zwraca:                                                                   
 *      \param[out] result - kwadrat modulu wektora                                               
 */
    type modulus2() const;

/*!
 * \brief Zwraca wektor do tablicy o rozmiarze SIZE                                           
 * Argumenty:                                                                
 *      \param[in] tab - tablica do ktorej wypisywany jest wektor                                                                 
 * Zwraca:                                                                   
 *      \post zmienia zawartosc podanej tablicy                                              
 */
    void get_vec(type (&tab)[SIZE]) const;

/*!
 * \brief Zwraca dlugosc wektora                                                    
 * Argumenty:                                                                
 *      Brak                                                                 
 * Zwraca:                                                                   
 *      \param[out] len - dlugosc wektora                                                      
 */
    type get_len() const;

    type get_slope_angle() const;   //2D rotation

/*!
 *  \brief Funktor wektora.                                                         
 *  Argumenty:                                                               
 *      \param[in] index - index wektora.                                               
 *  Zwraca:                                                                  
 *      \param[out] size - Wartosc wektora w danym miejscu tablicy jako stala.                  
 */
    const type &operator [] (unsigned int index) const;

/*!
 *  \brief Funktor wektora.                                                         
 *  Argumenty:                                                               
 *      \param[in] index - index wektora.                                               
 *  Zwraca:                                                                  
 *      \param[out] Vector - Wartosc wektora w danym miejscu tablicy.                             
 */
    type &operator [] (unsigned int index);


/*!
 *  \brief Iloczyn skalarny wektorow                                                        
 *  Argumenty:                                                               
 *      \param[in] vec - drugi wektor do porownania                                              
 *  Zwraca:                                                                  
 *      \param[out] res - wynik iloczynu skalarnego                           
 */
    type scalar_prod(Vector const & vec) const;
};

/*!
 *  \brief Przeciazenie operatora <<                                                
 *  Argumenty:                                                               
 *      \param[in] out - strumien wyjsciowy,                                            
 *      \param[in] tmp - wektor.   
 *  Zwraca:
 *      \param[out] out - strumien wyjsciowy                                                     
 */
template <typename type, unsigned int SIZE> 
std::ostream &operator << (std::ostream &out, Vector<type,SIZE> const &tmp);

/*!
 *  \brief Przeciazenie operatora >>                                                
 *  Argumenty:                                                               
 *      \param[in] in - strumien wejsciowy,                                             
 *      \param[in] tmp - wektor.   
 *  Zwraca:
 *      \param[out] in - strumien wejsciowy                                                     
 */
template <typename type, unsigned int SIZE> 
std::istream &operator >> (std::istream &in, Vector<type,SIZE> &tmp);


#include"../src/vector.tpp"