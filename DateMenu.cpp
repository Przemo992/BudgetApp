#include "DateMenu.h"

DateMenu::DateMenu()
{
    string year = to_string(getPresentYear());
    string month = to_string(getPresentMonth());
    string day = to_string(getPresentDay());

    if(month.length() < 2) month = "0" + month;

    if(day.length() < 2) day = "0" + day;
    presentDate = year + month + day;

    string maxDay = to_string(daysOfMonth(stoi(month), stoi(year)));

    maxDateToInput = stoi(year + month + maxDay);
    firstDayPresentMonth = year + month + "01";
}

string DateMenu::getPresentDate()
{
    return presentDate;
}

string DateMenu::getFirstDayPresentMonth()
{
    return firstDayPresentMonth;
}

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
    if (date.length()<10)
    {
        cout << "Podano bledna date, wprowadz jeszcze raz!\n";
        return false;
    }

    int year = stoi(date.substr(0,4));
    int month = stoi(date.substr(5,2));
    int day = stoi(date.substr(8,2));
    int presentDate = stoi(HelpingMethods::eraseDashFromDate(date));
    int monthDays = daysOfMonth(month, year);

    if((year > 2000) && (month>=1) && (month <= 12) && (day > 0) && (day <= monthDays) && (presentDate <= maxDateToInput))
    {
        return true;
    }
    else
    {
        cout << "\nPodano bledna date, wprowadz jeszcze raz!\n";
        return false;
    }
}

int DateMenu::setDate()
{
    char choose;

    int intDate = 0;

    system("cls");
    cout << "Z JAKA DATA CHCESZ WPROWADZIC OPERACJE?\n\n";
    cout << "1. Data dzisiejsza\n";
    cout << "2. Inna data\n";
    choose = HelpingMethods::getChar();

    switch(choose)
    {
    case '1' :
    {
        intDate = stoi(presentDate);
        break;
    }
    case '2' :
    {
        cout << "Podaj date wydatku w formacie yyyy-mm-dd\n";
        intDate = typeInDate();
        cout << endl;
        break;
    }
    default :
    {
        cout << "Nie ma takiej opcji!\n";
        break;
    }

    }
    return intDate;
}

int DateMenu::typeInDate()
{
    constexpr char c_enter  = 13;
    constexpr char c_backspace = 8;

    string date = "";

    char input_character;


    do
    {
        date = "";
            input_character = getch();
        while(input_character != c_enter)
        {
            if(input_character == c_backspace && date.size())
            {
                if (date.length() == 5 || date.length() == 8 )
                {
                    cout << "\b \b \b";
                    date.pop_back();
                }
                cout << "\b \b";
                date.pop_back();
            }

            else if((input_character != c_backspace && input_character >= 48 && input_character <= 57))
            {
                cout << input_character;
                date += input_character;
            }
            if ((date.length() == 4) || (date.length() == 7))
            {
                cout << "-";
                date += "-";
            }

            input_character = getch();
        }
    }
    while (checkIsDateCorrect(date) == false);
    return stoi(HelpingMethods::eraseDashFromDate(date));
}



