#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <windows.h>

using namespace std;

struct Uzytkownik
{
    int idUzytkownika;
    string nazwaUzytkownika, hasloUzytkownika;
};

vector <Uzytkownik> rejestracjaUzytkownika (Uzytkownik uzytkownik, vector <Uzytkownik> uzytkownikVector)
{
    string nazwaUzytkownika, hasloUzytkownika;
    int idUzytkownika;
    cout << "Podaj nazwe uzytkownika: " << endl;
    cin >> nazwaUzytkownika;
    if (uzytkownikVector.size() != 0)
    {
        int i = 0;
        while (i <= uzytkownikVector.size())
        {
            if (nazwaUzytkownika == uzytkownikVector[i].nazwaUzytkownika)
            {
                cout << "Taki uzytkownik juz istnieje. Podaj inna nazwe uzytkownika" << endl;
                cin >> nazwaUzytkownika;
                i = 0;
            }
            else
            {
                i++;
            }
        }
    }
    cout << "Podaj haslo uzytkownika: " << endl;
    cin >> hasloUzytkownika;
    if (uzytkownikVector.size() == 0)
    {
        idUzytkownika = 1;
    }
    else
        idUzytkownika = uzytkownikVector[uzytkownikVector.size()-1].idUzytkownika + 1;
    uzytkownik.idUzytkownika = idUzytkownika;
    uzytkownik.nazwaUzytkownika = nazwaUzytkownika;
    uzytkownik.hasloUzytkownika = hasloUzytkownika;
    uzytkownikVector.push_back(uzytkownik);
    fstream plikUzytkownicy;
    plikUzytkownicy.open("Uzytkownicy.txt", ios::out | ios::app);
    plikUzytkownicy << idUzytkownika << "|" << nazwaUzytkownika << "|" << hasloUzytkownika << endl;
    cout << "Uzytkownik zostal dodany" << endl;
    system("pause");

    return uzytkownikVector;
}

int logowanieUzytkownika (Uzytkownik uzytkownik, vector <Uzytkownik> uzytkownikVector)
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
                    cout << "Zalogowales sie.";
                    system("pause");
                    return uzytkownikVector[i].idUzytkownika;
                }
                else
                    cout << "Nieprawidlowe haslo.";
            }
            cout << "Podales 3 razy bledne haslo. Odczekaj 3 sekundy.";
            Sleep(3000);
            return 0;
        }
        i++;
    }
    cout << "Nie ma uzytkownika o takiej nazwie." << endl;
    system ("pause");
    return 0;

}

void zmianaHaslaUzytkownika(Uzytkownik uzytkownik, vector <Uzytkownik> uzytkownikVector, int idZalogowanegoUzytkownika)
{
    string haslo;
    cout << "Podaj nowe haslo." << endl;
    cin >> haslo;
    for (int i = 0; i < uzytkownikVector.size(); i++)
    {
        if (idZalogowanegoUzytkownika == uzytkownikVector[i].idUzytkownika)
        {
            uzytkownikVector[i].hasloUzytkownika = haslo;
            cout << "Haslo zostalo zmienione." << endl;
            system("pause");
        }
    }
}

int main()
{
    Uzytkownik uzytkownik;
    vector <Uzytkownik> uzytkownikVector;
    int idZalogowanegoUzytkownika = 0;
    int liczbaUzytkownikow = 0;

    fstream plikUzytkownicy;
    plikUzytkownicy.open("Uzytkownicy.txt", ios::in | ios::out);
    if (plikUzytkownicy.good() == false)
    {
        cout << "Baza uzytkownikow jest pusta." << endl;
        system("pause");
        system("cls");
    }
    string linia;
    int licznik = 0;
    while (getline (plikUzytkownicy, linia, '|'))
    {
       licznik = licznik + 1;

        if (licznik == 1)
        {
            uzytkownik.idUzytkownika = atoi(linia.c_str());
        }
        else if (licznik == 2)
        {
            uzytkownik.nazwaUzytkownika = linia;
        }
        else if (licznik == 3)
        {
            uzytkownik.hasloUzytkownika = linia;
        }
        if (licznik == 3)
        {
            licznik = 0;
            uzytkownikVector.push_back(uzytkownik);
        }
    }

    char wybor;

    while (1)
    {
        system("cls");
        cout << "1. Logowanie." << endl;
        cout << "2. Rejestracja." << endl;
        cout << "3. Zmana hasla." << endl;
        cout << "9. Zamknij program" << endl;

        cin >> wybor;

        if (wybor == '1')
        {
            idZalogowanegoUzytkownika = logowanieUzytkownika(uzytkownik, uzytkownikVector);
        }
        else if (wybor == '2')
        {
            uzytkownikVector = rejestracjaUzytkownika(uzytkownik, uzytkownikVector);
        }
        else if (wybor == '3')
        {
            zmianaHaslaUzytkownika(uzytkownik, uzytkownikVector, idZalogowanegoUzytkownika);
        }
        else if (wybor == '9')
        {
            exit(0);
        }
        else
            cout << "Nieprawid³wy wybor";
            system("pause");
    }

    return 0;
}
