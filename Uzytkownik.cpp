#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include "Uzytkownik.h"

using namespace std;

vector <Uzytkownik> Uzytkownik::rejestracjaUzytkownika (Uzytkownik uzytkownik, vector <Uzytkownik> uzytkownikVector)
{
    string nazwaUzytkownika, hasloUzytkownika;
    int idUzytkownika;
    cout << "Podaj nazwe uzytkownika: " << endl;
    cin >> uzytkownik.nazwaUzytkownika;
    if (uzytkownikVector.size() != 0)
    {
        int i = 0;
        while (i <= uzytkownikVector.size())
        {
            if (uzytkownik.nazwaUzytkownika == uzytkownikVector[i].nazwaUzytkownika)
            {
                cout << "Taki uzytkownik juz istnieje. Podaj inna nazwe uzytkownika" << endl;
                cin >> uzytkownik.nazwaUzytkownika;
                i = 0;
            }
            else
                i++;
        }
    }
    cout << "Podaj haslo uzytkownika: " << endl;
    cin >> uzytkownik.hasloUzytkownika;
    if (uzytkownikVector.size() == 0)
    {
        uzytkownik.idUzytkownika = 1;
    }
    else
        uzytkownik.idUzytkownika = uzytkownikVector.size() + 1;
    uzytkownikVector.push_back(uzytkownik);
    fstream plikUzytkownicy;
    plikUzytkownicy.open("Uzytkownicy.txt", ios::out | ios::app);
    plikUzytkownicy << uzytkownik.idUzytkownika << "|" << uzytkownik.nazwaUzytkownika << "|" << uzytkownik.hasloUzytkownika << "|" << endl;
    cout << "Uzytkownik zostal dodany" << endl;
    system("pause");

    return uzytkownikVector;
}

int Uzytkownik::logowanieUzytkownika (vector <Uzytkownik> uzytkownikVector)
{
    string nazwaUzytkownika, hasloUzytkownika;
    cout << "Podaj nazwe uzytkownika: " << endl;
    cin >> nazwaUzytkownika;
    int i = 0;
    while (i < uzytkownikVector.size())
    {
        if (nazwaUzytkownika == uzytkownikVector[i].nazwaUzytkownika)
        {
            for (int proby = 0; proby < 3; proby++)
            {
                cout << "Podaj haslo. Pozostalo prob: " << 3 -  proby << endl;
                cin >> hasloUzytkownika;
                if (hasloUzytkownika == uzytkownikVector[i].hasloUzytkownika)
                {
                    cout << "Zalogowales sie." << endl;
                    system("pause");
                    system("cls");
                    return uzytkownikVector[i].idUzytkownika;
                }
                else
                    cout << "Nieprawidlowe haslo." << endl;;
            }
            cout << "Podales 3 razy bledne haslo. Odczekaj 3 sekundy." << endl;;
            Sleep(3000);
            return 0;
        }
        i++;
    }
    cout << "Nie ma uzytkownika o takiej nazwie." << endl;
    system ("pause");
    return 0;
}
