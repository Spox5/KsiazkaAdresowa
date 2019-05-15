#include "PlikTekstowy.h"

string PlikTekstowy::pobierzNazwePliku()
{
    return NAZWA_PLIKU;
}

bool PlikTekstowy::czyPlikJestPusty()
{
    bool plikJestPusty = true;
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        plikTekstowy.seekg(0, ios::end);
        if (plikTekstowy.tellg() != 0)
            plikJestPusty = false;
    }

    plikTekstowy.close();
    return plikJestPusty;
}
