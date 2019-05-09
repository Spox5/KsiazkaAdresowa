#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    while (true)
    {
        if (ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() == 0)
        {
            char wybor;

            system("cls");
            cout << "    >>> MENU  GLOWNE <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Koniec programu" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            cin >> wybor;

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.ustawIdZalogowanegoUzytkownika(ksiazkaAdresowa.logowanieUzytkownika());
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {

            char wyborMenuUzytkownika;

            system("cls");
            cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Dodaj adresata" << endl;
            cout << "2. Wyszukaj po imieniu" << endl;
            cout << "3. Wyszukaj po nazwisku" << endl;
            cout << "4. Wyswietl adresatow" << endl;
            cout << "5. Usun adresata" << endl;
            cout << "6. Edytuj adresata" << endl;
            cout << "---------------------------" << endl;
            cout << "7. Zmien haslo" << endl;
            cout << "8. Wyloguj sie" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            cin >> wyborMenuUzytkownika;

            switch (wyborMenuUzytkownika)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika());
                break;
            case '2':
                ksiazkaAdresowa.wyszukajAdresataPoImieniu(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika());
                break;
            case '3':
                ksiazkaAdresowa.wyszukajAdresataPoNazwisku(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika());
                break;
            case '4':
                ksiazkaAdresowa.listaAdresatow(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika());
                break;
            case '5':

                break;
            case '6':

                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaUzytkownika(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika());
                break;
            case '8':
                ksiazkaAdresowa.ustawIdZalogowanegoUzytkownika(ksiazkaAdresowa.wylogowanieUzytkownika());
                break;
            }
        }
    }

    /*ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    int idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.zmianaHaslaUzytkownika(idZalogowanegoUzytkownika);
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.listaAdresatow(idZalogowanegoUzytkownika);
    ksiazkaAdresowa.dodajAdresata(idZalogowanegoUzytkownika);
    ksiazkaAdresowa.listaAdresatow(idZalogowanegoUzytkownika);
    ksiazkaAdresowa.wylogowanieUzytkownika();*/

    /*
int main()
{
    Uzytkownik uzytkownik;
    vector <Uzytkownik> uzytkownicy;

    uzytkownicy = wczytaniePlikuUzytkownika();

    while (1)
    {
        char wyborUzytkownicy = menuUzytkownicyWybor();
        menuUzytkownicy(wyborUzytkownicy, uzytkownicy);
    }
    return 0;
}

vector <Uzytkownik> zmianaHaslaUzytkownika(vector <Uzytkownik> uzytkownicy, int idZalogowanegoUzytkownika)
{
    ofstream plikUzytkownicy;
    string noweHaslo;

    cout << "Podaj nowe haslo:" << endl;
    cin >> noweHaslo;

    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (idZalogowanegoUzytkownika == uzytkownicy[i].idUzytkownika)
        {
            uzytkownicy[i].hasloUzytkownika = noweHaslo;
            plikUzytkownicy.close();
            plikUzytkownicy.open("Uzytkownicy.txt");
            for (int i = 0; i <= uzytkownicy.size()-1; i++)
            {
                plikUzytkownicy << uzytkownicy[i].idUzytkownika << "|" << uzytkownicy[i].nazwaUzytkownika << "|"
                                << uzytkownicy[i].hasloUzytkownika << "|" << endl;
            }
            cout << "Haslo zostalo zmienione." << endl;
            system("pause");
        }
    }
    plikUzytkownicy.close();
    return uzytkownicy;
}

vector<Adresat> dodajAdresata(Adresat adresat, vector<Adresat>adresatVector, int idZalogowanegoUzytkownika)
{
    string imie, nazwisko, email, adres, nrTelefonu;
    int id;
    fstream plik;
    string linia;
    string idOstatniegoAdresataString;
    int idOstatniegoAdresata = 0;

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

vector <Adresat> usuniecieAdresata (vector<Adresat> adresatVector, int idZalogowanegoUzytkownika)
{
    ofstream plik;
    string idString;
    string wybor;
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

char menuAdresatWybor()
{
    char wybor;

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
    cin >> wybor;

    return wybor;
}

vector <Adresat> wczytaniePlikuZAdresatami(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    vector <Adresat> adresaci;
    fstream plikZAdresatami;
    string liniaCalosc;
    string linia;
    int idUzytkownikaSprawdzenie;
    int licznik = 0;
    bool czyZapisacUzytkownika;

    plikZAdresatami.open("Adresaci.txt", ios::in | ios::out);
    if (plikZAdresatami.good() == false)
    {
        cout << "Baza adresatow jest pusta." << endl;
        system("pause");
        system("cls");
    }

    while(getline(plikZAdresatami, linia, '|'))
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
            adresaci.push_back(adresat);
        }
        else if (licznik == 7)
            licznik = 0;
    }
    plikZAdresatami.close();

    return adresaci;
}

vector <Uzytkownik> adresaciMenu(int idZalogowanegoUzytkownika, vector <Uzytkownik> uzytkownicy)
{
    Adresat adresat;
    vector <Adresat> adresatVector = wczytaniePlikuZAdresatami(idZalogowanegoUzytkownika);

    while(1)
    {
        char wybor = menuAdresatWybor();

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
            uzytkownicy = zmianaHaslaUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
        }
        else if (wybor == '9')
        {
            return uzytkownicy;
        }
        else
        {
            cout << "Nieprawidlowy wybor." << endl;
            cout << endl;
            system("pause");
        }
    }
}

vector <Uzytkownik> wczytaniePlikuUzytkownika()
{
    fstream plikUzytkownicy;
    Uzytkownik uzytkownik;
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
            uzytkownicy.push_back(uzytkownik);
        }
    }
    plikUzytkownicy.close();

    return uzytkownicy;
}

char menuUzytkownicyWybor()
{
    char wyborUzytkownicy;

    system("cls");
    cout << "1. Logowanie." << endl;
    cout << "2. Rejestracja." << endl;
    cout << "9. Zamknij program." << endl;
    cin >> wyborUzytkownicy;

    return wyborUzytkownicy;
}

void menuUzytkownicy(char wyborUzytkownicy, vector <Uzytkownik> uzytkownicy)
{
    Uzytkownik uzytkownik;
    int idZalogowanegoUzytkownika = 0;

    if (wyborUzytkownicy == '1')
    {
        idZalogowanegoUzytkownika = uzytkownik.logowanieUzytkownika(uzytkownicy);
        if (idZalogowanegoUzytkownika != 0)
            uzytkownicy = adresaciMenu(idZalogowanegoUzytkownika, uzytkownicy);
    }
    else if (wyborUzytkownicy == '2')
    {
        uzytkownicy = uzytkownik.rejestracjaUzytkownika(uzytkownik, uzytkownicy);
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
}*/

    return 0;
}

