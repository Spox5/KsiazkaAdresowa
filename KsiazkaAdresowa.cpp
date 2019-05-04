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

vector <Uzytkownik> KsiazkaAdresowa::zmianaHaslaUzytkownika(int idZalogowanegoUzytkownika)
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

void KsiazkaAdresowa::listaAdresatow()
{
    adresatMaster.listaAdresatow();
}
