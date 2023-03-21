#include "FinancalOperation.h"

void FinancalOperation::setDate(int date)
{
    if (date >= 20000101)
    {
        this->date = date;
    }
}
void FinancalOperation::setId(int id)
{
    this->id = id;
}
void FinancalOperation::setUserId(int userId)
{
    this->userId = userId;
}
void FinancalOperation::setItem(string item)
{
    this->item = item;
}
void FinancalOperation::setAmount(float amount)
{
    this->amount = amount;
}
int FinancalOperation::getId()
{
    return id;
}
int FinancalOperation::getUserId()
{
    return userId;
}
int FinancalOperation::getDate()
{
    return date;
}
string FinancalOperation::getItem()
{
    return item;
}
float FinancalOperation::getAmount()
{
    return amount;
}
