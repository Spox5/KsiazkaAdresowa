#include "KsiazkaAdresowa.h"

<<<<<<< HEAD
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
=======
using namespace std;

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMaster.rejestracjaUzytkownika();
}

int KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMaster.logowanieUzytkownika();
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika()
{
    adresatMaster.pobierzIdZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::ustawIdZalogowanegoUzytkownika(int idZalogowanegoUzytkownika)
{
    adresatMaster.ustawIdZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::zmianaHaslaUzytkownika(int idZalogowanegoUzytkownika)
{
    uzytkownikMaster.zmianaHaslaUzytkownika(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMaster.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMaster.wylogowanieUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata(int idZalogowanegoUzytkownika)
{
    adresatMaster.dodajAdresata(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::listaAdresatow(int idZalogowanegoUzytkownika)
{
    adresatMaster.listaAdresatow(idZalogowanegoUzytkownika);
>>>>>>> 6989526f2abf72d8bfd9fa948d9d9679d16812b9
}
