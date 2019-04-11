#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <sstream>
#include <windows.h>
#include <cstdio>

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

int logowanieUzytkownika (vector <Uzytkownik> uzytkownikVector)
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

vector <Uzytkownik> zmianaHaslaUzytkownika(vector <Uzytkownik> uzytkownikVector, int idZalogowanegoUzytkownika)
{
    ofstream plikUzytkownicy;
    string noweHaslo;
    cout << "Podaj nowe haslo:" << endl;
    cin >> noweHaslo;
    for (int i = 0; i < uzytkownikVector.size(); i++)
    {
        if (idZalogowanegoUzytkownika == uzytkownikVector[i].idUzytkownika)
        {
            uzytkownikVector[i].hasloUzytkownika = noweHaslo;
            plikUzytkownicy.close();
            plikUzytkownicy.open("Uzytkownicy.txt");
            for (int i = 0; i <= uzytkownikVector.size()-1; i++)
            {
                plikUzytkownicy << uzytkownikVector[i].idUzytkownika << "|" << uzytkownikVector[i].nazwaUzytkownika << "|"
                                << uzytkownikVector[i].hasloUzytkownika << "|" << endl;
            }
            cout << "Haslo zostalo zmienione." << endl;
            system("pause");
        }
    }
    plikUzytkownicy.close();
    return uzytkownikVector;
}

struct Adresat
{
    int id;
    string imie, nazwisko, email, adres, nrTelefonu;
};

vector<Adresat> dodajAdresata(Adresat adresat, vector<Adresat>adresatVector, int idZalogowanegoUzytkownika)
{
    string imie, nazwisko, email, adres, nrTelefonu;
    int id;
    cout << "Podaj imie: " << endl;
    cin >> adresat.imie;
    cout << "Podaj nazwisko" << endl;
    cin >> adresat.nazwisko;
    cout << "Podaj numer telefonu: " << endl;
    cin >> adresat.nrTelefonu;
    cout << "Podaj email: " << endl;
    cin >> adresat.email;
    cout << "Podaj adres: " << endl;
    cin.sync();
    getline(cin>>ws, adresat.adres);

    fstream plik;
    string linia;
    string idOstatniegoAdresataString;
    int idOstatniegoAdresata = 0;
    plik.open("Adresaci.txt", ios::in | ios:: out);
    while(getline(plik, linia))
    {
        idOstatniegoAdresataString = linia[0];
    }
    idOstatniegoAdresata = atoi(idOstatniegoAdresataString.c_str());
    plik.close();
    if (idOstatniegoAdresata == 0)
    {
        adresat.id = 1;
    }
    else
        adresat.id = idOstatniegoAdresata + 1;
    adresatVector.push_back(adresat);
    plik.open("Adresaci.txt", ios::out | ios::app);
    plik << adresat.id << "|" << idZalogowanegoUzytkownika << "|" << adresat.imie << "|" << adresat.nazwisko << "|" << adresat.nrTelefonu
         << "|" << adresat.email << "|" << adresat.adres << "|" << endl;

    cout << "Adresat zostal dodany" << endl;
    system("pause");
    plik.close();
    return adresatVector;
}

