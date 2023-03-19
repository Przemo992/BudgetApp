#include "DateMenu.h"



bool DateMenu::isLeapYear(int year)
{
	if((year%4==0 && year%100!=0) || year%400==0)
		return true;
	else
		return false;
}

int DateMenu::daysOfMonth(int m1, int y1)
{
    int month;
    switch(m1)
    {
    case 1:
        month = 31;
        break;
    case 2:
        if (isLeapYear(y1) == true)
            month = 29;
        else month =  28;
        break;
    case 3:
        month =  31;
        break;
    case 4:
        month =  30;
        break;
    case 5:
        month =  31;
        break;
    case 6:
        month =  30;
        break;
    case 7:
        month =  31;
        break;
    case 8:
        month =  31;
        break;
    case 9:
        month =  30;
        break;
    case 10:
        month =  31;
        break;
    case 11:
        month =  30;
        break;
    case 12:
        month =  31;
        break;
    }
    return month;
}
int DateMenu::getPresentDay()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    return st.wDay;
}
int DateMenu::getPresentMonth()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    return st.wMonth;
}
int DateMenu::getPresentYear()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    return st.wYear;
}

bool DateMenu::checkIsDateCorrect(string date)
{
    //yyyy-mm-dd
    int year = stoi(date.substr(0,4));
    int month = stoi(date.substr(5,2));
    int day = stoi(date.substr(8,2));

    int monthDays = daysOfMonth(month, year);
    if((year > 2000) && (month>=1) && (month <= 12) && (day >= 0) && (day <= monthDays))
    {
        return true;
    }
    else
    {
        cout << "Podano bledna date!"<<endl;
        return false;
    }
}
