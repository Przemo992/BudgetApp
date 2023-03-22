#include "UserManager.h"
#include "BudgetManager.h"

class BudgetApp
{
    UserManager userManager;
    BudgetManager *budgetManager;
    const string NAME_FILE_WITH_INCOMES;
    const string NAME_FILE_WITH_EXPENSES;

public:
    BudgetApp(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses)
        :userManager(fileNameWithUsers), NAME_FILE_WITH_INCOMES(fileNameWithIncomes), NAME_FILE_WITH_EXPENSES(fileNameWithExpenses)
    {
        budgetManager = NULL;
    };
    ~BudgetApp()
    {
        delete budgetManager;
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
    void showBalanceForPresentMonth();
    void showBalanceForLastMonth();
    void showBalanceForSetDate();
};
