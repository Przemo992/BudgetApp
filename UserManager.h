#ifndef USERMANAGER_H
#define USERMANAGER_H


#include <iostream>
#include <vector>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
        FileWithUsers fileWithUsers;
    int idLoggedUser;
    vector <User> users;

    bool isExistLogin(string login);
    User typeInNewUserData();

public:
    UserManager();
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
