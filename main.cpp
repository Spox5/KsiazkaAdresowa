#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");

    //ksiazkaAdresowa.rejestracjaUzytkownika();
    int idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.zmianaHaslaUzytkownika(idZalogowanegoUzytkownika);
    //ksiazkaAdresowa.listaAdresatow(idZalogowanegoUzytkownika);
    //ksiazkaAdresowa.dodajAdresata(idZalogowanegoUzytkownika);
    //ksiazkaAdresowa.listaAdresatow(idZalogowanegoUzytkownika);
    //ksiazkaAdresowa.wylogowanieUzytkownika();

    return 0;
}
