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

    string date="";
    string item = "";
    string amount;
    int intDate;
    do
    {
        cout << "Podaj date wydatku w formacie yyyy-mm-dd"<<endl;
        cin >> date;
    } while (DateMenu::checkIsDateCorrect(date) == false);
    intDate = stoi(HelpingMethods::eraseDashFromDate(date));
    cout << "Podaj na co wydano pieniadze"<<endl;
    cin >> item;
    cout << "Podaj wydana kwote"<<endl;
    amount = HelpingMethods::getLine();
    float amountWithDot = stof(HelpingMethods::changeCommaToDot(amount));
    expense.setDate(intDate);
    expense.setItem(item);
    expense.setAmount(amountWithDot);

    return expense;
}

void BudgetManager::displayExpenses()
{
    system("cls");
    if (!expenses.empty())
    {
        cout << "             >>> WYDATKI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            displayExpenseData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Brak Wydatkow." << endl << endl;
    }
    system("pause");
}

void BudgetManager::displayExpenseData(Expense expense)
{
    cout << endl << "Data:            " << HelpingMethods::insertDashesToDate(to_string(expense.getDate())) << endl;
    cout << "Na co:           " << expense.getItem() << endl;
    cout << "Kwota:           " << expense.getAmount() << endl;
}
