#ifndef FINANCALOPERATION_H
#define FINANCALOPERATION_H

#include <iostream>

using namespace std;

class FinancalOperation
{
protected:
    int date, id, userId;
    string item = "";
    float amount;

public:
    void setId(int id);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(float amount);

    int getId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};


#endif // FINANCALOPERATION_H
