#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include "Uzytkownik.h"
#include "PlikTekstowy.h"
#include <fstream>

using namespace std;

class PlikZUzytkownikami: public PlikTekstowy
{
    //const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;

public:
    PlikZUzytkownikami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {};
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
    vector <Uzytkownik> wczytaniePlikuZUzytkownikami();
    void zapisanieUzytkownikaDoPliku(Uzytkownik uzytkownik);
    void zapisanieZmienionegoHaslaDoPliku(vector <Uzytkownik> uzytkownicy);

};

#endif // PLIKZUZYTKOWNIKAMI
