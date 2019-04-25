#include "PlikZUzytkownikami.h"

vector <Uzytkownik> PlikZUzytkownikami::wczytaniePlikuZUzytkownikami()
{
    Uzytkownik uzytkownik;
    fstream plikUzytkownicy;
    vector <Uzytkownik> uzytkownicy;
    string liniaUzytkownicy;
    int licznikUzytkownicy = 0;

    plikUzytkownicy.open("Uzytkownicy.txt", ios::in | ios::out);
    if (plikUzytkownicy.good() == false)
    {
        cout << "Baza uzytkownikow jest pusta." << endl;
        system("pause");
        system("cls");
    }

    while (getline (plikUzytkownicy, liniaUzytkownicy, '|'))
    {
        licznikUzytkownicy = licznikUzytkownicy + 1;

        if (licznikUzytkownicy == 1)
        {
            uzytkownik.ustawIdUzytkownika(atoi(liniaUzytkownicy.c_str()));
        }
        else if (licznikUzytkownicy == 2)
        {
            uzytkownik.ustawNazweUzytkownika(liniaUzytkownicy);
        }
        else if (licznikUzytkownicy == 3)
        {
            uzytkownik.ustawHasloUzytkownika(liniaUzytkownicy);
        }
        if (licznikUzytkownicy == 3)
        {
            licznikUzytkownicy = 0;
            uzytkownicy.push_back(uzytkownik);
        }
    }
    plikUzytkownicy.close();

    return uzytkownicy;
}
