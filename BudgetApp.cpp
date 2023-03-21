#include "BudgetApp.h"

void BudgetApp::userRegister()
{
    userManager.userRegister();
}
void BudgetApp::userLoggingIn()
{
    userManager.userLoggingIn();

    budgetManager = new BudgetManager(NAME_FILE_WITH_INCOMES, NAME_FILE_WITH_EXPENSES, userManager.getIdLoggedUser());

}
void BudgetApp::displayAllUsers()
{
    userManager.displayAllUsers();
}

void BudgetApp::addExpense()
{
  budgetManager->addExpense();
}

void BudgetApp::displayExpenses()
{
    budgetManager->displayExpenses();
}
void BudgetApp::addIncome()
{
    budgetManager->addIncome();
}
void BudgetApp::displayIncomes()
{
    budgetManager->displayIncomes();
}
int BudgetApp::getIdLoggedUser()
{
    return userManager.getIdLoggedUser();
}
void BudgetApp::changeLoggedUserPassword()
{
    userManager.changeLoggedUserPassword();
}
void BudgetApp::setIdLoggedUser(int idLoggedUser)
{
    userManager.setIdLoggedUser(idLoggedUser);
}
void BudgetApp::logOut()
{
    budgetManager->logOut();
    delete budgetManager;
    budgetManager = NULL;
}
