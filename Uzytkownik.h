#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

class Uzytkownik
{
public:
    int idUzytkownika;
    string nazwaUzytkownika, hasloUzytkownika;


    vector <Uzytkownik> rejestracjaUzytkownika (vector <Uzytkownik> uzytkownicy);
    int logowanieUzytkownika (vector <Uzytkownik> uzytkownicy);
    vector <Uzytkownik> zmianaHaslaUzytkownika(vector <Uzytkownik> uzytkownicy, int idZalogowanegoUzytkownika);
};

#endif
