#include "BudgetApp.h"

void BudgetApp::userRegister()
{
    userManager.userRegister();
}
void BudgetApp::userLoggingIn()
{
    userManager.userLoggingIn();

    budgetManager = new BudgetManager(userManager.getIdLoggedUser());

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
