#include <iostream>
#include <vector>

#include "Expenses.h"
#include "Incomes.h"

#include "FileWithExpenses.h"

using namespace std;

class BudgetManager
{
    FileWithExpenses fileWithExpenses;
    //FileWithIncomes fileWithIncomes

    const int ID_LOGGED_USER;

    vector <Expense> expenses;
    vector <Income> incomes;

    int getIdNewExpense();
public:
    BudgetManager(int idLoggedUser)
    : ID_LOGGED_USER(idLoggedUser){};
    void addExpense();
    Expense typeInNewExpenseData();
    void displayExpenses();




};
