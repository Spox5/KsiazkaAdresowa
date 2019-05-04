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
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMaster(nazwaPlikuZUzytkownikami) {
    uzytkownikMaster.wczytaniePlikuZUzytkownikami();
    };
    void rejestracjaUzytkownika ();
    int logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int wylogowanieUzytkownika();
    vector <Uzytkownik> zmianaHaslaUzytkownika(int idZalogowanegoUzytkownika);

    void dodajAdresata(int idZalogowanegoUzytkownika);
    void listaAdresatow(int idZalogowanegoUzytkownika);

};

#endif
