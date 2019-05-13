#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMaster.h"
#include "AdresatMaster.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMaster uzytkownikMaster;
    AdresatMaster *adresatMaster;
    const string NAZWA_PLIKU_Z_ADRESATAMI;


public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikMaster(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        adresatMaster = NULL;
    };
    ~KsiazkaAdresowa()
    {
        delete adresatMaster;
        adresatMaster = NULL;
    }
    void rejestracjaUzytkownika ();
    int logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int wylogowanieUzytkownika();
    void zmianaHaslaUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();

    void dodajAdresata();
    void listaAdresatow();
    void wyszukajAdresataPoImieniu();
    void wyszukajAdresataPoNazwisku();
    void usuniecieAdresata ();
    void edycjaAdresata ();

};

#endif
