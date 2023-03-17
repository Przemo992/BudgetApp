#include <iostream>

using namespace std;

class Income
{
    int date, incomeId, userId;
    string item = "", amount = "";

public:
    void setIncomeId(int incomeId);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(string amount);

    int getDate();
    string getItem();
    string getAmount();
};
