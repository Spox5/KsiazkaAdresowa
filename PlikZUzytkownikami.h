#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include "Uzytkownik.h"

using namespace std;

class PlikZUzytkownikami
{
public:
    vector <Uzytkownik> wczytaniePlikuZUzytkownikami();
    //
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    static string konwerjsaIntNaString(int liczba);
};

#endif // PLIKZUZYTKOWNIKAMI
