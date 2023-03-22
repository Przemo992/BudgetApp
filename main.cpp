#include "BudgetApp.h"
#include "MainMenu.h"

int main()
{
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
                budgetApp.showBalanceForPresentMonth();
                break;
            case '4':
                budgetApp.showBalanceForLastMonth();
                break;
            case '5':
                budgetApp.showBalanceForSetDate();
                break;
            case '6':
                budgetApp.changeLoggedUserPassword();
                break;
            case '7':
                budgetApp.setIdLoggedUser(0);
                budgetApp.logOut();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
