#include <iostream>
#include <vector>

#include "Expenses.h"
#include "Incomes.h"

#include "FileWithExpenses.h"
#include "FileWithIncomes.h"
#include "HelpingMethods.h"
#include "DateMenu.h"

using namespace std;

class BudgetManager
{
    FileWithExpenses fileWithExpenses;
    FileWithIncomes fileWithIncomes;
DateMenu dateMenu;
    const int ID_LOGGED_USER;

    vector <Expense> expenses;
    vector <Income> incomes;

    int getIdNewExpense();
    void displayExpenseData(Expense expense);
    int getIdNewIncome();
    void displayIncomesData(Income income);


public:
    BudgetManager(string nameFileWithIncomes, string nameFileWithExpenses, int idLoggedUser)
    : ID_LOGGED_USER(idLoggedUser), fileWithIncomes(nameFileWithIncomes), fileWithExpenses(nameFileWithExpenses){
    expenses = fileWithExpenses.loadExpensesFromFile(ID_LOGGED_USER);
    incomes = fileWithIncomes.loadIncomesFromFile(ID_LOGGED_USER);
    };
    void addExpense();
    Expense typeInNewExpenseData();
    void displayExpenses();
    void addIncome();
    Income typeInNewIncomeData();
    void displayIncomes();
    void logOut();




};
