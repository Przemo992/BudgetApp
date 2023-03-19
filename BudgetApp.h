#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class BudgetApp
{
    UserManager userManager;
    BudgetManager *budgetManager;
    //const string NAME_FILE_WITH_INCOEMS;
    //const string NAME_FILE_WITH_EXPENSES;

public:
    void userRegister();
    void userLoggingIn();
    void displayAllUsers();
    void addExpense();
    void displayExpenses();


};
