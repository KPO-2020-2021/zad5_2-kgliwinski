#include "../include/menu.hpp"

Menu::Menu()
{
    open = 1;
}

void Menu::init_menu(Scene &sc, PzG::LaczeDoGNUPlota &Lacze)
{
    if (!sc.check_scene())
    {
        open = 0;
        std::cout << "Error: Blednie zainicjowana scena\n"
                  << std::endl;
    }
    else
    {
        sc.init_gnuplot(300,300,Lacze);
        Lacze.Rysuj();
        std::cout << "\n Polozenie Drona aktywnego (x,y): ";
        sc.print_active();
        show_menu();
    }
    char n;
    while (open)
    {
        std::cout << "\nTwoj wybor? (m - menu) > ";
        std::cin >> n;
        std::cout << "\n";
        switch_menu(sc, Lacze, n);
    }
}

void Menu::switch_menu(Scene &sc, PzG::LaczeDoGNUPlota &Lacze, const char &oper)
{
    switch (oper)
    {
    case 'a':
    {
        int a;
        std::cout << "Wybor aktywnego drona\n\n";
        sc.print_positions();
        std::cout << "Wybierz aktywnego drona: ";
        std::cin >> a;
        sc.choose_drone(a - 1);
        std::cout << "\n Polozenie Drona aktywnego (x,y): ";
        sc.print_active();
        std::cout << std::endl;
        break;
    }
    case 'p':
    {
        double ang, len;
        std::cout << "Podaj kierunek lotu (kat w stopniach): ";
        std::cin >> ang;
        while(ang<0)
        {
            ang +=360;
        }
        std::cout << "Podaj długość lotu: ";
        std::cin >> len;
        if(!sc.fly(ang, len, Lacze))
            std::cout<<"Error: Bledne dane\n";
        break;
    }
    case 'o':
    {
        double rad;
        std::cout << "Podaj promien okregu: ";
        std::cin >> rad;
        if(!sc.fly_roundabout(rad, Lacze))
            std::cout<<"Error: Bledne dane\n";
        break;
    }
    case 'm':
    {
        show_menu();
        break;
    }
    case 'k':
    {
        std::cout << "Koniec dzialania programu\n";
        open = 0;
        break;
    }
    default:
    {
        std::cout << "Bledna opcja\n";
        break;
    }
    }
}

void Menu::show_menu()
{
    std::cout << std::endl;
    std::cout << "a - wybierz aktywnego drona\n";
    std::cout << "p - zadaj parametry przelotu\n";
    std::cout << "o - MODYFIKACJA: wznoszenie na okreslona wysokosc i zatoczenie kola\n";
    std::cout << "m - wyswietl menu\n";
    std::cout << "k - koniec dzialania programu\n\n";
}