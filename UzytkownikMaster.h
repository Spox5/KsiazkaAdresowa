#ifndef UZYTKOWNIKMASTER_H
#define UZYTKOWNIKMASTER_H

#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMaster
{
    PlikZUzytkownikami plikZUzytkownikami;
    vector <Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika;

public:
    UzytkownikMaster(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
        idZalogowanegoUzytkownika = 0;
    uzytkownicy = plikZUzytkownikami.wczytaniePlikuZUzytkownikami();
    };

    void ustawWektorUzytkownicy(vector <Uzytkownik> nowyWektorUzytkownicy);
    vector <Uzytkownik> pobierzWektorUzytkownicy();
    void rejestracjaUzytkownika();
    int logowanieUzytkownika ();
    vector <Uzytkownik> zmianaHaslaUzytkownika();
    int wylogowanieUzytkownika();

    void wypiszWszystkichUzytkownikow();
    bool czyUzytkownikJestZalogowany();
    int pobierzIdZalogowanegoUzytkownika();
};

#endif
