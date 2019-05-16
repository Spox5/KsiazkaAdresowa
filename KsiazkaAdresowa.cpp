#include "KsiazkaAdresowa.h"

using namespace std;

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMaster.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMaster.logowanieUzytkownika();
    if (uzytkownikMaster.czyUzytkownikJestZalogowany())
    {
        adresatMaster = new AdresatMaster(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMaster.pobierzIdZalogowanegoUzytkownika());
    }
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika()
{
    uzytkownikMaster.pobierzIdZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaUzytkownika()
{
    uzytkownikMaster.zmianaHaslaUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMaster.wylogowanieUzytkownika();
    delete adresatMaster;
    adresatMaster = NULL;
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMaster->dodajAdresata();
}

void KsiazkaAdresowa::listaAdresatow()
{
    adresatMaster->listaAdresatow();
}

void KsiazkaAdresowa::wyszukajAdresataPoImieniu()
{
    adresatMaster->wyszukajAdresataPoImieniu();
}

void KsiazkaAdresowa::wyszukajAdresataPoNazwisku()
{
    adresatMaster->wyszukajAdresataPoNazwisku();
}

void KsiazkaAdresowa::usuniecieAdresata()
{
    adresatMaster->usuniecieAdresata();
}

void KsiazkaAdresowa::edycjaAdresata ()
{
    adresatMaster->edycjaAdresata();
}
