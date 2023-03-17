#include "Expenses.h"

void Expense::setDate(int date)
{
    if (date >= 20000101)
    {
        this->date = date;
    }
}
void Expense::setExpenseId(int expenseId)
{
    this->expenseId = expenseId;
}
void Expense::setUserId(int userId)
{
    this->userId = userId;
}
void Expense::setItem(string item)
{
    this->item = item;
}
void Expense::setAmount(float amount)
{
    this->amount = amount;
}
int Expense::getExpenseId()
{
    return expenseId;
}
int Expense::getUserId()
{
    return userId;
}
int Expense::getDate()
{
    return date;
}
string Expense::getItem()
{
    return item;
}
float Expense::getAmount()
{
    return amount;
}
