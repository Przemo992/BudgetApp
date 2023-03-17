#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "User.h"
#include "Markup.h"

using namespace std;

class FileWithUsers
{
    CMarkup xml;
    string nameFileWithUsers;

    User setUserData(int userId, string userLogin, string userPassword);

public:
    FileWithUsers();
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();

};
