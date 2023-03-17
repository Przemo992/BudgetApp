#include "Incomes.h"

void Income::setDate(int date)
{
    if (date >= 20000101)
    {
        this->date = date;
    }
}
void Income::setIncomeId(int incomeId)
{
    this->incomeId = incomeId;
}
void Income::setUserId(int userId)
{
    this->userId = userId;
}
void Income::setItem(string item)
{
    this->item = item;
}
void Income::setAmount(string amount)
{
    this->amount = amount;
}
int Income::getDate()
{
    return date;
}
string Income::getItem()
{
    return item;
}
string Income::getAmount()
{
    return amount;
}
