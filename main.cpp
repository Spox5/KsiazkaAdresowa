#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <sstream>
#include <windows.h>
#include <cstdio>
#include "PlikZUzytkownikami.h"
#include "UzytkownikMaster.h"
#include "Uzytkownik.h"
#include "PlikZAdresatami.h"
#include "AdresatMaster.h"
#include "Adresat.h"

using namespace std;

void wyszukajAdresataPoImieniu (vector <Adresat> adresaci);
void wyszukajAdresataPoNazwisku (vector <Adresat> adresaci);
void nadpisaniePlikuEdycjaAdresata (int idEdytowanegoAdresata, Adresat adresat, int idZalogowanegoUzytkownika);
vector <Adresat> edycjaAdresata (Adresat adresat, vector<Adresat> adresaci, int idZalogowanegoUzytkownika);
void nadpisaniePlikuUsuniecieAdresata (int idEdytowanegoAdresata, int idZalogowanegoUzytkownika);
vector <Adresat> usuniecieAdresata (vector<Adresat> adresaci, int idZalogowanegoUzytkownika);

int main()
{
    PlikZUzytkownikami plikZUzytkownikami;
    UzytkownikMaster uzytkownikMaster;
    vector <Uzytkownik> uzytkownicy;

    uzytkownicy = plikZUzytkownikami.wczytaniePlikuZUzytkownikami();

    while (1)
    {
        char wyborUzytkownicy = uzytkownikMaster.menuUzytkownicyWybor();
        uzytkownicy = uzytkownikMaster.menuUzytkownicy(wyborUzytkownicy, uzytkownicy);
    }
    return 0;
}

void wyszukajAdresataPoImieniu (vector <Adresat> adresaci)
{
    system("cls");
    string imie;
    bool licznikImion = false;

    system("cls");
    if (adresaci.size() == 0)
    {
        cout << "Baza danych jest pusta" << endl;
        system("pause");
    }
    else
    {
        cout << "Wpisz imie:" << endl;
        cin >> imie;
        for (int i = 0; i <= adresaci.size(); i++)
        {
            if (imie == adresaci[i].wypiszImieAdresata())
            {
                licznikImion = true;
                cout << adresaci[i].wypiszImieAdresata() << " ";
                cout << adresaci[i].wypiszNazwiskoAdresata() << ", ";
                cout << adresaci[i].wypiszNrTelefonuAdresata() << ", ";
                cout << adresaci[i].wypiszEmailAdresata() << ", ";
                cout << adresaci[i].wypiszAdresAdresata() << "." << endl;
            }
        }
        if (licznikImion == false)
        {
            cout << "W bazie nie ma osoby o takim imieniu";
        }
        cout << endl;
        system("pause");
    }
}

void wyszukajAdresataPoNazwisku (vector <Adresat> adresaci)
{
    string nazwisko;
    bool licznikNazwisk = false;

    system("cls");
    if (adresaci.size() == 0)
    {
        cout << "Baza danych jest pusta" << endl;
        system("pause");
    }
    else
    {
        cout << "Wpisz nazwisko:" << endl;
        cin >> nazwisko;
        for (int i = 0; i <= adresaci.size(); i++)
        {
            if (nazwisko == adresaci[i].wypiszNazwiskoAdresata())
            {
                licznikNazwisk = true;
                cout << adresaci[i].wypiszImieAdresata() << " ";
                cout << adresaci[i].wypiszNazwiskoAdresata() << ", ";
                cout << adresaci[i].wypiszNrTelefonuAdresata() << ", ";
                cout << adresaci[i].wypiszEmailAdresata() << ", ";
                cout << adresaci[i].wypiszAdresAdresata() << "." << endl;
            }
        }
        if (licznikNazwisk == false)
        {
            cout << "W bazie nie ma osoby o takim nazwisku.";
        }
        cout << endl;
        system("pause");
    }
}

void nadpisaniePlikuEdycjaAdresata (int idEdytowanegoAdresata, Adresat adresat, int idZalogowanegoUzytkownika)
{
    fstream plik;
    fstream plikAdresaciTymczasowy;
    string linia;
    string idStringEdytowanegoAdresata;
    string idStringZalogowanegoUzytkownika;

    plik.open("Adresaci.txt", ios::in | ios::out);
    plikAdresaciTymczasowy.open("Adresaci_tymczasowy.txt", ios::in | ios::app);
    while(getline(plik, linia))
    {
        idStringEdytowanegoAdresata = linia[0];
        idStringZalogowanegoUzytkownika = linia[2];
        if (idEdytowanegoAdresata == atoi(idStringEdytowanegoAdresata.c_str()) && idZalogowanegoUzytkownika == atoi(idStringZalogowanegoUzytkownika.c_str()))
        {
            plikAdresaciTymczasowy << adresat.wypiszIdAdresata() << "|" << idZalogowanegoUzytkownika << "|" <<  adresat.wypiszImieAdresata() << "|"
                                   << adresat.wypiszNazwiskoAdresata() << "|" << adresat.wypiszNrTelefonuAdresata() << "|" << adresat.wypiszEmailAdresata() << "|"
                                   << adresat.wypiszAdresAdresata() << "|" << endl;
        }
        else
        {
            plikAdresaciTymczasowy << linia << endl;
        }
    }
    plik.close();
    plikAdresaciTymczasowy.close();
    remove("Adresaci.txt");
    rename ("Adresaci_tymczasowy.txt", "Adresaci.txt");
}

