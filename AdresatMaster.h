#ifndef ADRESATMASTER_H
#define ADRESATMASTER_H

#include "PlikZUzytkownikami.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMaster
{
public:

    char menuAdresatWybor();
    vector <Adresat> dodajAdresata(vector<Adresat>adresaci, int idZalogowanegoUzytkownika);
    void listaAdresatow(vector<Adresat> adresaci);
};

#endif
