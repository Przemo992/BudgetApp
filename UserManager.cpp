#include "UserManager.h"

int UserManager::getIdLoggedUser()
{
    return idLoggedUser;
}

void UserManager::setIdLoggedUser(int idLoggedUser)
{
    this->idLoggedUser = idLoggedUser;
}

int UserManager::getIdNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isExistLogin(string login)
{
    for (unsigned int i = 0; i < users.size(); i++)
    {
        if(users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }

    }
    return false;
}

void UserManager::userRegister()
{
    User user = typeInNewUserData();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);
    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::typeInNewUserData()
{
    User user;

    user.setId(getIdNewUser());

    string login;
    do
    {
        cout << endl << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    }
    while (isExistLogin(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    //password = MetodyPomocnicze::zakrywanieHasla();
    user.setPassword(password);

    return user;
}

void UserManager::userLoggingIn()
{
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    cin >> login;

    for (unsigned int i = 0; i < users.size(); i++)
    {
        if(users[i].getLogin() == login)
        {
            for (int numberOfattempts = 3; numberOfattempts > 0; numberOfattempts--)
            {
                cout << endl << "Podaj haslo. Pozostalo prob: " << numberOfattempts << ": ";
                    cin >> password;
                    //haslo = MetodyPomocnicze::zakrywanieHasla();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    idLoggedUser = users[i].getId();
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }

    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UserManager::changeLoggedUserPassword()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    cin >> newPassword;

    for (unsigned int i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == idLoggedUser)
        {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.changePassword(idLoggedUser, newPassword);
    //plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

bool UserManager::isUserLogged()
{
    if (idLoggedUser > 0)
        return true;
    else
        return false;
}

void UserManager::displayAllUsers()
{
    system("cls");
    if (!users.empty())
    {
        cout << "             >>> UZYTKOWNICY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <User> :: iterator itr = users.begin(); itr != users.end(); itr++)
        {
            displayUserData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Brak Uzytkownikow." << endl << endl;
    }
    system("pause");
}

void UserManager::displayUserData(User user)
{
    cout << endl << "Id:                 " << user.getId() << endl;
    cout << "Imie:               " << user.getLogin() << endl;
    cout << "Nazwisko:           " << user.getPassword() << endl;
}