void wyszukajAdresataPoImieniu (vector <Adresat> adresatVector)
{
    system("cls");
    string imie;
    bool licznikImion = false;
    system("cls");
    if (adresatVector.size() == 0)
    {
        cout << "Baza danych jest pusta" << endl;
        system("pause");
    }
    else
    {
        cout << "Wpisz imie:" << endl;
        cin >> imie;
        for (int i = 0; i <= adresatVector.size(); i++)
        {
            if (imie == adresatVector[i].imie)
            {
                licznikImion = true;
                cout << adresatVector[i].imie << " ";
                cout << adresatVector[i].nazwisko << ", ";
                cout << adresatVector[i].nrTelefonu << ", ";
                cout << adresatVector[i].email << ", ";
                cout << adresatVector[i].adres << "." << endl;
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

void wyszukajAdresataPoNazwisku (vector <Adresat> adresatVector)
{
    system("cls");
    string nazwisko;
    bool licznikNazwisk = false;
    system("cls");
    if (adresatVector.size() == 0)
    {
        cout << "Baza danych jest pusta" << endl;
        system("pause");
    }
    else
    {
        cout << "Wpisz nazwisko:" << endl;
        cin >> nazwisko;
        for (int i = 0; i <= adresatVector.size(); i++)
        {
            if (nazwisko == adresatVector[i].nazwisko)
            {
                licznikNazwisk = true;
                cout << adresatVector[i].imie << " ";
                cout << adresatVector[i].nazwisko << ", ";
                cout << adresatVector[i].nrTelefonu << ", ";
                cout << adresatVector[i].email << ", ";
                cout << adresatVector[i].adres << "." << endl;
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

void listaAdresatow(vector<Adresat> adresatVector)
{
    if (adresatVector.size() == 0)
    {
        system("cls");
        cout << "Baza danych jest pusta." << endl;
        system("pause");
    }
    else
    {
        system("cls");
        for (int i = 0; i <= adresatVector.size()-1; i++)
        {
            cout << adresatVector[i].id << ". ";
            cout << adresatVector[i].imie << " ";
            cout << adresatVector[i].nazwisko << ", ";
            cout << adresatVector[i].nrTelefonu << ", ";
            cout << adresatVector[i].email << ", ";
            cout << adresatVector[i].adres << "." << endl;
        }
        cout << endl;
        system("pause");
    }
}

void nadpisaniePlikuEdycjaAdresata (int idEdytowanegoAdresata, Adresat adresat, int idZalogowanegoUzytkownika)
{
    fstream plik;
    plik.open("Adresaci.txt", ios::in | ios::out);
    fstream plikAdresaciTymczasowy;
    plikAdresaciTymczasowy.open("Adresaci_tymczasowy.txt", ios::in | ios::app);

    string linia;
    string idStringEdytowanegoAdresata;
    string idStringZalogowanegoUzytkownika;
    while(getline(plik, linia))
    {
        idStringEdytowanegoAdresata = linia[0];
        idStringZalogowanegoUzytkownika = linia[2];
        if (idEdytowanegoAdresata == atoi(idStringEdytowanegoAdresata.c_str()) && idZalogowanegoUzytkownika == atoi(idStringZalogowanegoUzytkownika.c_str()))
        {
            plikAdresaciTymczasowy << adresat.id << "|" << idZalogowanegoUzytkownika << "|" <<  adresat.imie << "|"
                                   << adresat.nazwisko << "|" << adresat.nrTelefonu << "|" << adresat.email << "|" << adresat.adres << "|" << endl;
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

vector <Adresat> edycjaAdresata (Adresat adresat, vector<Adresat> adresatVector, int idZalogowanegoUzytkownika)
{
    string idEdytowanegoAdresataString;
    string wybor;
    ofstream plik;
    bool znalezionoID = false;

    if (adresatVector.size() == 0)
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
        for (int i = 0; i <= adresatVector.size()-1; i++)
        {
            if (idEdytowanegoAdresata == adresatVector[i].id)
            {
                adresat.id = idEdytowanegoAdresata;
                adresat.imie = adresatVector[i].imie;
                adresat.nazwisko = adresatVector[i].nazwisko;
                adresat.nrTelefonu = adresatVector[i].nrTelefonu;
                adresat.email = adresatVector[i].email;
                adresat.adres = adresatVector[i].adres;
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
                    cin >> adresat.imie;
                    adresatVector[i].imie = adresat.imie;
                }
                else if (wybor == "2")
                {
                    cout << "Podaj nowe nazwisko: ";
                    cin >> adresat.nazwisko;
                    adresatVector[i].nazwisko = adresat.nazwisko;
                }
                else if (wybor == "3")
                {
                    cout << "Podaj nowy numer telefonu: ";
                    cin >> adresat.nrTelefonu;
                    adresatVector[i].nrTelefonu = adresat.nrTelefonu;
                }
                else if (wybor == "4")
                {
                    cout << "Podaj nowy email: ";
                    cin >> adresat.email;
                    adresatVector[i].email = adresat.email;
                }
                else if (wybor == "5")
                {
                    cout << "Podaj nowy adres: ";
                    cin.sync();
                    getline(cin>>ws, adresat.adres);
                    adresatVector[i].adres = adresat.adres;
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
    return adresatVector;
}

void nadpisaniePlikuUsuniecieAdresata (int idEdytowanegoAdresata, int idZalogowanegoUzytkownika)
{
    fstream plik;
    plik.open("Adresaci.txt", ios::in | ios::out);
    fstream plikAdresaciTymczasowy;
    plikAdresaciTymczasowy.open("Adresaci_tymczasowy.txt", ios::in | ios::app);

    string linia;
    string idStringUsuwanegoAdresata;
    string idStringZalogowanegoUzytkownika;
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

vector <Adresat> usuniecieAdresata (vector<Adresat> adresatVector, int idZalogowanegoUzytkownika)
{
    string idString;
    string wybor;
    ofstream plik;
    bool znalezionoID = false;
    int i = 0;
    if (adresatVector.size() == 0)
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
        for (vector<Adresat>::iterator it = adresatVector.begin(), koniec = adresatVector.end(); it != koniec; it++)
        {
            if (idUsuwanegoAdresata == adresatVector[i].id)
            {
                znalezionoID = true;
                system("cls");
                cout << "Czy na pewno chcesz usunac adresata? (t/n)" << endl;
                cin >> wybor;
                if (wybor == "t")
                {
                    adresatVector.erase(it);
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
    return adresatVector;
}

vector <Uzytkownik> adresaciMenu(int idZalogowanegoUzytkownika, vector <Uzytkownik> uzytkownikVector)
{
    Adresat adresat;
    vector <Adresat> adresatVector;
    int liczbaPrzyjaciol = 0;
    fstream plik;
    plik.open("Adresaci.txt", ios::in | ios::out);
    if (plik.good() == false)
    {
        cout << "Baza adresatow jest pusta." << endl;
        system("pause");
        system("cls");
    }
    string liniaCalosc;
    string linia;
    int idUzytkownikaSprawdzenie;
    int licznik = 0;
    bool czyZapisacUzytkownika;

    while(getline(plik, linia, '|'))
    {
        licznik = licznik + 1;

        if (licznik == 1)
        {
            adresat.id = atoi(linia.c_str());
        }
        else if (licznik == 2)
        {

            idUzytkownikaSprawdzenie = atoi(linia.c_str());
            if (idUzytkownikaSprawdzenie != idZalogowanegoUzytkownika)
                czyZapisacUzytkownika = false;
            else
                czyZapisacUzytkownika = true;
        }
        else if (licznik == 3)
        {
            adresat.imie = linia;
        }
        else if (licznik == 4)
        {
            adresat.nazwisko = linia;
        }
        else if (licznik == 5)
        {
            adresat.nrTelefonu = linia;
        }
        else if (licznik == 6)
        {
            adresat.email = linia;
        }
        else if (licznik == 7)
        {
            adresat.adres = linia;
        }

        if (licznik == 7 && czyZapisacUzytkownika == true)
        {
            licznik = 0;
            czyZapisacUzytkownika = false;
            adresatVector.push_back(adresat);
        }
        else if (licznik == 7)
            licznik = 0;
    }

    plik.close();

    while(1)
    {
        system("cls");
        cout << "KSIAZKA ADRESOWA" << endl << endl;
        cout << "1. Dodaj adresata." << endl;
        cout << "2. Wyszukaj po imieniu." << endl;
        cout << "3. Wysukaj po nazwisku." << endl;
        cout << "4. Wyswietl wszystkich adresatow." << endl;
        cout << "5. Usun adresata." << endl;
        cout << "6. Edytuj adresata." << endl;
        cout << "7. Zmien haslo." << endl;
        cout << "9. Wyloguj sie." << endl;

        char wybor;
        cin >> wybor;
        if (wybor == '1')
        {
            adresatVector = dodajAdresata(adresat, adresatVector, idZalogowanegoUzytkownika);
        }
        else if (wybor == '2')
        {
            wyszukajAdresataPoImieniu(adresatVector);
        }
        else if (wybor == '3')
        {
            wyszukajAdresataPoNazwisku(adresatVector);
        }
        else if (wybor == '4')
        {
            listaAdresatow(adresatVector);
        }
        else if (wybor == '5')
        {
            adresatVector = usuniecieAdresata(adresatVector, idZalogowanegoUzytkownika);
        }
        else if (wybor == '6')
        {
            adresatVector = edycjaAdresata (adresat, adresatVector, idZalogowanegoUzytkownika);
        }
        else if (wybor == '7')
        {
            uzytkownikVector = zmianaHaslaUzytkownika(uzytkownikVector, idZalogowanegoUzytkownika);
        }
        else if (wybor == '9')
        {
            return uzytkownikVector;
        }
        else
        {
            cout << "Nieprawidlowy wybor." << endl;
            cout << endl;
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
    string liniaUzytkownicy;
    int licznikUzytkownicy = 0;
    while (getline (plikUzytkownicy, liniaUzytkownicy, '|'))
    {
        licznikUzytkownicy = licznikUzytkownicy + 1;

        if (licznikUzytkownicy == 1)
        {
            uzytkownik.idUzytkownika = atoi(liniaUzytkownicy.c_str());
        }
        else if (licznikUzytkownicy == 2)
        {
            uzytkownik.nazwaUzytkownika = liniaUzytkownicy;
        }
        else if (licznikUzytkownicy == 3)
        {
            uzytkownik.hasloUzytkownika = liniaUzytkownicy;
        }
        if (licznikUzytkownicy == 3)
        {
            licznikUzytkownicy = 0;
            uzytkownikVector.push_back(uzytkownik);
        }
    }
    plikUzytkownicy.close();

    char wyborUzytkownicy;

    while (1)
    {
        system("cls");
        cout << "1. Logowanie." << endl;
        cout << "2. Rejestracja." << endl;
        cout << "9. Zamknij program." << endl;

        cin >> wyborUzytkownicy;

        if (wyborUzytkownicy == '1')
        {
            idZalogowanegoUzytkownika = logowanieUzytkownika(uzytkownikVector);
            if (idZalogowanegoUzytkownika != 0)
                uzytkownikVector = adresaciMenu(idZalogowanegoUzytkownika, uzytkownikVector);
        }
        else if (wyborUzytkownicy == '2')
        {
            uzytkownikVector = rejestracjaUzytkownika(uzytkownik, uzytkownikVector);
        }
        else if (wyborUzytkownicy == '9')
        {
            exit(0);
        }
        else
        {
            cout << "Nieprawidlowy wybor" << endl;;
            system("pause");
        }
    }
    return 0;
}
