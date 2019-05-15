#include "PlikZUzytkownikami.h"

Uzytkownik PlikZUzytkownikami::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    Uzytkownik uzytkownik;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
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
                uzytkownik.ustawIdUzytkownika(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustawNazweUzytkownika(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.ustawHasloUzytkownika(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}

vector <Uzytkownik> PlikZUzytkownikami::wczytaniePlikuZUzytkownikami()
{
    Uzytkownik uzytkownik;
    vector <Uzytkownik> uzytkownicy;
    fstream plikUzytkownicy;
    string linia;
    int licznikUzytkownicy = 0;

    plikUzytkownicy.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::in);

    if (plikUzytkownicy.good() == true)
    {
        while (getline(plikUzytkownicy, linia))
        {
            uzytkownik = pobierzDaneUzytkownika(linia);
            uzytkownicy.push_back(uzytkownik);
        }
        plikUzytkownicy.close();
    }
    else
    {
        cout << "Baza uzytkownikow jest pusta." << endl;
        system("pause");
        system("cls");
    }

    return uzytkownicy;
}

void PlikZUzytkownikami::zapisanieUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
    fstream plikUzytkownicy;
    plikUzytkownicy.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::app);
    if (plikUzytkownicy.good() == true)
    {
        plikUzytkownicy << uzytkownik.wypiszIdUzytkownika() << "|" << uzytkownik.wypiszNazweUzytkownika() << "|" << uzytkownik.wypiszHasloUzytkownika() << "|" << endl;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku " << PlikTekstowy::pobierzNazwePliku().c_str() << " i zapisac uzytkownika." << endl;
        system("pause");
    }
    plikUzytkownicy.close();
}

void PlikZUzytkownikami::zapisanieZmienionegoHaslaDoPliku(vector <Uzytkownik> uzytkownicy)
{
    fstream plikUzytkownicy;
    plikUzytkownicy.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::out);
    for (int j = 0; j <= uzytkownicy.size()-1; j++)
    {
        plikUzytkownicy << uzytkownicy[j].wypiszIdUzytkownika() << "|" << uzytkownicy[j].wypiszNazweUzytkownika() << "|"
                        << uzytkownicy[j].wypiszHasloUzytkownika() << "|" << endl;
    }
    cout << "Haslo zostalo zmienione." << endl;
    system("pause");
    plikUzytkownicy.close();
}

void PlikZUzytkownikami::dopisz(string tekst)
    {
        fstream plikTekstowy;
        plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

        if (plikTekstowy.good() == true)
        {
            if (czyPlikJestPusty())
                plikTekstowy << "To jest poczatek pliku" << endl;
            plikTekstowy << tekst << endl;
        }

        plikTekstowy.close();
    }
