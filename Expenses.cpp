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
void Expense::setAmount(string amount)
{
    this->amount = amount;
}
int Expense::getDate()
{
    return date;
}
string Expense::getItem()
{
    return item;
}
string Expense::getAmount()
{
    return amount;
}
