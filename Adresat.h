#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

class Adresat
{
    int id, idZalogowanegoUzytkownika;
    string imie, nazwisko, nrTelefonu, email, adres;

public:
<<<<<<< HEAD

    void ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika);
    int wypiszIdZalogowanegoUzytkownika();

=======
    Adresat (int id = 0, string imie = "", string nazwisko = "", string nrTelefonu = "", string email = "", string adres = "")
    {
        this->id = id;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->nrTelefonu = nrTelefonu;
        this->email = email;
        this->adres = adres;
    }
>>>>>>> 6989526f2abf72d8bfd9fa948d9d9679d16812b9
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
