#include "AdresatMaster.h"
#include "PlikZAdresatami.h"

vector <Uzytkownik> AdresatMaster::adresaciMenu(int idZalogowanegoUzytkownika, vector <Uzytkownik> uzytkownicy)
{
    Uzytkownik uzytkownik;
    PlikZAdresatami plikZAdresatami;
    Adresat adresat;
    vector <Adresat> adresaci = plikZAdresatami.wczytaniePlikuZAdresatami(idZalogowanegoUzytkownika);

    while(1)
    {
        char wybor = menuAdresatWybor();

        if (wybor == '1')
        {
            adresaci = adresat.dodajAdresata(adresaci, idZalogowanegoUzytkownika);
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
            adresat.listaAdresatow(adresaci);
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
            uzytkownicy = uzytkownik.zmianaHaslaUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
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
}
