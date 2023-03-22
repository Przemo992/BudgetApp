#ifndef HELPINGMETHODS_H
#define HELPINGMETHODS_H

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class HelpingMethods
{

public:
    static string changeCommaToDot(string number);
    static string getLine();
    static string eraseDashFromDate(string date);
    static string insertDashesToDate(string date);
    static char getChar();
    static string typeInFloatNumber();
};

#endif // HELPINGMETHODS_H
