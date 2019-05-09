#ifndef ADRESATMASTER_H
#define ADRESATMASTER_H

#include "PlikZUzytkownikami.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMaster
{
    PlikZAdresatami plikZAdresatami;
    int idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;

public:
    AdresatMaster(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {
    adresaci = plikZAdresatami.wczytaniePlikuZAdresatami(idZalogowanegoUzytkownika);
    idZalogowanegoUzytkownika = 0;
    };

    void ustawWektorAdresaci(vector <Adresat> nowyWektorAdresat);
    vector <Adresat> pobierzWektorAdresaci();

    void ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika);
    int pobierzIdZalogowanegoUzytkownika();

    //vector <Uzytkownik> adresaciMenu(int idZalogowanegoUzytkownika, vector <Uzytkownik> uzytkownicy);
    //char menuAdresatWybor();

    void wczytaniePlikuZAdresatami(int idZalogowanegoUzytkownika);
    void dodajAdresata(int idZalogowanegoUzytkownika);
    void listaAdresatow(int idZalogowanegoUzytkownika);
    void wyszukajAdresataPoImieniu (int idZalogowanegoUzytkownika);
};

#endif
