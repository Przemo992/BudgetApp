#include "HelpingMethods.h"

string HelpingMethods::changeCommaToDot(string number)
{
    string wanted=",";
    auto charPosition = number.find(wanted);
    if (charPosition!=string::npos){
        number.replace(charPosition,1,".");
    }
    return number;
}

string HelpingMethods::getLine()
{
    string line = "";
    cin.sync();
    getline(cin, line);
    return line;
}

string HelpingMethods::eraseDashFromDate(string date)
{
    string wanted="-";
    auto charPosition = date.find(wanted);
    while (charPosition!=string::npos)
    {
        date.erase(charPosition,1);
        charPosition = date.find(wanted);
    }
    return date;
}

string HelpingMethods::insertDashesToDate(string date)
{
    date.insert(4,"-");
    date.insert(7,"-");
    return date;
}

char HelpingMethods::getChar()
{
    string line = "";
    char cHar  = {0};
    cin.sync();
    while (true) {
        getline(cin, line);

        if (line.length() == 1) {
            cHar = line[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return cHar;
}
