#ifndef ADRESATMASTER_H
#define ADRESATMASTER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include "Uzytkownik.h"

using namespace std;

class AdresatMaster
{
public:
    vector <Uzytkownik> adresaciMenu(int idZalogowanegoUzytkownika, vector <Uzytkownik> uzytkownicy);
    char menuAdresatWybor();
};

#endif
