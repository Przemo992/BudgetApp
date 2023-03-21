#include "BudgetManager.h"

int BudgetManager::getIdNewExpense()
{

    if (fileWithExpenses.checkIsFileExist() == false)
    {
        return 1;
    }
    else
    {
        return fileWithExpenses.getLastExpenseId() + 1;
    }


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

    expense.setId(getIdNewExpense());
    expense.setUserId(ID_LOGGED_USER);

    string item = "";
    string amount;
    int intDate = 0;

    while(intDate == 0){
    intDate = dateMenu.setDate();
    }

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

int BudgetManager::getIdNewIncome()
{

    if (fileWithIncomes.checkIsFileExist() == false)
    {
        return 1;
    }
    else
    {
        return fileWithIncomes.getLastIncomeId() + 1;
    }


}

void BudgetManager::addIncome()
{
    Income income = typeInNewIncomeData();

    incomes.push_back(income);

    fileWithIncomes.addIncomeToFile(income);

    cout << endl << "Dodano przychod pomyslnie" << endl << endl;
    system("pause");

}

Income BudgetManager::typeInNewIncomeData()
{
    Income income;

    income.setId(getIdNewIncome());
    income.setUserId(ID_LOGGED_USER);

    string item = "";
    string amount;
    int intDate = 0;

    while(intDate == 0){
    intDate = dateMenu.setDate();
    }

    cout << "Podaj skad wplynely srodki"<<endl;
    cin >> item;
    cout << "Podaj zarobiona kwote"<<endl;
    amount = HelpingMethods::getLine();
    float amountWithDot = stof(HelpingMethods::changeCommaToDot(amount));

    income.setDate(intDate);
    income.setItem(item);
    income.setAmount(amountWithDot);

    return income;
}

void BudgetManager::displayIncomes()
{
    system("cls");
    if (!incomes.empty())
    {
        cout << "             >>> PRZYCHODY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            displayIncomesData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Brak Przychodow." << endl << endl;
    }
    system("pause");
}

void BudgetManager::displayIncomesData(Income income)
{
    cout << endl << "Data Wplywow:    " << HelpingMethods::insertDashesToDate(to_string(income.getDate())) << endl;
    cout << "Skad:            " << income.getItem() << endl;
    cout << "Kwota:           " << income.getAmount() << endl;
}
void BudgetManager::logOut()
{
    expenses.clear();
    incomes.clear();
}
