#ifndef FINANCALOPERATION_H
#define FINANCALOPERATION_H

#include<iomanip>
#include<algorithm>

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
    void setDate (int date);
    void setItem(string item);
    void setAmount(float amount);
    int getId();
    int getUserId();
    int getDate() const;
    string getItem();
    float getAmount();
    static bool comp( const FinancalOperation & l, const FinancalOperation & r );

};


#endif // FINANCALOPERATION_H
