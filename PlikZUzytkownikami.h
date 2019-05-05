#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include "Uzytkownik.h"
#include <fstream>

using namespace std;

class PlikZUzytkownikami
{
    const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;


public:
    PlikZUzytkownikami(string nazwaPlikuZUzytkownikami) : NAZWA_PLIKU_Z_UZYTKOWNIKAMI(nazwaPlikuZUzytkownikami) {};
    vector <Uzytkownik> wczytaniePlikuZUzytkownikami();
    void zapisanieUzytkownikaDoPliku(Uzytkownik uzytkownik);
    void zapisanieZmienionegoHaslaDoPliku(vector <Uzytkownik> uzytkownicy);
    //
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami();
    static string konwerjsaIntNaString(int liczba);
};

#endif // PLIKZUZYTKOWNIKAMI
