#include "PlikZUzytkownikami.h"

vector <Uzytkownik> PlikZUzytkownikami::wczytaniePlikuZUzytkownikami()
{
    Uzytkownik uzytkownik;
    vector <Uzytkownik> uzytkownicy;
    fstream plikUzytkownicy;
    string liniaUzytkownicy;
    int licznikUzytkownicy = 0;

    plikUzytkownicy.open(nazwaPlikuZUzytkownikami.c_str(), ios::in);
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
    plikUzytkownicy.open(nazwaPlikuZUzytkownikami.c_str(), ios::app);
    if (plikUzytkownicy.good() == true)
    {
        plikUzytkownicy << uzytkownik.wypiszIdUzytkownika() << "|" << uzytkownik.wypiszNazweUzytkownika() << "|" << uzytkownik.wypiszHasloUzytkownika() << "|" << endl;
    cout << "Uzytkownik zostal dodany" << endl;
    system("pause");
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZUzytkownikami << " i zapisac uzytkownika." << endl;
        system("pause");
    }
    plikUzytkownicy.close();
}

/*string PlikZUzytkownikami::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
    string liniaZDanymiUzytkownika = "";


    liniaZDanymiUzytkownika += PlikZUzytkownikami::konwerjsaIntNaString(uzytkownik.wypiszIdUzytkownika())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.wypiszNazweUzytkownika() + '|';
    liniaZDanymiUzytkownika += uzytkownik.wypiszHasloUzytkownika() + '|';

    return liniaZDanymiUzytkownika;
}

string PlikZUzytkownikami::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}*/
