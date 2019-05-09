#include "KsiazkaAdresowa.h"

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
}

void KsiazkaAdresowa::wyszukajAdresataPoImieniu(int idZalogowanegoUzytkownika)
{
    adresatMaster.wyszukajAdresataPoImieniu(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wyszukajAdresataPoNazwisku(int idZalogowanegoUzytkownika)
{
    adresatMaster.wyszukajAdresataPoNazwisku(idZalogowanegoUzytkownika);
}
