#pragma once
#include "scene.hpp"

/*!
 * \file  menu.hpp
 *  
 *  \brief Plik zawiera definicję klasy reprezentujacej menu,
 *         obslugujace menu programu
 */

/*!
 *  \class Menu
 *  \brief Opisuje menu programu Dron5.1
 */

class Menu{
private:
/*!
 * \brief Zmienna mowiaca czy menu jest aktywne
 */
    bool open;

    public:
    
/*!
 * \brief Konstruktor bezparametryczny menu
 */
    Menu();

public:
/*!
 * \brief Inicjuje i obsluguje menu
 *  \param[in] sc - scena
 *  \param[in] Lacze - lacze do gnuplota
 */
    void init_menu(Scene &sc, PzG::LaczeDoGNUPlota &Lacze);

/*!
 * \brief Obsluguje wybor menu
 *  \param[in] sc - scena
 *  \param[in] Lacze - lacze do gnuplota
 *  \param[in] oper - operator switch'a
 */
void switch_menu(Scene &sc, PzG::LaczeDoGNUPlota &Lacze, const char &oper);

/*!
 * \brief Wyswietla menu
 */
void show_menu();

/*!
 * \brief Wyswietla menu wyboru obiektu
 */
void show_object_menu();

};