#include "UzytkownikMaster.h"
#include "AdresatMaster.h"

void UzytkownikMaster::rejestracjaUzytkownika ()
{
    Uzytkownik uzytkownik;
    string nazwaUzytkownika, hasloUzytkownika;

    cout << "Podaj nazwe uzytkownika: " << endl;
    cin >> nazwaUzytkownika;
    if (uzytkownicy.size() != 0)
    {
        int i = 0;
        while (i < uzytkownicy.size())
        {
            if (nazwaUzytkownika == uzytkownicy[i].wypiszNazweUzytkownika())
            {
                cout << "Taki uzytkownik juz istnieje. Podaj inna nazwe uzytkownika" << endl;
                cin >> nazwaUzytkownika;
                i = 0;
            }
            else
                i++;
        }
    }
    uzytkownik.ustawNazweUzytkownika(nazwaUzytkownika);

    cout << "Podaj haslo uzytkownika: " << endl;
    cin >> hasloUzytkownika;
    uzytkownik.ustawHasloUzytkownika(hasloUzytkownika);

    if (uzytkownicy.size() == 0)
    {
        uzytkownik.ustawIdUzytkownika(1);
    }
    else
        uzytkownik.ustawIdUzytkownika(uzytkownicy.size() + 1);
    uzytkownicy.push_back(uzytkownik);
    cout << "Nowy uzytkownik zostal utworzony" << endl;
    system("pause");

    plikZUzytkownikami.zapisanieUzytkownikaDoPliku(uzytkownik);

}

int UzytkownikMaster::logowanieUzytkownika ()
{
    string nazwaUzytkownika, hasloUzytkownika;

    cout << "Podaj nazwe uzytkownika: " << endl;
    cin >> nazwaUzytkownika;

    int i = 0;
    while (i < uzytkownicy.size())
    {
        if (nazwaUzytkownika == uzytkownicy[i].wypiszNazweUzytkownika())
        {
            for (int proby = 0; proby < 3; proby++)
            {
                cout << "Podaj haslo. Pozostalo prob: " << 3 -  proby << endl;
                cin >> hasloUzytkownika;
                if (hasloUzytkownika == uzytkownicy[i].wypiszHasloUzytkownika())
                {
                    cout << "Zalogowales sie." << endl;
                    system("pause");
                    system("cls");
                    idZalogowanegoUzytkownika = uzytkownicy[i].wypiszIdUzytkownika();
                    return uzytkownicy[i].wypiszIdUzytkownika();
                }
                else
                    cout << "Nieprawidlowe haslo." << endl;;
            }
            cout << "Podales 3 razy bledne haslo. Odczekaj 3 sekundy." << endl;;
            Sleep(3000);
            return 0;
        }
        i++;
    }
    cout << "Nie ma uzytkownika o takiej nazwie." << endl;
    system ("pause");
    return 0;
}

vector <Uzytkownik> UzytkownikMaster::zmianaHaslaUzytkownika()
{
    string noweHaslo;

    cout << "Podaj nowe haslo:" << endl;
    cin >> noweHaslo;
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (idZalogowanegoUzytkownika == uzytkownicy[i].wypiszIdUzytkownika())
        {
            uzytkownicy[i].ustawHasloUzytkownika(noweHaslo);
            plikZUzytkownikami.zapisanieZmienionegoHaslaDoPliku(uzytkownicy);
        }
    }
    return uzytkownicy;
}

int UzytkownikMaster::wylogowanieUzytkownika()
{
    return idZalogowanegoUzytkownika = 0;
}

bool UzytkownikMaster::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

int UzytkownikMaster::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}
