#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include "Adresat.h"
#include <fstream>

using namespace std;

class PlikZAdresatami
{
    string nazwaPlikuZAdresatami;

public:
    PlikZAdresatami();
    string wypiszNazwePlikuZAdresatami();
    vector <Adresat> wczytaniePlikuZAdresatami(int idZalogowanegoUzytkownika);
    void zapisanieAdresataDoPliku(Adresat adresat, int idZalogowanegoUzytkownika);
};

#endif
