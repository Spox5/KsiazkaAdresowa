#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include "PlikTekstowy.h"
#include "Adresat.h"
#include <fstream>
#include <sstream>

using namespace std;

class PlikZAdresatami: public PlikTekstowy
{
    //const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {};
    void dopisz(string tekst);
    string wypiszNazwePlikuZAdresatami();
    vector <Adresat> wczytaniePlikuZAdresatami(int idZalogowanegoUzytkownika);

    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int konwersjaStringNaInt(string liczba);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);

    void zapisanieAdresataDoPliku(Adresat adresat, int idZalogowanegoUzytkownika);
    void nadpisaniePlikuUsuniecieAdresata (int idEdytowanegoAdresata, int idZalogowanegoUzytkownika);
    void nadpisaniePlikuEdycjaAdresata (Adresat adresat, int idEdytowanegoAdresata, int idZalogowanegoUzytkownika);
};

#endif
