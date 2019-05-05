#ifndef UZYTKOWNIKMASTER_H
#define UZYTKOWNIKMASTER_H

#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMaster
{
    PlikZUzytkownikami plikZUzytkownikami;
    vector <Uzytkownik> uzytkownicy;

public:
    UzytkownikMaster(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
    uzytkownicy = plikZUzytkownikami.wczytaniePlikuZUzytkownikami();
    };

    void ustawWektorUzytkownicy(vector <Uzytkownik> nowyWektorUzytkownicy);
    vector <Uzytkownik> pobierzWektorUzytkownicy();
    vector <Uzytkownik> menuUzytkownicy(char wyborUzytkownicy, vector <Uzytkownik> uzytkownicy);
    char wyswietlenieMenuUzytkownikaiWybor();
    void rejestracjaUzytkownika();
    int logowanieUzytkownika ();
    vector <Uzytkownik> zmianaHaslaUzytkownika(int idZalogowanegoUzytkownika);
    int wylogowanieUzytkownika();

    void wypiszWszystkichUzytkownikow();
};

#endif
