#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include "Adresat.h"

using namespace std;

class PlikZAdresatami
{
public:
    vector <Adresat> wczytaniePlikuZAdresatami(int idZalogowanegoUzytkownika);
    void zapisanieNowegoAdresataDoPliku(Adresat adresat);
};

#endif
