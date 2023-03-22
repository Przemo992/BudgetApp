#include <vector>
#include <iomanip>

#include "Expenses.h"
#include "Incomes.h"

#include "FileWithExpenses.h"
#include "FileWithIncomes.h"
#include "HelpingMethods.h"
#include "DateMenu.h"

class BudgetManager
{
    const int ID_LOGGED_USER;

    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;

    DateMenu dateMenu;

    vector <Expense> expenses;
    vector <Income> incomes;

    int getIdNewExpense();
    void displayExpenseData(Expense expense);
    int getIdNewIncome();
    void displayIncomesData(Income income);
    void showBalanceForChosenDateRange(int dateFrom, int dateTo);

public:
    BudgetManager(string nameFileWithIncomes, string nameFileWithExpenses, int idLoggedUser)
        : ID_LOGGED_USER(idLoggedUser), fileWithIncomes(nameFileWithIncomes), fileWithExpenses(nameFileWithExpenses)
    {
        expenses = fileWithExpenses.loadExpensesFromFile(ID_LOGGED_USER);
        incomes = fileWithIncomes.loadIncomesFromFile(ID_LOGGED_USER);
    };
    Income typeInNewIncomeData();
    Expense typeInNewExpenseData();
    void addExpense();
    void displayExpenses();
    void addIncome();
    void displayIncomes();
    void logOut();
    void showBalanceForPresentMonth();
    void showBalanceForLastMonth();
    void showBalanceForSetDate();
};