vector <Adresat> edycjaAdresata (Adresat adresat, vector<Adresat> adresaci, int idZalogowanegoUzytkownika)
{
    string idEdytowanegoAdresataString;
    string wybor;
    string imie;
    string nazwisko;
    string nrTelefonu;
    string email;
    string adres;
    ofstream plik;
    bool znalezionoID = false;

    if (adresaci.size() == 0)
    {
        system("cls");
        cout << "Baza danych jest pusta." << endl;
        system("pause");
    }
    else
    {
        cout << "Podaj ID adresata, ktorego chcesz edytowac: ";
        cin >> idEdytowanegoAdresataString;
        int idEdytowanegoAdresata = atoi(idEdytowanegoAdresataString.c_str());
        for (int i = 0; i <= adresaci.size()-1; i++)
        {
            if (idEdytowanegoAdresata == adresaci[i].wypiszIdAdresata())
            {
                adresat.ustawIdAdresata(idEdytowanegoAdresata);
                adresat.ustawImieAdresata(adresaci[i].wypiszImieAdresata());
                adresat.ustawNazwiskoAdresata(adresaci[i].wypiszNazwiskoAdresata());
                adresat.ustawNrTelefonuAdresata(adresaci[i].wypiszNrTelefonuAdresata());
                adresat.ustawEmailAdresata(adresaci[i].wypiszEmailAdresata());
                adresat.ustawAdresAdresata(adresaci[i].wypiszAdresAdresata());
                znalezionoID = true;
                system("cls");
                cout << "1 - imie" << endl;
                cout << "2 - nazwisko" << endl;
                cout << "3 - numer telefonu" << endl;
                cout << "4 - email" << endl;
                cout << "5 - adres" << endl;
                cout << "6 - powrot do menu" << endl;
                cin >> wybor;
                if (wybor == "1")
                {
                    cout << "Podaj nowe imie: ";
                    cin >> imie;
                    adresaci[i].ustawImieAdresata(imie);
                }
                else if (wybor == "2")
                {
                    cout << "Podaj nowe nazwisko: ";
                    cin >> nazwisko;
                    adresaci[i].ustawNazwiskoAdresata(nazwisko);
                }
                else if (wybor == "3")
                {
                    cout << "Podaj nowy numer telefonu: ";
                    cin >> nrTelefonu;
                    adresaci[i].ustawNrTelefonuAdresata(nrTelefonu);
                }
                else if (wybor == "4")
                {
                    cout << "Podaj nowy email: ";
                    cin >> email;
                    adresaci[i].ustawEmailAdresata(email);
                }
                else if (wybor == "5")
                {
                    cout << "Podaj nowy adres: ";
                    cin.sync();
                    getline(cin>>ws, adres);
                    adresaci[i].ustawAdresAdresata(adres);
                }

                else if (wybor == "6")
                {
                    break;
                }
                else
                {
                    cout << "Nieprawidlowy wybor." << endl;
                    system("pause");
                }
                plik.close();
                nadpisaniePlikuEdycjaAdresata(idEdytowanegoAdresata, adresat, idZalogowanegoUzytkownika);
            }
        }
        if (znalezionoID == false)
        {
            cout << "Nieprawidlowe ID" << endl;
            system("pause");
        }
    }
    return adresaci;
}

void nadpisaniePlikuUsuniecieAdresata (int idEdytowanegoAdresata, int idZalogowanegoUzytkownika)
{
    fstream plik;
    fstream plikAdresaciTymczasowy;
    string linia;
    string idStringUsuwanegoAdresata;
    string idStringZalogowanegoUzytkownika;

    plik.open("Adresaci.txt", ios::in | ios::out);
    plikAdresaciTymczasowy.open("Adresaci_tymczasowy.txt", ios::in | ios::app);
    while(getline(plik, linia))
    {
        idStringUsuwanegoAdresata = linia[0];
        idStringZalogowanegoUzytkownika = linia[2];
        if (idEdytowanegoAdresata == atoi(idStringUsuwanegoAdresata.c_str()) && idZalogowanegoUzytkownika == atoi(idStringZalogowanegoUzytkownika.c_str()));
        else
        {
            plikAdresaciTymczasowy << linia << endl;
        }
    }
    plik.close();
    plikAdresaciTymczasowy.close();
    remove("Adresaci.txt");
    rename ("Adresaci_tymczasowy.txt", "Adresaci.txt");
}

vector <Adresat> usuniecieAdresata (vector<Adresat> adresaci, int idZalogowanegoUzytkownika)
{
    ofstream plik;
    string idString;
    string wybor;
    bool znalezionoID = false;
    int i = 0;

    if (adresaci.size() == 0)
    {
        system("cls");
        cout << "Baza danych jest pusta";
        cout << endl;
        system("pause");
    }
    else
    {
        cout << "Podaj ID adresata, ktorego chcesz usunac: ";
        cin >> idString;
        int idUsuwanegoAdresata = atoi(idString.c_str());
        for (vector<Adresat>::iterator it = adresaci.begin(), koniec = adresaci.end(); it != koniec; it++)
        {
            if (idUsuwanegoAdresata == adresaci[i].wypiszIdAdresata())
            {
                znalezionoID = true;
                system("cls");
                cout << "Czy na pewno chcesz usunac adresata? (t/n)" << endl;
                cin >> wybor;
                if (wybor == "t")
                {
                    adresaci.erase(it);
                }
                else
                {
                    break;
                }
                plik.close();
                nadpisaniePlikuUsuniecieAdresata(idUsuwanegoAdresata, idZalogowanegoUzytkownika);
            }
            i ++;
        }
        if (znalezionoID == false)
        {
            cout << "Nieprawidlowe ID" << endl;
            system("pause");
        }
    }
    return adresaci;
}
