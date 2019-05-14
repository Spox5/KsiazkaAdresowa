#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include "PlikTekstowy.h"
#include "Adresat.h"
#include <fstream>

using namespace std;

class PlikZAdresatami: public PlikTekstowy
{
    //const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {};
    dopisz(string tekst)
    {
        fstream plikTekstowy;
        plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

        if (plikTekstowy.good() == true)
        {
            if (czyPlikJestPusty())
                plikTekstowy << "To jest poczatek pliku" << endl;
            plikTekstowy << tekst << endl;
        }

        plikTekstowy.close();
    }
    string wypiszNazwePlikuZAdresatami();
    vector <Adresat> wczytaniePlikuZAdresatami(int idZalogowanegoUzytkownika);
    void zapisanieAdresataDoPliku(Adresat adresat, int idZalogowanegoUzytkownika);
    void nadpisaniePlikuUsuniecieAdresata (int idEdytowanegoAdresata, int idZalogowanegoUzytkownika);
    void nadpisaniePlikuEdycjaAdresata (Adresat adresat, int idEdytowanegoAdresata, int idZalogowanegoUzytkownika);
};

#endif
