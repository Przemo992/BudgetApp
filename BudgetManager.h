#include <iostream>
#include <vector>

#include "Expenses.h"
#include "Incomes.h"

#include "FileWithExpenses.h"
#include "HelpingMethods.h"
#include "DateMenu.h"

using namespace std;

class BudgetManager
{
    FileWithExpenses fileWithExpenses;
    //FileWithIncomes fileWithIncomes

    const int ID_LOGGED_USER;

    vector <Expense> expenses;
    vector <Income> incomes;

    int getIdNewExpense();
    void displayExpenseData(Expense expense);


public:
    BudgetManager(int idLoggedUser)
    : ID_LOGGED_USER(idLoggedUser){
    expenses = fileWithExpenses.loadExpensesFromFile(ID_LOGGED_USER);
    };
    void addExpense();
    Expense typeInNewExpenseData();
    void displayExpenses();




};
