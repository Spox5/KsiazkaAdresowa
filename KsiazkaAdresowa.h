#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMaster.h"
#include "AdresatMaster.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMaster uzytkownikMaster;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMaster(nazwaPlikuZUzytkownikami) {
    uzytkownikMaster.wczytaniePlikuZUzytkownikami();
    };
    void rejestracjaUzytkownika ();
    void wypiszWszystkichUzytkownikow();

};

#endif
