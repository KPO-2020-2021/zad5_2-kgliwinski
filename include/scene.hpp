#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>
#include "drone.hpp"
#include "lacze_do_gnuplota.hpp"


constexpr unsigned int SIZE = 2;

/*!
 * \file  scene.hpp
 *  
 *  \brief Plik zawiera definicję klasy reprezentujacej scene,
 *         obslugujacej zapis do plikow i wytswietlanie w gnuplocie
 */

/*!
 *  \class Scene
 *  \brief Opisuje scene w 3D w ktorej poruszaja sie drony
 */
class Scene
{
private:

/*!
 * \brief Tablica dronow obslugiwanych w programie
 */
    Drone flies[SIZE];
/*!
 * \brief Wskaznik na aktywnego drona. Wartosc koresponduje z ta
 *          z tablicy flies (drony sa numerowane w zakresie 0 , 1 , ... , (SIZE-1))
 */

    unsigned int active;

/*!
 * \brief Nazwa pliku w ktorym zawarta jest plaszczyzna
 *         reprezentujaca podloze (ziemie) w Gnuplocie
 */
    std::string land_name;

public:

/*!
 * \brief Konstruktor paramereyczny klasy Scene
 *      \param[in] pos - tablica polozen dronow
 *      \param[in] scal_bod - tablica skali korpusow dronow
 *      \param[in] scal_rot - tablica skali rotorow dronow
 *      \param[in] name - nazwa pliku w ktorym opisana jest plaszczyzna sceny
 *      \param[in] names_bod - tablica nazw plikow sample i final dla prostopadloscianow body
 *      \param[in] names_rot - tablica nazw plikow sample i final dla graniastoslupow rotors
 *      \post Ustawia odpowiednie wartosci klasy, zadane przez uzytkownika
 */
Scene(Vector3D const (&pos)[SIZE], Vector3D const (&scal_bod)[SIZE],Vector3D const (&scal_rot)[SIZE], std::string const &name, 
std::string const (&names_bod)[SIZE][2],std::string const (&names_rot)[SIZE][4][2]);

/*!
 * \brief Metoda sprawdzajaca poprawnosc inicjacji sceny
 *      \retval true - scena poprawnie zainicjowana
 *      \retval false - scena blednie zainicjowana
 */
bool check_scene() const;

/*!
 *  \brief Przeciazenie operatora == dla klasy Scene    
 *       \b{Parametr active jest pomijany}                                         
 *      \param[in] pri - porownywana scena                                            
 *      \retval false - nie sa rowne, 
 *      \retval true - sa rowne                                                     
 */
bool operator == (const Scene &sce) const;


/*!
 * \brief Metoda pozwalajaca na wybor aktywnego drona
 *      \param[in] ch - nowo wybrany dron
 *      \post Wybiera aktywnego drona (wartosc klasy active)
 *      \retval false - jesli zadana wartosc jest spoza zakresu
 *      \retval true - jesli zadana wartosc jest poprawna
 */
bool choose_drone(unsigned int const &ch);

/*!
 * \brief Metoda inicjalizujaca lacze do gnuplota
 *  \param[in] parametry okreslajace zakresy
 *  \post Powstaje w pelni skonfigurowane lacze, ktore 
 *          moze byc uzyte do rysowania calej sceny
 */
PzG::LaczeDoGNUPlota init_gnuplot(double const &x1, double const &x2,double const &y1,double const &y2) const;

/*!
 * \brief Metoda tworzy plaszczyzne z podanych zakresow
 *          i zwraca nazwe pliku do zapisu
 */
bool Make_Plane(double const &x1, double const &x2,double const &y1,double const &y2, std::string const &name) const;

/*!
 * \brief Metoda dodajaca do lacza plik z plaszczyzna
 */
void Add_Plane(PzG::LaczeDoGNUPlota &Lacze) const;

/*!
 * \brief Zwraca numer aktywnego drona
 */
unsigned int get_active() const;

/*!
 * \brief Wypisuje polozenie aktywnego drona
 */
void print_active() const;

/*!
 * \brief Wypisuje polozenia dronow
 */
void print_positions() const;

/*!
 * \brief Przelot aktywnego drona
  *     \pre Lacze musi byc odpowiednio skonfigurowane
 *     \param[in] angle - kat w stopniach
 *     \param[in] len - dlugosc przelotu       
 *     \param[in] Lacze - aktywne lacze do gnuplota                                                                          
 *     \post W oknie gnuplota wykonuje sie animacja translacji drona
 *     \retval true - jesli jest odpowiednio skonfigurowane lacze
 *     \retval false - w przeciwnym wypadku                                   
 */
 
bool fly(double const &angle, double const &len, PzG::LaczeDoGNUPlota &Lacze);

/*!
 * \brief Przelot aktywnego drona
  *     \pre Lacze musi byc odpowiednio skonfigurowane
 *     \param[in] radius - promien okregu przelotu      
 *     \param[in] Lacze - aktywne lacze do gnuplota                                                                          
 *     \post W oknie gnuplota wykonuje sie animacja translacji drona  
 *     \retval true - jesli jest odpowiednio skonfigurowane lacze
 *     \retval false - w przeciwnym wypadku                                 
 */
 
bool fly_roundabout(double const &radius, PzG::LaczeDoGNUPlota &Lacze);
};