#include <iostream>
#include <windows.h>
#include <winbase.h>

using namespace std;

class DateMenu
{
    static bool isLeapYear(int year);
   static int daysOfMonth(int m1, int y1);
    int getPresentDay();
    int getPresentMonth();
    int getPresentYear();
public:
    static bool checkIsDateCorrect(string date);

};
