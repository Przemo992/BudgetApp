#include "HelpingMethods.h"

string HelpingMethods::changeCommaToDot(string number)
{
    string wanted=",";
    auto charPosition = number.find(wanted);

    if (charPosition!=string::npos)
    {
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

string HelpingMethods::typeInFloatNumber()
{
    constexpr char c_enter  = 13;
    constexpr char c_backspace = 8;

    string floatStr;
    char input_character;

    input_character = getch();

    while(input_character != c_enter) {

        if(input_character == c_backspace && floatStr.size()) {
            cout << "\b \b";
            floatStr.pop_back();
        } else if((input_character != c_backspace && input_character >= 48 && input_character <= 57) || (input_character == 44) || (input_character == 46)) {
            cout << input_character;
            floatStr += input_character;
        }
        input_character = getch();
    }
    return floatStr;
}
