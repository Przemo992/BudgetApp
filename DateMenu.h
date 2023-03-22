#include <windows.h>
#include <winbase.h>

#include "HelpingMethods.h"

class DateMenu
{
    string presentDate;
    string firstDayPresentMonth;
    int maxDateToInput;
    bool isLeapYear(int year);

public:
    DateMenu();
    bool checkIsDateCorrect(string date);
    int setDate();
    string getPresentDate();
    string getFirstDayPresentMonth();
    int getPresentDay();
    int getPresentMonth();
    int getPresentYear();
    int daysOfMonth(int m1, int y1);
    int typeInDate();
};
