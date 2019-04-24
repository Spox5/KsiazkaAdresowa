#include "PlikZAdresatami.h"

vector <Adresat> PlikZAdresatami::wczytaniePlikuZAdresatami(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    vector <Adresat> adresaci;
    fstream plikZAdresatami;
    string liniaCalosc;
    string linia;
    int idUzytkownikaSprawdzenie;
    int licznik = 0;
    bool czyZapisacUzytkownika;

    plikZAdresatami.open("Adresaci.txt", ios::in | ios::out);
    if (plikZAdresatami.good() == false)
    {
        cout << "Baza adresatow jest pusta." << endl;
        system("pause");
        system("cls");
    }

    while(getline(plikZAdresatami, linia, '|'))
    {
        licznik = licznik + 1;

        if (licznik == 1)
        {
            adresat.id = atoi(linia.c_str());
        }
        else if (licznik == 2)
        {
            idUzytkownikaSprawdzenie = atoi(linia.c_str());
            if (idUzytkownikaSprawdzenie != idZalogowanegoUzytkownika)
                czyZapisacUzytkownika = false;
            else
                czyZapisacUzytkownika = true;
        }
        else if (licznik == 3)
        {
            adresat.imie = linia;
        }
        else if (licznik == 4)
        {
            adresat.nazwisko = linia;
        }
        else if (licznik == 5)
        {
            adresat.nrTelefonu = linia;
        }
        else if (licznik == 6)
        {
            adresat.email = linia;
        }
        else if (licznik == 7)
        {
            adresat.adres = linia;
        }

        if (licznik == 7 && czyZapisacUzytkownika == true)
        {
            licznik = 0;
            czyZapisacUzytkownika = false;
            adresaci.push_back(adresat);
        }
        else if (licznik == 7)
            licznik = 0;
    }
    plikZAdresatami.close();

    return adresaci;
}
