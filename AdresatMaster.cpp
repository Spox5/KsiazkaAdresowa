#include "AdresatMaster.h"
#include "UzytkownikMaster.h"

int AdresatMaster::pobierzZPlikuIdOstatniegoAdresata()
{
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;

    plikTekstowy.open(plikZAdresatami.wypiszNazwePlikuZAdresatami().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        }
        plikTekstowy.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        return idOstatniegoAdresata;
    }
    else
        return 0;
}

int AdresatMaster::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = funkcjePomocnicze.konwersjaStringNaInt(funkcjePomocnicze.pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

void AdresatMaster::dodajAdresata()
{
    Adresat adresat;
    string imie, nazwisko, nrTelefonu, email, adres;
    fstream plik;
    string linia;

    cout << "Podaj imie: " << endl;
    cin >> imie;
    adresat.ustawImieAdresata(imie);
    cout << "Podaj nazwisko" << endl;
    cin >> nazwisko;
    adresat.ustawNazwiskoAdresata(nazwisko);
    cout << "Podaj numer telefonu: " << endl;
    cin >> nrTelefonu;
    adresat.ustawNrTelefonuAdresata(nrTelefonu);
    cout << "Podaj email: " << endl;
    cin >> email;
    adresat.ustawEmailAdresata(email);
    cout << "Podaj adres: " << endl;
    cin.sync();
    getline(cin>>ws, adres);
    adresat.ustawAdresAdresata(adres);
    adresat.ustawIdAdresata(pobierzZPlikuIdOstatniegoAdresata() + 1);

    adresaci.push_back(adresat);
    cout << "Adresat zostal dodany" << endl;
    system("pause");

    plikZAdresatami.zapisanieAdresataDoPliku(adresat, ID_ZALOGOWANEGO_UZYTKOWNIKA);

}

void AdresatMaster::listaAdresatow()
{
    if (adresaci.size() == 0)
    {
        system("cls");
        cout << "Baza danych jest pusta." << endl;
        system("pause");
    }
    else
    {
        system("cls");
        for (int i = 0; i <= adresaci.size()-1; i++)
        {
            cout << adresaci[i].wypiszIdAdresata() << ". ";
            cout << adresaci[i].wypiszImieAdresata() << " ";
            cout << adresaci[i].wypiszNazwiskoAdresata() << ", ";
            cout << adresaci[i].wypiszNrTelefonuAdresata() << ", ";
            cout << adresaci[i].wypiszEmailAdresata() << ", ";
            cout << adresaci[i].wypiszAdresAdresata() << "." << endl;
        }
        cout << endl;
        system("pause");
    }
}

void AdresatMaster::wyszukajAdresataPoImieniu ()
{
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
        for (int i = 0; i <= adresaci.size()-1; i++)
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

void AdresatMaster::wyszukajAdresataPoNazwisku ()
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
        for (int i = 0; i <= adresaci.size()-1; i++)
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

void AdresatMaster::usuniecieAdresata ()
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
                plikZAdresatami.nadpisaniePlikuUsuniecieAdresata(idUsuwanegoAdresata, ID_ZALOGOWANEGO_UZYTKOWNIKA);
            }
            i ++;
        }
        if (znalezionoID == false)
        {
            cout << "Nieprawidlowe ID" << endl;
            system("pause");
        }
    }
}

void AdresatMaster::edycjaAdresata ()
{
    Adresat adresat;
    string idEdytowanegoAdresataString;
    string wybor, imie, nazwisko, nrTelefonu, email, adres;
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
                plikZAdresatami.nadpisaniePlikuEdycjaAdresata(adresaci[i], idEdytowanegoAdresata, ID_ZALOGOWANEGO_UZYTKOWNIKA);
            }
        }
        if (znalezionoID == false)
        {
            cout << "Nieprawidlowe ID" << endl;
            system("pause");
        }
    }
}
