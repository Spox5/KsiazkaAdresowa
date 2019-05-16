#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include "PlikTekstowy.h"
#include "Adresat.h"
#include "FunkcjePomocnicze.h"

using namespace std;

class PlikZAdresatami: public PlikTekstowy
{
    FunkcjePomocnicze funkcjePomocnicze;
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzZPlikuIdOstatniegoAdresata();

public:
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {};
    void dopisz(string tekst);
    string wypiszNazwePlikuZAdresatami();
    vector <Adresat> wczytaniePlikuZAdresatami(int idZalogowanegoUzytkownika);

    void zapisanieAdresataDoPliku(Adresat adresat, int idZalogowanegoUzytkownika);
    void nadpisaniePlikuUsuniecieAdresata (int idEdytowanegoAdresata, int idZalogowanegoUzytkownika);
    void nadpisaniePlikuEdycjaAdresata (Adresat adresat, int idEdytowanegoAdresata, int idZalogowanegoUzytkownika);

};

#endif
