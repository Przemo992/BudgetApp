#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include <conio.h>

#include "User.h"
#include "FileWithUsers.h"

class UserManager
{
    FileWithUsers fileWithUsers;
    int idLoggedUser;
    vector <User> users;
    bool isExistLogin(string login);
    User typeInNewUserData();
    string hidingPassword();

public:
    UserManager(string fileName)
        :fileWithUsers(fileName)
    {
        users = fileWithUsers.loadUsersFromFile();
        idLoggedUser = 0;
    };
    void userRegister();
    void userLoggingIn();
    void changeLoggedUserPassword();
    int getIdNewUser();
    void setIdLoggedUser(int idLoggedUser);
    bool isUserLogged();
    int getIdLoggedUser();
    void displayAllUsers();
    void displayUserData(User user);
};

#endif // USERMANAGER_H
