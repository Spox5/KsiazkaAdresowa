#include "PlikZAdresatami.h"

PlikZAdresatami::PlikZAdresatami()
{
    nazwaPlikuZAdresatami = "Adresaci.txt";
}

string PlikZAdresatami::wypiszNazwePlikuZAdresatami()
{
    return nazwaPlikuZAdresatami;
}

vector <Adresat> PlikZAdresatami::wczytaniePlikuZAdresatami(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    vector <Adresat> adresaci;
    fstream plikZAdresatami;
    string liniaCalosc = "";
    string linia = "";
    int idUzytkownikaSprawdzenie = 0;
    int licznik = 0;
    bool czyZapisacUzytkownika = false;

    plikZAdresatami.open(nazwaPlikuZAdresatami.c_str(), ios::in);
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
            adresat.ustawIdAdresata(atoi(linia.c_str()));
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
            adresat.ustawImieAdresata(linia);
        }
        else if (licznik == 4)
        {
            adresat.ustawNazwiskoAdresata(linia);
        }
        else if (licznik == 5)
        {
            adresat.ustawNrTelefonuAdresata(linia);
        }
        else if (licznik == 6)
        {
            adresat.ustawEmailAdresata(linia);
        }
        else if (licznik == 7)
        {
            adresat.ustawAdresAdresata(linia);
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

void PlikZAdresatami::zapisanieAdresataDoPliku(Adresat adresat, int idZalogowanegoUzytkownika)
{
    fstream plik;
    plik.open(nazwaPlikuZAdresatami.c_str(), ios::app);
    if (plik.good() == true)
    {
        plik << adresat.wypiszIdAdresata() << "|" << idZalogowanegoUzytkownika << "|" << adresat.wypiszImieAdresata() << "|" << adresat.wypiszNazwiskoAdresata() << "|" << adresat.wypiszNrTelefonuAdresata()
         << "|" << adresat.wypiszEmailAdresata() << "|" << adresat.wypiszAdresAdresata() << "|" << endl;
    cout << "Adresat zostal dodany" << endl;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZAdresatami << " i zapisac adresata." << endl;
        system("pause");
    }
    plik.close();
}
