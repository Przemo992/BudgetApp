#ifndef XMLFILE_H
#define XMLFILE_H

#include "Markup.h"

using namespace std;

class XmlFile
{
protected:
    bool fileExists;
    const string NAME_FILE;
    CMarkup xml;

public:
    XmlFile(string fileName) :NAME_FILE(fileName) {};
    bool checkIsFileExist();
    string getFileName();
};

#endif // XMLFILE_H
