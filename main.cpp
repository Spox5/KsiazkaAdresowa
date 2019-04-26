#include <iostream>
#include "UzytkownikMaster.h"
#include "AdresatMaster.h"

using namespace std;

int main()
{
    PlikZUzytkownikami plikZUzytkownikami;
    PlikZAdresatami plikZAdresatami;
    AdresatMaster adresatMaster;
    UzytkownikMaster uzytkownikMaster;

    plikZUzytkownikami.wczytaniePlikuZUzytkownikami();
    adresatMaster.listaAdresatow(plikZAdresatami.wczytaniePlikuZAdresatami(1));
    uzytkownikMaster.wyswietlenieMenuUzytkownikaiWybor();

    /*PlikZUzytkownikami plikZUzytkownikami;
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
