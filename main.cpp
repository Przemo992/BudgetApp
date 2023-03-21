#include <iostream>

#include "BudgetApp.h"
#include "MainMenu.h"

using namespace std;

int main()
{
    //KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    BudgetApp budgetApp("users.xml", "incomes.xml", "expenses.xml");

    char choose;

    while (true)
    {
        if (budgetApp.getIdLoggedUser() == 0)
        {
            choose = MainMenu::chooseOptionFromUserMenu();

            switch (choose)
            {
            case '1':
                budgetApp.userRegister();
                break;
            case '2':
                budgetApp.userLoggingIn();
                break;
            case '0':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {

            choose = MainMenu::chooseOptionFromBudgetMenu();

            switch (choose)
            {
            case '1':
                budgetApp.addIncome();
                break;
            case '2':
                budgetApp.addExpense();
                break;
            case '3':
                budgetApp.displayExpenses();
                break;
            case '4':
                budgetApp.displayIncomes();
                break;
           case '5':
                //ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                budgetApp.changeLoggedUserPassword();
                break;
            case '7':
                budgetApp.setIdLoggedUser(0);
                budgetApp.logOut();
                break;
            }
        }
    }
    return 0;
}
