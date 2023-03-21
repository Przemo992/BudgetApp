#include "FileWithIncomes.h"

void FileWithIncomes::addIncomeToFile(Income income)
{

    if (!checkIsFileExist())
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", to_string(income.getId()));
    xml.AddElem("UserId", to_string(income.getUserId()));
    xml.AddElem("Date", to_string(income.getDate()));
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", to_string(income.getAmount()));

    xml.Save(getFileName());
}

vector <Income> FileWithIncomes::loadIncomesFromFile(int idLoggedUser)
{
    Income income;
    vector <Income> incomes;
    CMarkup xml;
    xml.Load(getFileName());

    if (checkIsFileExist() == true)
    {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Income") )
        {
            xml.IntoElem();
            xml.FindElem( "IncomeId" );
            int incomeId = atoi( MCD_2PCSZ(xml.GetData()) );
            xml.FindElem( "UserId" );
            int userId = atoi( MCD_2PCSZ(xml.GetData()) );
            xml.FindElem( "Date" );
            int date = atoi( MCD_2PCSZ(xml.GetData()) );
            xml.FindElem( "Item" );
            MCD_STR item = xml.GetData();
            xml.FindElem( "Amount" );
            float amount = stof( MCD_2PCSZ(xml.GetData()) );
            xml.OutOfElem();
            if(userId == idLoggedUser)
            {
                income = setIncomeData(incomeId, userId, date, item, amount);
                incomes.push_back(income);
            }
        }
    }
    return incomes;
}

Income FileWithIncomes::setIncomeData(int incomeId, int userId, int date, string item, float amount)
{
    Income income;

    income.setId(incomeId);
    income.setUserId(userId);
    income.setDate(date);
    income.setItem(item);
    income.setAmount(amount);

    return income;
}

int FileWithIncomes::getLastIncomeId()
{
    int id = 0;

       CMarkup xml;

    xml.Load(getFileName());


    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Income")  )
    {
        xml.IntoElem();
        xml.FindElem( "IncomeId" );
        int expenseId = atoi( MCD_2PCSZ(xml.GetData()) );
        if (expenseId > id) id = expenseId;
        xml.OutOfElem();
    }
    return id;
}
