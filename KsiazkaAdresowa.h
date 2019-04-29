#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include "AdresatMaster.h"
#include "UzytkownikMaster.h"

using namespace std;

class KsiazkaAdresowa
{

public:
    vector <Uzytkownik> menuUzytkownicy(char wyborUzytkownicy, vector <Uzytkownik> uzytkownicy);
    vector <Uzytkownik> adresaciMenu(int idZalogowanegoUzytkownika, vector <Uzytkownik> uzytkownicy);
};

#endif
