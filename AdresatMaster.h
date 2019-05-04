#ifndef ADRESATMASTER_H
#define ADRESATMASTER_H

#include "PlikZUzytkownikami.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMaster
{
    PlikZAdresatami plikZAdresatami;



public:
    vector <Adresat> adresaci;

    void ustawWektorAdresaci(vector <Adresat> nowyWektorAdresat);
    vector <Adresat> pobierzWektorAdresaci();

    vector <Uzytkownik> adresaciMenu(int idZalogowanegoUzytkownika, vector <Uzytkownik> uzytkownicy);
    char menuAdresatWybor();

    void wczytaniePlikuZAdresatami(int idZalogowanegoUzytkownika);
    void dodajAdresata(int idZalogowanegoUzytkownika);
    void listaAdresatow(int idZalogowanegoUzytkownika);
};

#endif
