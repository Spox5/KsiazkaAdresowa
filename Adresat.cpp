#include "Adresat.h"

void Adresat::ustawIdAdresata(int noweIdAdresata)
{
    id = noweIdAdresata;
}

int Adresat::wypiszIdAdresata()
{
    return id;
}

void Adresat::ustawImieAdresata(string noweImieAdresata)
{
    imie = noweImieAdresata;
}

string Adresat::wypiszImieAdresata()
{
    return imie;
}

void Adresat::ustawNazwiskoAdresata(string noweNazwiskoAdresata)
{
    nazwisko = noweNazwiskoAdresata;
}

string Adresat::wypiszNazwiskoAdresata()
{
    return nazwisko;
}

void Adresat::ustawNrTelefonuAdresata(string nowyNrTelefonuAdresata)
{
    nrTelefonu = nowyNrTelefonuAdresata;
}

string Adresat::wypiszNrTelefonuAdresata()
{
    return nrTelefonu;
}

void Adresat::ustawEmailAdresata(string nowyEmailAdresata)
{
    email = nowyEmailAdresata;
}

string Adresat::wypiszEmailAdresata()
{
    return email;
}

void Adresat::ustawAdresAdresata(string nowyAdresAdresata)
{
    adres = nowyAdresAdresata;
}

string Adresat::wypiszAdresAdresata()
{
    return adres;
}

vector<Adresat> Adresat::dodajAdresata(vector<Adresat>adresaci, int idZalogowanegoUzytkownika)
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

    plik.open("Adresaci.txt", ios::out | ios::app);
    plik << adresat.wypiszIdAdresata() << "|" << idZalogowanegoUzytkownika << "|" << adresat.wypiszImieAdresata() << "|" << adresat.wypiszNazwiskoAdresata() << "|" << adresat.wypiszNrTelefonuAdresata()
         << "|" << adresat.wypiszEmailAdresata() << "|" << adresat.wypiszAdresAdresata() << "|" << endl;
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
