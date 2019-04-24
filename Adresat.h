#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

class Adresat
{
public:
    int id;
    string imie, nazwisko, email, adres, nrTelefonu;

    vector <Adresat> dodajAdresata(vector<Adresat>adresaci, int idZalogowanegoUzytkownika);
    void listaAdresatow(vector<Adresat> adresaci);
};

#endif
