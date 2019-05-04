#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include "Uzytkownik.h"
#include <fstream>

using namespace std;

class PlikZUzytkownikami
{
    const string nazwaPlikuZUzytkownikami;


public:
    PlikZUzytkownikami(string NAZWAPLIKUZUZYTKOWNIKAMI) : nazwaPlikuZUzytkownikami(NAZWAPLIKUZUZYTKOWNIKAMI) {};
    vector <Uzytkownik> wczytaniePlikuZUzytkownikami();
    void zapisanieUzytkownikaDoPliku(Uzytkownik uzytkownik);
    //
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami();
    static string konwerjsaIntNaString(int liczba);
};

#endif // PLIKZUZYTKOWNIKAMI
