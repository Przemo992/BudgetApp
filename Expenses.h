#include <iostream>

using namespace std;

class Expense
{
    int date, expenseId, userId;
    string item = "", amount = "";

public:
    void setExpenseId(int expenseId);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(string amount);

    int getDate();
    string getItem();
    string getAmount();
};
