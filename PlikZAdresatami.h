#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include "Adresat.h"
#include <fstream>

using namespace std;

class PlikZAdresatami
{
    const string NAZWA_PLIKU_Z_ADRESATAMI;


public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {};
    string wypiszNazwePlikuZAdresatami();
    vector <Adresat> wczytaniePlikuZAdresatami(int idZalogowanegoUzytkownika);
<<<<<<< HEAD
    void zapisanieNowegoAdresataDoPliku(Adresat adresat);
=======
    void zapisanieAdresataDoPliku(Adresat adresat, int idZalogowanegoUzytkownika);
>>>>>>> 6989526f2abf72d8bfd9fa948d9d9679d16812b9
};

#endif
