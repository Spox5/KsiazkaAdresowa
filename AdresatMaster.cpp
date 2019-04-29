#include "AdresatMaster.h"
#include "UzytkownikMaster.h"

char AdresatMaster::menuAdresatWybor()
{
    char wybor;

    system("cls");
    cout << "KSIAZKA ADRESOWA" << endl << endl;
    cout << "1. Dodaj adresata." << endl;
    cout << "2. Wyszukaj po imieniu." << endl;
    cout << "3. Wysukaj po nazwisku." << endl;
    cout << "4. Wyswietl wszystkich adresatow." << endl;
    cout << "5. Usun adresata." << endl;
    cout << "6. Edytuj adresata." << endl;
    cout << "7. Zmien haslo." << endl;
    cout << "9. Wyloguj sie." << endl;
    cin >> wybor;

    return wybor;
}

vector<Adresat> AdresatMaster::dodajAdresata(vector<Adresat>adresaci, int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    string imie, nazwisko, nrTelefonu, email, adres;
    int id;
    fstream plik;
    string linia;
    string idOstatniegoAdresataString;
    int idOstatniegoAdresata = 0;

    cout << "Podaj imie: " << endl;
    cin >> imie;
    adresat.ustawImieAdresata(imie);
    cout << "Podaj nazwisko" << endl;
    cin >> nazwisko;
    adresat.ustawNazwiskoAdresata(nazwisko);
    cout << "Podaj numer telefonu: " << endl;
    cin >> nrTelefonu;
    adresat.ustawNrTelefonuAdresata(nrTelefonu);
    cout << "Podaj email: " << endl;
    cin >> email;
    adresat.ustawEmailAdresata(email);
    cout << "Podaj adres: " << endl;
    cin.sync();
    getline(cin>>ws, adres);
    adresat.ustawAdresAdresata(adres);

    plik.open("Adresaci.txt", ios::in | ios:: out);
    while(getline(plik, linia))
    {
        idOstatniegoAdresataString = linia[0];
    }
    idOstatniegoAdresata = atoi(idOstatniegoAdresataString.c_str());
    plik.close();

    if (idOstatniegoAdresata == 0)
    {
        adresat.ustawIdAdresata(1);
    }
    else
        adresat.ustawIdAdresata(idOstatniegoAdresata + 1);

    adresaci.push_back(adresat);






    return adresaci;
}

void AdresatMaster::listaAdresatow(vector<Adresat> adresaci)
{
    if (adresaci.size() == 0)
    {
        system("cls");
        cout << "Baza danych jest pusta." << endl;
        system("pause");
    }
    else
    {
        system("cls");
        for (int i = 0; i <= adresaci.size()-1; i++)
        {
            cout << adresaci[i].wypiszIdAdresata() << ". ";
            cout << adresaci[i].wypiszImieAdresata() << " ";
            cout << adresaci[i].wypiszNazwiskoAdresata() << ", ";
            cout << adresaci[i].wypiszNrTelefonuAdresata() << ", ";
            cout << adresaci[i].wypiszEmailAdresata() << ", ";
            cout << adresaci[i].wypiszAdresAdresata() << "." << endl;
        }
        cout << endl;
        system("pause");
    }
}
