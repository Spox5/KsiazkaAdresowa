#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

<<<<<<< HEAD
#include "AdresatMaster.h"
#include "UzytkownikMaster.h"
=======
#include <iostream>
#include "UzytkownikMaster.h"
#include "AdresatMaster.h"
>>>>>>> 6989526f2abf72d8bfd9fa948d9d9679d16812b9

using namespace std;

class KsiazkaAdresowa
{
<<<<<<< HEAD

public:
    vector <Uzytkownik> menuUzytkownicy(char wyborUzytkownicy, vector <Uzytkownik> uzytkownicy);
    vector <Uzytkownik> adresaciMenu(int idZalogowanegoUzytkownika, vector <Uzytkownik> uzytkownicy);
=======
    UzytkownikMaster uzytkownikMaster;
    AdresatMaster adresatMaster;


public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikMaster(nazwaPlikuZUzytkownikami), adresatMaster(nazwaPlikuZAdresatami) {

    };
    void rejestracjaUzytkownika ();
    int logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int wylogowanieUzytkownika();
    void zmianaHaslaUzytkownika(int idZalogowanegoUzytkownika);
    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);

    void dodajAdresata(int idZalogowanegoUzytkownika);
    void listaAdresatow(int idZalogowanegoUzytkownika);

>>>>>>> 6989526f2abf72d8bfd9fa948d9d9679d16812b9
};

#endif
