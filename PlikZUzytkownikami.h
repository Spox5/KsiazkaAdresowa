#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include "Uzytkownik.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZUzytkownikami: public PlikTekstowy
{

public:
    PlikZUzytkownikami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {};
    void dopisz(string tekst);
    vector <Uzytkownik> wczytaniePlikuZUzytkownikami();

    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

    void zapisanieUzytkownikaDoPliku(Uzytkownik uzytkownik);
    void zapisanieZmienionegoHaslaDoPliku(vector <Uzytkownik> uzytkownicy);

};

#endif // PLIKZUZYTKOWNIKAMI
