#ifndef UZYTKOWNIKMASTER_H
#define UZYTKOWNIKMASTER_H

#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMaster
{
public:

    vector <Uzytkownik> menuUzytkownicy(char wyborUzytkownicy, vector <Uzytkownik> uzytkownicy);
    char wyswietlenieMenuUzytkownikaiWybor();
    vector <Uzytkownik> rejestracjaUzytkownika (vector <Uzytkownik> uzytkownicy);
    int logowanieUzytkownika (vector <Uzytkownik> uzytkownicy);
    vector <Uzytkownik> zmianaHaslaUzytkownika(vector <Uzytkownik> uzytkownicy, int idZalogowanegoUzytkownika);
};

#endif
