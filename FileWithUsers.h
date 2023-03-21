#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "User.h"
#include "XmlFile.h"
#include "Markup.h"

using namespace std;

class FileWithUsers :public XmlFile
{
    CMarkup xml;

    User setUserData(int userId, string userLogin, string userPassword);

public:
    FileWithUsers(string fileName)
    : XmlFile(fileName){};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void changePassword(int loggedUserId, string newPassword);

};
