#ifndef ADRESATMASTER_H
#define ADRESATMASTER_H

#include "PlikZUzytkownikami.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMaster
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    PlikZAdresatami plikZAdresatami;
    FunkcjePomocnicze funkcjePomocnicze;
    int pobierzZPlikuIdOstatniegoAdresata();
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    vector <Adresat> adresaci;


public:
    AdresatMaster(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
    : plikZAdresatami(nazwaPlikuZAdresatami),  ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
    adresaci = plikZAdresatami.wczytaniePlikuZAdresatami(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };

    void dodajAdresata();
    void listaAdresatow();
    void wyszukajAdresataPoImieniu ();
    void wyszukajAdresataPoNazwisku ();
    void usuniecieAdresata ();
    void edycjaAdresata ();
};

#endif
