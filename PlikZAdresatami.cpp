#include "PlikZAdresatami.h"



string PlikZAdresatami::wypiszNazwePlikuZAdresatami()
{
    return NAZWA_PLIKU_Z_ADRESATAMI;
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

    plikZAdresatami.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
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
    plik.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::app);
    if (plik.good() == true)
    {
        plik << adresat.wypiszIdAdresata() << "|" << idZalogowanegoUzytkownika << "|" << adresat.wypiszImieAdresata() << "|" << adresat.wypiszNazwiskoAdresata() << "|" << adresat.wypiszNrTelefonuAdresata()
         << "|" << adresat.wypiszEmailAdresata() << "|" << adresat.wypiszAdresAdresata() << "|" << endl;
    cout << "Adresat zostal dodany" << endl;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku " << NAZWA_PLIKU_Z_ADRESATAMI << " i zapisac adresata." << endl;
        system("pause");
    }
    plik.close();
}

void PlikZAdresatami::nadpisaniePlikuUsuniecieAdresata (int idEdytowanegoAdresata, int idZalogowanegoUzytkownika)
{
    fstream plik;
    fstream plikAdresaciTymczasowy;
    string linia;
    string idStringUsuwanegoAdresata;
    string idStringZalogowanegoUzytkownika;

    plik.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    plikAdresaciTymczasowy.open("Adresaci_tymczasowy.txt", ios::app);
    while(getline(plik, linia))
    {
        idStringUsuwanegoAdresata = linia[0];
        idStringZalogowanegoUzytkownika = linia[2];
        if (idEdytowanegoAdresata == atoi(idStringUsuwanegoAdresata.c_str()) && idZalogowanegoUzytkownika == atoi(idStringZalogowanegoUzytkownika.c_str()));
        else
        {
            plikAdresaciTymczasowy << linia << endl;
        }
    }
    plik.close();
    plikAdresaciTymczasowy.close();
    remove(NAZWA_PLIKU_Z_ADRESATAMI.c_str());
    rename ("Adresaci_tymczasowy.txt", NAZWA_PLIKU_Z_ADRESATAMI.c_str());
}

void PlikZAdresatami::nadpisaniePlikuEdycjaAdresata (Adresat adresat, int idEdytowanegoAdresata, int idZalogowanegoUzytkownika)
{

    fstream plik;
    fstream plikAdresaciTymczasowy;
    string linia;
    string idStringEdytowanegoAdresata;
    string idStringZalogowanegoUzytkownika;

    plik.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in | ios::out);
    plikAdresaciTymczasowy.open("Adresaci_tymczasowy.txt", ios::in | ios::app);
    while(getline(plik, linia))
    {
        idStringEdytowanegoAdresata = linia[0];
        idStringZalogowanegoUzytkownika = linia[2];
        if (idEdytowanegoAdresata == atoi(idStringEdytowanegoAdresata.c_str()) && idZalogowanegoUzytkownika == atoi(idStringZalogowanegoUzytkownika.c_str()))
        {
            plikAdresaciTymczasowy << adresat.wypiszIdAdresata() << "|" << idZalogowanegoUzytkownika << "|" <<  adresat.wypiszImieAdresata() << "|"
                                   << adresat.wypiszNazwiskoAdresata() << "|" << adresat.wypiszNrTelefonuAdresata() << "|"
                                   << adresat.wypiszEmailAdresata() << "|" << adresat.wypiszAdresAdresata() << "|" << endl;
        }
        else
        {
            plikAdresaciTymczasowy << linia << endl;
        }
    }
    plik.close();
    plikAdresaciTymczasowy.close();
    remove(NAZWA_PLIKU_Z_ADRESATAMI.c_str());
    rename ("Adresaci_tymczasowy.txt", NAZWA_PLIKU_Z_ADRESATAMI.c_str());
}
