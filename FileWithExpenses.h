#include <fstream>
#include <vector>

#include "Expenses.h"
#include "XmlFile.h"
#include "Markup.h"

class FileWithExpenses :public XmlFile
{
    Expense setExpenseData(int expenseId, int userId, int date, string item, float amount);

public:
    FileWithExpenses(string fileName)
    : XmlFile(fileName){};
    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesFromFile(int idLoggedUser);
    int getLastExpenseId();

};
