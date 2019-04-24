#ifndef UZYTKOWNIKMASTER_H
#define UZYTKOWNIKMASTER_H

#include <vector>
#include "Uzytkownik.h"

using namespace std;

class UzytkownikMaster
{
public:
    vector <Uzytkownik> menuUzytkownicy(char wyborUzytkownicy, vector <Uzytkownik> uzytkownicy);
    char menuUzytkownicyWybor();
};

#endif
