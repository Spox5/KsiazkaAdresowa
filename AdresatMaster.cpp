#include "AdresatMaster.h"
#include "UzytkownikMaster.h"


void AdresatMaster::ustawWektorAdresaci(vector <Adresat> nowyWektorAdresaci)
{
    adresaci = nowyWektorAdresaci;
}

vector <Adresat> AdresatMaster::pobierzWektorAdresaci()
{
    return adresaci;
}

void AdresatMaster::ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika)
{
    idZalogowanegoUzytkownika = noweIdZalogowanegoUzytkownika;
}

int AdresatMaster::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void AdresatMaster::wczytaniePlikuZAdresatami(int idZalogowanegoUzytkownika)
{
    adresaci = plikZAdresatami.wczytaniePlikuZAdresatami(idZalogowanegoUzytkownika);
}

/*vector <Uzytkownik> AdresatMaster::adresaciMenu(int idZalogowanegoUzytkownika, vector <Uzytkownik> uzytkownicy)
{
    //UzytkownikMaster uzytkownikMaster;
    PlikZAdresatami plikZAdresatami;
    AdresatMaster adresatMaster;
    vector <Adresat> adresaci = plikZAdresatami.wczytaniePlikuZAdresatami(idZalogowanegoUzytkownika);

    while(1)
    {
        char wybor = menuAdresatWybor();

        if (wybor == '1')
        {
            //adresaci = adresatMaster.dodajAdresata(adresaci, idZalogowanegoUzytkownika);
        }
        else if (wybor == '2')
        {
            //wyszukajAdresataPoImieniu(adresaci);
        }
        else if (wybor == '3')
        {
            //wyszukajAdresataPoNazwisku(adresaci);
        }
        else if (wybor == '4')
        {
            //adresatMaster.listaAdresatow(adresaci);
        }
        else if (wybor == '5')
        {
            //adresaci = usuniecieAdresata(adresaci, idZalogowanegoUzytkownika);
        }
        else if (wybor == '6')
        {
            //adresaci = edycjaAdresata (adresat, adresaci, idZalogowanegoUzytkownika);
        }
        else if (wybor == '7')
        {
            //uzytkownicy = uzytkownikMaster.zmianaHaslaUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
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

char AdresatMaster::menuAdresatWybor()
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
}*/

void AdresatMaster::dodajAdresata(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    string imie, nazwisko, nrTelefonu, email, adres;
    fstream plik;
    string linia;
    string idOstatniegoAdresataString;
    int idOstatniegoAdresata = 0;

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

    plik.open(plikZAdresatami.wypiszNazwePlikuZAdresatami().c_str(), ios::in | ios:: out);
    while(getline(plik, linia))
    {
        idOstatniegoAdresataString = linia[0];
    }
    idOstatniegoAdresata = atoi(idOstatniegoAdresataString.c_str());
    plik.close();

    if (idOstatniegoAdresata == 0)
    {
        adresat.ustawIdAdresata(1);
    }
    else
        adresat.ustawIdAdresata(idOstatniegoAdresata + 1);

    adresaci.push_back(adresat);

    cout << "Adresat zostal dodany" << endl;
    system("pause");

    plikZAdresatami.zapisanieAdresataDoPliku(adresat, idZalogowanegoUzytkownika);

}

void AdresatMaster::listaAdresatow(int idZalogowanegoUzytkownika)
{
    adresaci = plikZAdresatami.wczytaniePlikuZAdresatami(idZalogowanegoUzytkownika);
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
