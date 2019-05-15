#include "PlikZAdresatami.h"
#include "FunkcjePomocnicze.h"

string PlikZAdresatami::wypiszNazwePlikuZAdresatami()
{
    return PlikTekstowy::pobierzNazwePliku();
}

int PlikZAdresatami::pobierzZPlikuIdOstatniegoAdresata()
{
    FunkcjePomocnicze funkcjePomocnicze;
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;

    plikTekstowy.open(wypiszNazwePlikuZAdresatami().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        }
        plikTekstowy.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = funkcjePomocnicze.pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        return idOstatniegoAdresata;
    }
    else
        return 0;
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

vector <Adresat> PlikZAdresatami::wczytaniePlikuZAdresatami(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    vector <Adresat> adresaci;
    fstream plikZAdresatami;
    string linia = "";

    plikZAdresatami.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::in);

    if (plikZAdresatami.good() == true)
    {
        while(getline(plikZAdresatami, linia))
        {
            cout << linia[2];
            if (idZalogowanegoUzytkownika == funkcjePomocnicze.pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(linia))
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
    int idUsuwanegoAdresata;
    int idZalogowanegoUzytkownikaSprawdzenie;

    plik.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::in);
    plikAdresaciTymczasowy.open("Adresaci_tymczasowy.txt", ios::app);
    while(getline(plik, linia))
    {
        idUsuwanegoAdresata = funkcjePomocnicze.pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(linia);
        idZalogowanegoUzytkownikaSprawdzenie = funkcjePomocnicze.pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(linia);
        if (idEdytowanegoAdresata == idUsuwanegoAdresata && idZalogowanegoUzytkownika == idZalogowanegoUzytkownikaSprawdzenie);
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
    int idEdytowanegoAdresataSprawdzenie;
    int idZalogowanegoUzytkownikaSprawdzenie;

    plik.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::in);
    plikAdresaciTymczasowy.open("Adresaci_tymczasowy.txt", ios::app);
    while(getline(plik, linia))
    {
        idEdytowanegoAdresataSprawdzenie = funkcjePomocnicze.pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(linia);
        idZalogowanegoUzytkownikaSprawdzenie = funkcjePomocnicze.pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(linia);
        if (idEdytowanegoAdresata == idEdytowanegoAdresataSprawdzenie && idZalogowanegoUzytkownika == idZalogowanegoUzytkownikaSprawdzenie)
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
