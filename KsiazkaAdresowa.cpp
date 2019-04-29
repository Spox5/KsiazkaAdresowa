#include "KsiazkaAdresowa.h"

vector <Uzytkownik> KsiazkaAdresowa::menuUzytkownicy(char wyborUzytkownicy, vector <Uzytkownik> uzytkownicy)
{
    UzytkownikMaster uzytkownikMaster;
    AdresatMaster adresatMaster;
    int idZalogowanegoUzytkownika = 0;

    if (wyborUzytkownicy == '1')
    {
        idZalogowanegoUzytkownika = uzytkownikMaster.logowanieUzytkownika(uzytkownicy);
        if (idZalogowanegoUzytkownika != 0)
            uzytkownicy = adresaciMenu(idZalogowanegoUzytkownika, uzytkownicy);
    }
    else if (wyborUzytkownicy == '2')
    {
        uzytkownicy = uzytkownikMaster.rejestracjaUzytkownika(uzytkownicy);
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
    return uzytkownicy;
}

vector <Uzytkownik> KsiazkaAdresowa::adresaciMenu(int idZalogowanegoUzytkownika, vector <Uzytkownik> uzytkownicy)
{
    UzytkownikMaster uzytkownikMaster;
    PlikZAdresatami plikZAdresatami;
    AdresatMaster adresatMaster;
    vector <Adresat> adresaci = plikZAdresatami.wczytaniePlikuZAdresatami(idZalogowanegoUzytkownika);

    while(1)
    {
        char wybor = adresatMaster.menuAdresatWybor();

        if (wybor == '1')
        {
            adresaci = adresatMaster.dodajAdresata(adresaci, idZalogowanegoUzytkownika);
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
            adresatMaster.listaAdresatow(adresaci);
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
            uzytkownicy = uzytkownikMaster.zmianaHaslaUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
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
