#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMaster.h"
#include "AdresatMaster.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMaster uzytkownikMaster;
    AdresatMaster adresatMaster;


public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikMaster(nazwaPlikuZUzytkownikami), adresatMaster(nazwaPlikuZAdresatami) {

    };
    void rejestracjaUzytkownika ();
    int logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int wylogowanieUzytkownika();
    void zmianaHaslaUzytkownika(int idZalogowanegoUzytkownika);
    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);

    void dodajAdresata(int idZalogowanegoUzytkownika);
    void listaAdresatow(int idZalogowanegoUzytkownika);
    void wyszukajAdresataPoImieniu(int idZalogowanegoUzytkownika);

};

#endif
