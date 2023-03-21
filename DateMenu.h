#include <iostream>
#include <windows.h>
#include <winbase.h>

#include "HelpingMethods.h"

using namespace std;

class DateMenu
{
    string presentDate;
    int maxDateToInput;
    bool isLeapYear(int year);
    int daysOfMonth(int m1, int y1);
    int getPresentDay();
    int getPresentMonth();
    int getPresentYear();

public:
    DateMenu();
    bool checkIsDateCorrect(string date);
    int setDate();
};
