#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

class Uzytkownik
{
    int idUzytkownika;
    string nazwaUzytkownika;
    string hasloUzytkownika;

public:

    void ustawIdUzytkownika(int noweId);
    int wypiszIdUzytkownika();

    void ustawNazweUzytkownika(string nowaNazwaUzytkownika);
    string wypiszNazweUzytkownika();

    void ustawHasloUzytkownika(string noweHasloUzytkownika);
    string wypiszHasloUzytkownika();

    vector <Uzytkownik> rejestracjaUzytkownika (vector <Uzytkownik> uzytkownicy);
    int logowanieUzytkownika (vector <Uzytkownik> uzytkownicy);
    vector <Uzytkownik> zmianaHaslaUzytkownika(vector <Uzytkownik> uzytkownicy, int idZalogowanegoUzytkownika);
};

#endif
