#ifndef ADRESATMASTER_H
#define ADRESATMASTER_H

#include "PlikZUzytkownikami.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMaster
{
public:
    vector <Uzytkownik> adresaciMenu(int idZalogowanegoUzytkownika, vector <Uzytkownik> uzytkownicy);
    char menuAdresatWybor();
    vector <Adresat> dodajAdresata(vector<Adresat>adresaci, int idZalogowanegoUzytkownika);
    void listaAdresatow(vector<Adresat> adresaci);
};

#endif
