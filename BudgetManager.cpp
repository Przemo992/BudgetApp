#include "BudgetManager.h"

int BudgetManager::getIdNewExpense()
{
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}

void BudgetManager::addExpense()
{
    Expense expense = typeInNewExpenseData();

    expenses.push_back(expense);

    fileWithExpenses.addExpenseToFile(expense);

    cout << endl << "Dodano wydatek pomyslnie" << endl << endl;
    system("pause");

}

Expense BudgetManager::typeInNewExpenseData()
{
    Expense expense;

    expense.setExpenseId(getIdNewExpense());
    expense.setUserId(ID_LOGGED_USER);

    int date;
    string item = "";
    float amount;
    cout << "Podaj date wydatku"<<endl;
    cin >> date;
    cout << "Podaj na co wydano pieniadze"<<endl;
    cin >> item;
    cout << "Podaj wydana kwote"<<endl;
    cin >> amount;

    expense.setDate(date);
    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
}
