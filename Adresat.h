#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

class Adresat
{
    int id;
    string imie, nazwisko, nrTelefonu, email, adres;

public:

    void ustawIdAdresata(int noweIdAdresata);
    int wypiszIdAdresata();

    void ustawImieAdresata(string noweImieAdresata);
    string wypiszImieAdresata();

    void ustawNazwiskoAdresata(string noweNazwiskoAdresata);
    string wypiszNazwiskoAdresata();

    void ustawNrTelefonuAdresata(string nowyNrTelefonuAdresata);
    string wypiszNrTelefonuAdresata();

    void ustawEmailAdresata(string nowyEmailAdresata);
    string wypiszEmailAdresata();

    void ustawAdresAdresata(string nowyAdresAdresata);
    string wypiszAdresAdresata();

};

#endif
