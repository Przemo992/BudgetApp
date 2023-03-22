#include "MainMenu.h"

char MainMenu::chooseOptionFromUserMenu()
{
    char choose;

    system("cls");
    cout << "    >>> MENU  Gù‡WNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "0. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choose = HelpingMethods::getChar();

    return choose;
}

char MainMenu::chooseOptionFromBudgetMenu()
{
    char choose;

    system("cls");
    cout << " >>> MENU UΩYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przych¢d" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biez•cego miesi•ca" << endl;
    cout << "4. Bilans z poprzedniego miesi•ca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmie‰ haslo" << endl;
    cout << "7. Wyloguj si©" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choose = HelpingMethods::getChar();

    return choose;
}
