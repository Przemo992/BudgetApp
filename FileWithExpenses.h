#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Expenses.h"
#include "Markup.h"

using namespace std;

class FileWithExpenses
{
    CMarkup xml;
    string nameFileWithExpenses;

    Expense setExpenseData(int expenseId, int userId, int date, string item, float amount);

public:
    FileWithExpenses();
    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesFromFile(int idLoggedUser);

};
