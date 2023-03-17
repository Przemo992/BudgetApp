#include "FileWithExpenses.h"

FileWithExpenses::FileWithExpenses()
{
    nameFileWithExpenses = "expenses.xml";
}

void FileWithExpenses::addExpenseToFile(Expense expense)
{

    bool fileExists = xml.Load( nameFileWithExpenses );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", to_string(expense.getExpenseId()));
    xml.AddElem("UserId", to_string(expense.getUserId()));
    xml.AddElem("Date", to_string(expense.getDate()));
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", to_string(expense.getAmount()));

    xml.Save(nameFileWithExpenses);
}

vector <Expense> FileWithExpenses::loadExpensesFromFile()
{
    Expense expense;
    vector <Expense> expenses;
    CMarkup xml;
    bool fileExists = xml.Load(nameFileWithExpenses);

    if (fileExists == true)
    {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Expense") )
        {
            xml.IntoElem();
            xml.FindElem( "ExpenseId" );
            int expenseId = atoi( MCD_2PCSZ(xml.GetData()) );
            xml.FindElem( "UserId" );
            int userId = atoi( MCD_2PCSZ(xml.GetData()) );
            xml.FindElem( "Date" );
            int date = atoi( MCD_2PCSZ(xml.GetData()) );
            xml.FindElem( "Item" );
            MCD_STR item = xml.GetData();
            xml.FindElem( "Amount" );
            float amount = stof( MCD_2PCSZ(xml.GetData()) );
            xml.OutOfElem();
            expense = setExpenseData(expenseId, userId, date, item, amount);
            expenses.push_back(expense);
        }
    }
return expenses;
}

Expense FileWithExpenses::setExpenseData(int expenseId, int userId, int date, string item, float amount)
{
    Expense expense;

    expense.setExpenseId(expenseId);
    expense.setUserId(userId);
    expense.setDate(date);
    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
}
