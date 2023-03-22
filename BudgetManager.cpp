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

    std::sort( expenses.begin(), expenses.end(), Expense::comp);

    cout << endl << "Dodano wydatek pomy˜lnie" << endl << endl;
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

    while(intDate == 0)
    {
        intDate = dateMenu.setDate();
    }

    cout << "Podaj na co wydano pieni¥dze"<<endl;
    item = HelpingMethods::getLine();
    cout << "Podaj wydan¥ kwot©"<<endl;
    amount = HelpingMethods::changeCommaToDot(HelpingMethods::typeInFloatNumber());
    float amountWithDot = stof(amount);

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
        cout << endl << "Brak Wydatk¢w." << endl << endl;
    }

    system("pause");
}

void BudgetManager::displayExpenseData(Expense expense)
{
    cout << "Data          " << HelpingMethods::insertDashesToDate(to_string(expense.getDate())) << endl;
    cout << "Na co         " << expense.getItem() << endl;
    cout << "Kwota         " << fixed <<setprecision(2);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout << expense.getAmount() <<" zˆ"<< endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
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

    std::sort( incomes.begin(), incomes.end(), Income::comp);

    cout << endl << "Dodano przych¢d pomy˜lnie!" << endl << endl;

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

    while(intDate == 0)
    {
        intDate = dateMenu.setDate();
    }

    cout << "Podaj sk¥d wpˆyn©ly ˜rodki"<<endl;

    item = HelpingMethods::getLine();

    cout << "Podaj zarobion¥ kwot©"<<endl;

    amount = HelpingMethods::changeCommaToDot(HelpingMethods::typeInFloatNumber());
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
        cout << "              >>> PRZYCHODY <<<                " << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            displayIncomesData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Brak Przychod¢w." << endl << endl;
    }

    system("pause");
}

void BudgetManager::displayIncomesData(Income income)
{
    cout << "Data          " << HelpingMethods::insertDashesToDate(to_string(income.getDate())) << endl;
    cout << "½r¢dlo        " << income.getItem() << endl;
    cout << "Kwota         " << fixed <<setprecision(2);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    cout << income.getAmount() <<" zˆ"<< endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
void BudgetManager::logOut()
{
    expenses.clear();
    incomes.clear();
}

void BudgetManager::showBalanceForChosenDateRange(int dateFrom, int dateTo)
{
    float expensesSum = 0, incomesSum = 0;

    system("cls");

    if (!incomes.empty())
    {
        cout << "              >>> PRZYCHODY <<<                " << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            if (itr->getDate() >= dateFrom && itr->getDate()<= dateTo)
            {
                displayIncomesData(*itr);
                incomesSum += itr->getAmount();
            }

        }
    }

    if (incomesSum == 0)
    {
        cout << endl << "Brak Przych¢dow w wybranym okresie." << endl << endl;
    }

    if (!expenses.empty())
    {
        cout << "               >>> WYDATKI <<<                 " << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            if (itr->getDate() >= dateFrom && itr->getDate()<= dateTo)
            {
                displayExpenseData(*itr);
                expensesSum += itr->getAmount();
            }
        }
    }

    if (expensesSum == 0)
    {
        cout << endl << "Brak Wydatk¢w w wybranym okresie." << endl << endl;
    }

    if (expensesSum == 0 && incomesSum == 0)
    {
        system("pause");
        return;
    }

    cout << endl<<"Suma Twoich przychod¢w w wybranym okresie to: " << incomesSum << " zˆ\n";
    cout << endl<<"Suma Twoich wydatk¢w w wybranym okresie to:   " << expensesSum << " zˆ\n\n";

    if (incomesSum - expensesSum < 0)
    {
        cout << "\nNiestety jestes na minusie, bilans wynosi: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        cout << incomesSum - expensesSum << " zˆ\n\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    }
    else
    {
        cout << "Pozostaˆa kwota do wydania: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
        cout << incomesSum - expensesSum << " zˆ\n\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    }

    system("pause");
}

void BudgetManager::showBalanceForPresentMonth()
{
    int dateFrom = stoi(dateMenu.getFirstDayPresentMonth());
    int dateTo = stoi(dateMenu.getPresentDate());
    showBalanceForChosenDateRange(dateFrom, dateTo);
}

void BudgetManager::showBalanceForLastMonth()
{
    int year = dateMenu.getPresentYear();

    int month = dateMenu.getPresentMonth();
    string monthStr = "";

    if (month == 1)
    {
        month = 12;
        year--;
        monthStr = "12";
    }
    else
    {
        month = dateMenu.getPresentMonth() - 1;
        monthStr = to_string(month);
    }

    if(monthStr.length() < 2) monthStr = "0" + monthStr;

    string yearStr = to_string(year);
    string daysOfMonth = to_string(dateMenu.daysOfMonth(month, year));
    string dateFromStr = yearStr + monthStr + "01";
    string dateToStr = yearStr + monthStr + daysOfMonth;

    int dateFrom = stoi(dateFromStr);
    int dateTo = stoi(dateToStr);

    showBalanceForChosenDateRange(dateFrom, dateTo);
}

void BudgetManager::showBalanceForSetDate()
{
    cout << "Wprowad« zakres daty dla bilansu.\n";
    cout << "UWAGA ( Podaj date w formacie yyyy-mm-dd )\n\n";
    cout << "\nwprowad« date od: ";
    int dateFrom = dateMenu.typeInDate();
    cout << " do: ";
    int dateTo = dateMenu.typeInDate();

    showBalanceForChosenDateRange(dateFrom, dateTo);
}
