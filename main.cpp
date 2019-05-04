#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");


    ksiazkaAdresowa.listaAdresatow();
    ksiazkaAdresowa.dodajAdresata(1);
    ksiazkaAdresowa.listaAdresatow();

    //ksiazkaAdresowa.zmianaHaslaUzytkownika(1); - do poprawy
    ksiazkaAdresowa.wylogowanieUzytkownika();

    return 0;
}
