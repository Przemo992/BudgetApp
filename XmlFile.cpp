#include "XmlFile.h"

bool XmlFile::checkIsFileExist()
{
    fileExists = xml.Load( getFileName() );
    if (!fileExists) return false;
    else return true;
}

string XmlFile::getFileName()
{
    return NAME_FILE;
}
