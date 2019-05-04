#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy2.txt");

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();


    /*PlikZUzytkownikami plikZUzytkownikami;
    PlikZAdresatami plikZAdresatami;
    AdresatMaster adresatMaster;
    UzytkownikMaster uzytkownikMaster;

    plikZUzytkownikami.wczytaniePlikuZUzytkownikami();
    adresatMaster.listaAdresatow(plikZAdresatami.wczytaniePlikuZAdresatami(1));
    ///////////

    PlikZUzytkownikami plikZUzytkownikami;
    UzytkownikMaster uzytkownikMaster;
    vector <Uzytkownik> uzytkownicy;

    uzytkownicy = plikZUzytkownikami.wczytaniePlikuZUzytkownikami();

    while (1)
    {
        char wyborUzytkownicy = uzytkownikMaster.menuUzytkownicyWybor();
        uzytkownicy = uzytkownikMaster.menuUzytkownicy(wyborUzytkownicy, uzytkownicy);
    }*/
    return 0;
}
