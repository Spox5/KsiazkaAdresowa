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
    adresatMaster.wczytaniePlikuZAdresatami(1);
    };
    void rejestracjaUzytkownika ();
    int logowanieUzytkownika();
    vector <Uzytkownik> zmianaHaslaUzytkownika(int idZalogowanegoUzytkownika);
    void wypiszWszystkichUzytkownikow();
    int wylogowanieUzytkownika();

    //wczytanie pliku z adresatami
    void dodajAdresata(int idZalogowanegoUzytkownika);
    void listaAdresatow();

};

#endif
