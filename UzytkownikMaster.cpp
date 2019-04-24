#include "UzytkownikMaster.h"
#include "AdresatMaster.h"

char UzytkownikMaster::menuUzytkownicyWybor()
{
    char wyborUzytkownicy;

    system("cls");
    cout << "1. Logowanie." << endl;
    cout << "2. Rejestracja." << endl;
    cout << "9. Zamknij program." << endl;
    cin >> wyborUzytkownicy;

    return wyborUzytkownicy;
}

vector <Uzytkownik> UzytkownikMaster::menuUzytkownicy(char wyborUzytkownicy, vector <Uzytkownik> uzytkownicy)
{
    Uzytkownik uzytkownik;
    AdresatMaster adresatMaster;
    int idZalogowanegoUzytkownika = 0;

    if (wyborUzytkownicy == '1')
    {
        idZalogowanegoUzytkownika = uzytkownik.logowanieUzytkownika(uzytkownicy);
        if (idZalogowanegoUzytkownika != 0)
            uzytkownicy = adresatMaster.adresaciMenu(idZalogowanegoUzytkownika, uzytkownicy);
    }
    else if (wyborUzytkownicy == '2')
    {
        uzytkownicy = uzytkownik.rejestracjaUzytkownika(uzytkownicy);
    }
    else if (wyborUzytkownicy == '9')
    {
        exit(0);
    }
    else
    {
        cout << "Nieprawidlowy wybor" << endl;;
        system("pause");
    }
    return uzytkownicy;
}
