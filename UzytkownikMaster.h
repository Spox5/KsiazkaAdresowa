#ifndef UZYTKOWNIKMASTER_H
#define UZYTKOWNIKMASTER_H

#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMaster
{
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;

public:
    UzytkownikMaster(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {};
    vector <Uzytkownik> menuUzytkownicy(char wyborUzytkownicy, vector <Uzytkownik> uzytkownicy);
    void wczytaniePlikuZUzytkownikami();
    char wyswietlenieMenuUzytkownikaiWybor();
    void rejestracjaUzytkownika();
    int logowanieUzytkownika (vector <Uzytkownik> uzytkownicy);
    vector <Uzytkownik> zmianaHaslaUzytkownika(vector <Uzytkownik> uzytkownicy, int idZalogowanegoUzytkownika);

    void wypiszWszystkichUzytkownikow();
};

#endif
