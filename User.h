#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int id;
    string login="", password="";

public:
    void setId(int id);
    void setLogin(string login);
    void setPassword(string password);

    int getId();
    string getLogin();
    string getPassword();
};

#endif // USER_H
