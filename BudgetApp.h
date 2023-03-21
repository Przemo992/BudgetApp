#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class BudgetApp
{
    UserManager userManager;
    BudgetManager *budgetManager;
    const string NAME_FILE_WITH_INCOMES;
    const string NAME_FILE_WITH_EXPENSES;

public:
    BudgetApp(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses)
    :userManager(fileNameWithUsers), NAME_FILE_WITH_INCOMES(fileNameWithIncomes), NAME_FILE_WITH_EXPENSES(fileNameWithExpenses){
    budgetManager = NULL;
    };
    void setIdLoggedUser(int idLoggedUser);
    int getIdLoggedUser();
    void userRegister();
    void userLoggingIn();
    void displayAllUsers();
    void addExpense();
    void displayExpenses();
    void addIncome();
    void displayIncomes();
    void changeLoggedUserPassword();
    void logOut();


};
