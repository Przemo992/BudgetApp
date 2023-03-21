#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Incomes.h"
#include "XmlFile.h"
#include "Markup.h"

using namespace std;

class FileWithIncomes :public XmlFile
{


    Income setIncomeData(int incomeId, int userId, int date, string item, float amount);

public:
    FileWithIncomes(string fileName)
    : XmlFile(fileName){};
    void addIncomeToFile(Income income);
    vector <Income> loadIncomesFromFile(int idLoggedUser);
    int getLastIncomeId();

};
