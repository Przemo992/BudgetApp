#include "FileWithUsers.h"

FileWithUsers::FileWithUsers()
{
    nameFileWithUsers = "users.xml";
}

void FileWithUsers::addUserToFile(User user)
{

    bool fileExists = xml.Load( nameFileWithUsers );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", to_string(user.getId()));
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save(nameFileWithUsers);
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    User user;
    vector <User> users;
    CMarkup xml;
    bool fileExists = xml.Load(nameFileWithUsers);

    if (fileExists == true)
    {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("User") )
        {
            xml.IntoElem();
            xml.FindElem( "UserId" );
            int userId = atoi( MCD_2PCSZ(xml.GetData()) );
            xml.FindElem( "Login" );
            MCD_STR userLogin = xml.GetData();
            xml.FindElem( "Password" );
            MCD_STR userPassword = xml.GetData();
            xml.OutOfElem();
            user = setUserData(userId, userLogin, userPassword);
            users.push_back(user);
        }
    }
return users;
}

User FileWithUsers::setUserData(int userId, string userLogin, string userPassword)
{
    User user;
    user.setId(userId);
    user.setLogin(userLogin);
    user.setPassword(userPassword);
    return user;
}


/*
vector <Uzytkownik> PlikZUzytkownikami::wczytajUzytkownikowZPliku()
{
    Uzytkownik uzytkownik;
    vector <Uzytkownik> uzytkownicy;
    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";
    fstream plikTekstowy;

    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami))
        {
            uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            uzytkownicy.push_back(uzytkownik);
        }
           plikTekstowy.close();

    }
 return uzytkownicy;
}

Uzytkownik PlikZUzytkownikami::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    Uzytkownik uzytkownik;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (unsigned int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejUzytkownika)
            {
            case 1:
                uzytkownik.ustawId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustawLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.ustawHaslo(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}*/
