#include "PlikZAdresatami.h"

string PlikZAdresatami::wypiszNazwePlikuZAdresatami()
{
    return PlikTekstowy::pobierzNazwePliku();
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawIdAdresata(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdZalogowanegoUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImieAdresata(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwiskoAdresata(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNrTelefonuAdresata(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmailAdresata(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdresAdresata(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

int PlikZAdresatami::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

string PlikZAdresatami::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
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
    bool czyZapisacAdresata = false;

    plikZAdresatami.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::in);

    if (plikZAdresatami.good() == true)
    {
        while(getline(plikZAdresatami, linia))
        {
            cout << linia[2];
            if (idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(linia))
            {
                adresat = pobierzDaneAdresata(linia);
                adresaci.push_back(adresat);

            }

        }
    }

    plikZAdresatami.close();

    return adresaci;
}

void PlikZAdresatami::zapisanieAdresataDoPliku(Adresat adresat, int idZalogowanegoUzytkownika)
{
    fstream plik;
    plik.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::app);
    if (plik.good() == true)
    {
        plik << adresat.wypiszIdAdresata() << "|" << idZalogowanegoUzytkownika << "|" << adresat.wypiszImieAdresata() << "|" << adresat.wypiszNazwiskoAdresata() << "|" << adresat.wypiszNrTelefonuAdresata()
             << "|" << adresat.wypiszEmailAdresata() << "|" << adresat.wypiszAdresAdresata() << "|" << endl;
        cout << "Adresat zostal dodany" << endl;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku " << PlikTekstowy::pobierzNazwePliku() << " i zapisac adresata." << endl;
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

    plik.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::in);
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
    remove(PlikTekstowy::pobierzNazwePliku().c_str());
    rename ("Adresaci_tymczasowy.txt", PlikTekstowy::pobierzNazwePliku().c_str());
}

void PlikZAdresatami::nadpisaniePlikuEdycjaAdresata (Adresat adresat, int idEdytowanegoAdresata, int idZalogowanegoUzytkownika)
{

    fstream plik;
    fstream plikAdresaciTymczasowy;
    string linia;
    string idStringEdytowanegoAdresata;
    string idStringZalogowanegoUzytkownika;

    plik.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::in | ios::out);
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
    remove(PlikTekstowy::pobierzNazwePliku().c_str());
    rename ("Adresaci_tymczasowy.txt", PlikTekstowy::pobierzNazwePliku().c_str());
}

void PlikZAdresatami::dopisz(string tekst)
{
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        if (czyPlikJestPusty())
            plikTekstowy << "To jest poczatek pliku" << endl;
        plikTekstowy << tekst << endl;
    }

    plikTekstowy.close();
}
