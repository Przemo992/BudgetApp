#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>

using namespace std;

class Expense
{
    int date, expenseId, userId;
    string item = "";
    float amount;

public:
    void setExpenseId(int expenseId);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(float amount);

    int getExpenseId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};

#endif // EXPENSES_H
