#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include "Adresat.h"
#include <fstream>

using namespace std;

class PlikZAdresatami
{
    string nazwaPlikuZAdresatami;

public:
    vector <Adresat> wczytaniePlikuZAdresatami(int idZalogowanegoUzytkownika);
};

#endif
