#include "Uzytkownik.h"

vector <Uzytkownik> Uzytkownik::rejestracjaUzytkownika (vector <Uzytkownik> uzytkownicy)
{
    Uzytkownik uzytkownik;
    string nazwaUzytkownika, hasloUzytkownika;
    int idUzytkownika;

    cout << "Podaj nazwe uzytkownika: " << endl;
    cin >> uzytkownik.nazwaUzytkownika;
    if (uzytkownicy.size() != 0)
    {
        int i = 0;
        while (i <= uzytkownicy.size())
        {
            if (uzytkownik.nazwaUzytkownika == uzytkownicy[i].nazwaUzytkownika)
            {
                cout << "Taki uzytkownik juz istnieje. Podaj inna nazwe uzytkownika" << endl;
                cin >> uzytkownik.nazwaUzytkownika;
                i = 0;
            }
            else
                i++;
        }
    }
    cout << "Podaj haslo uzytkownika: " << endl;
    cin >> uzytkownik.hasloUzytkownika;
    if (uzytkownicy.size() == 0)
    {
        uzytkownik.idUzytkownika = 1;
    }
    else
        uzytkownik.idUzytkownika = uzytkownicy.size() + 1;
    uzytkownicy.push_back(uzytkownik);
    fstream plikUzytkownicy;
    plikUzytkownicy.open("Uzytkownicy.txt", ios::out | ios::app);
    plikUzytkownicy << uzytkownik.idUzytkownika << "|" << uzytkownik.nazwaUzytkownika << "|" << uzytkownik.hasloUzytkownika << "|" << endl;
    cout << "Uzytkownik zostal dodany" << endl;
    system("pause");
    //
    for (int i = 0; i <= uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].nazwaUzytkownika << endl;
    }
    system("pause");
    //
    return uzytkownicy;
}

int Uzytkownik::logowanieUzytkownika (vector <Uzytkownik> uzytkownicy)
{
    string nazwaUzytkownika, hasloUzytkownika;
    //
    cout << uzytkownicy.size() << endl;
    //
    cout << "Podaj nazwe uzytkownika: " << endl;
    cin >> nazwaUzytkownika;

    int i = 0;
    while (i < uzytkownicy.size())
    {
        if (nazwaUzytkownika == uzytkownicy[i].nazwaUzytkownika)
        {
            for (int proby = 0; proby < 3; proby++)
            {
                cout << "Podaj haslo. Pozostalo prob: " << 3 -  proby << endl;
                cin >> hasloUzytkownika;
                if (hasloUzytkownika == uzytkownicy[i].hasloUzytkownika)
                {
                    cout << "Zalogowales sie." << endl;
                    system("pause");
                    system("cls");
                    return uzytkownicy[i].idUzytkownika;
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

vector <Uzytkownik> Uzytkownik::zmianaHaslaUzytkownika(vector <Uzytkownik> uzytkownicy, int idZalogowanegoUzytkownika)
{
    ofstream plikUzytkownicy;
    string noweHaslo;

    cout << "Podaj nowe haslo:" << endl;
    cin >> noweHaslo;

    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (idZalogowanegoUzytkownika == uzytkownicy[i].idUzytkownika)
        {
            uzytkownicy[i].hasloUzytkownika = noweHaslo;
            plikUzytkownicy.close();
            plikUzytkownicy.open("Uzytkownicy.txt");
            for (int i = 0; i <= uzytkownicy.size()-1; i++)
            {
                plikUzytkownicy << uzytkownicy[i].idUzytkownika << "|" << uzytkownicy[i].nazwaUzytkownika << "|"
                                << uzytkownicy[i].hasloUzytkownika << "|" << endl;
            }
            cout << "Haslo zostalo zmienione." << endl;
            system("pause");
        }
    }
    plikUzytkownicy.close();
    return uzytkownicy;
}
