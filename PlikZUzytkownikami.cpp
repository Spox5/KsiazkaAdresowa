#include "PlikZUzytkownikami.h"

vector <Uzytkownik> PlikZUzytkownikami::wczytaniePlikuZUzytkownikami()
{
    Uzytkownik uzytkownik;
    vector <Uzytkownik> uzytkownicy;
    fstream plikUzytkownicy;
    string liniaUzytkownicy;
    int licznikUzytkownicy = 0;

    plikUzytkownicy.open(NAZWA_PLIKU_Z_UZYTKOWNIKAMI.c_str(), ios::in);
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

void PlikZUzytkownikami::zapisanieUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
    fstream plikUzytkownicy;
    plikUzytkownicy.open(NAZWA_PLIKU_Z_UZYTKOWNIKAMI.c_str(), ios::app);
    if (plikUzytkownicy.good() == true)
    {
        plikUzytkownicy << uzytkownik.wypiszIdUzytkownika() << "|" << uzytkownik.wypiszNazweUzytkownika() << "|" << uzytkownik.wypiszHasloUzytkownika() << "|" << endl;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku " << NAZWA_PLIKU_Z_UZYTKOWNIKAMI << " i zapisac uzytkownika." << endl;
        system("pause");
    }
    plikUzytkownicy.close();
}

void PlikZUzytkownikami::zapisanieZmienionegoHaslaDoPliku(vector <Uzytkownik> uzytkownicy)
{
    fstream plikUzytkownicy;
    plikUzytkownicy.open(NAZWA_PLIKU_Z_UZYTKOWNIKAMI.c_str(), ios::out);
    for (int j = 0; j <= uzytkownicy.size()-1; j++)
    {
        plikUzytkownicy << uzytkownicy[j].wypiszIdUzytkownika() << "|" << uzytkownicy[j].wypiszNazweUzytkownika() << "|"
                        << uzytkownicy[j].wypiszHasloUzytkownika() << "|" << endl;
    }
    cout << "Haslo zostalo zmienione." << endl;
    system("pause");
    plikUzytkownicy.close();
}
