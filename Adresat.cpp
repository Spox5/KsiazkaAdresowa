#include "Adresat.h"

vector<Adresat> Adresat::dodajAdresata(vector<Adresat>adresaci, int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    string imie, nazwisko, email, adres, nrTelefonu;
    int id;
    fstream plik;
    string linia;
    string idOstatniegoAdresataString;
    int idOstatniegoAdresata = 0;

    cout << "Podaj imie: " << endl;
    cin >> adresat.imie;
    cout << "Podaj nazwisko" << endl;
    cin >> adresat.nazwisko;
    cout << "Podaj numer telefonu: " << endl;
    cin >> adresat.nrTelefonu;
    cout << "Podaj email: " << endl;
    cin >> adresat.email;
    cout << "Podaj adres: " << endl;
    cin.sync();
    getline(cin>>ws, adresat.adres);

    plik.open("Adresaci.txt", ios::in | ios:: out);
    while(getline(plik, linia))
    {
        idOstatniegoAdresataString = linia[0];
    }
    idOstatniegoAdresata = atoi(idOstatniegoAdresataString.c_str());
    plik.close();

    if (idOstatniegoAdresata == 0)
    {
        adresat.id = 1;
    }
    else
        adresat.id = idOstatniegoAdresata + 1;

    adresaci.push_back(adresat);

    plik.open("Adresaci.txt", ios::out | ios::app);
    plik << adresat.id << "|" << idZalogowanegoUzytkownika << "|" << adresat.imie << "|" << adresat.nazwisko << "|" << adresat.nrTelefonu
         << "|" << adresat.email << "|" << adresat.adres << "|" << endl;
    cout << "Adresat zostal dodany" << endl;
    system("pause");
    plik.close();

    return adresaci;
}

void Adresat::listaAdresatow(vector<Adresat> adresaci)
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
            cout << adresaci[i].id << ". ";
            cout << adresaci[i].imie << " ";
            cout << adresaci[i].nazwisko << ", ";
            cout << adresaci[i].nrTelefonu << ", ";
            cout << adresaci[i].email << ", ";
            cout << adresaci[i].adres << "." << endl;
        }
        cout << endl;
        system("pause");
    }
}
