#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Adresat
{
    int id;
    string imie, nazwisko, email, adres, nrTelefonu;
};

vector<Adresat> dodajAdresata(Adresat adresat, vector<Adresat>adresatVector)
{
    string imie, nazwisko, email, adres, nrTelefonu;
    int id;
    cout << "Podaj imie: " << endl;
    cin >> imie;
    cout << "Podaj nazwisko" << endl;
    cin >> nazwisko;
    cout << "Podaj email: " << endl;
    cin >> email;
    cout << "Podaj adres: " << endl;
    cin.sync();
    getline(cin>>ws, adres);
    cout << "Podaj numer telefonu: " << endl;
    cin >> nrTelefonu;
    if (adresatVector.size() == 0)
    {
        id = 1;
    }
    else
        id = adresatVector[adresatVector.size()-1].id + 1;
    adresat.imie = imie;
    adresat.nazwisko = nazwisko;
    adresat.email = email;
    adresat.adres = adres;
    adresat.nrTelefonu = nrTelefonu;
    adresat.id = id;
    adresatVector.push_back(adresat);
    fstream plik;
    plik.open("przyjaciele.txt", ios::out | ios::app);
    plik << id << "|" << imie << "|" << nazwisko << "|" << email << "|" << adres << "|" << nrTelefonu << "|" << endl;

    cout << "Adresat zostal dodany" << endl;
    system("pause");

    return adresatVector;

}

void wyszukajAdresataPoImieniu (Adresat adresat, vector <Adresat> adresatVector)
{
    system("cls");
    string imie;
    bool licznikImion = false;
    system("cls");
    if (adresatVector.size() == 0)
    {
        cout << "Baza danych jest pusta" << endl;
        system("pause");
    }
    else
    {
        cout << "Wpisz imie:" << endl;
        cin >> imie;
        for (int i = 0; i <= adresatVector.size(); i++)
        {
            if (imie == adresatVector[i].imie)
            {
                licznikImion = true;
                cout << adresatVector[i].imie << " ";
                cout << adresatVector[i].nazwisko << ", ";
                cout << adresatVector[i].email << ", ";
                cout << adresatVector[i].adres << ", ";
                cout << adresatVector[i].nrTelefonu << "." << endl;
            }
        }
        if (licznikImion == false)
        {
            cout << "W bazie nie ma osoby o takim imieniu";
        }
        cout << endl;
        system("pause");
    }


}

void wyszukajAdresataPoNazwisku (Adresat adresat, vector <Adresat> adresatVector)
{
    system("cls");
    string nazwisko;
    bool licznikNazwisk = false;
    system("cls");
    if (adresatVector.size() == 0)
    {
        cout << "Baza danych jest pusta" << endl;
        system("pause");
    }
    else
    {
        cout << "Wpisz nazwisko:" << endl;
        cin >> nazwisko;
        for (int i = 0; i <= adresatVector.size(); i++)
        {
            if (nazwisko == adresatVector[i].nazwisko)
            {
                licznikNazwisk = true;
                cout << adresatVector[i].imie << " ";
                cout << adresatVector[i].nazwisko << ", ";
                cout << adresatVector[i].email << ", ";
                cout << adresatVector[i].adres << ", ";
                cout << adresatVector[i].nrTelefonu << "." << endl;
            }
        }
        if (licznikNazwisk == false)
        {
            cout << "W bazie nie ma osoby o takim nazwisku";
        }
        cout << endl;
        system("pause");
    }

}

void listaAdresatow(Adresat adresat, vector<Adresat> adresatVector)
{
    if (adresatVector.size() == 0)
    {
        system("cls");
        cout << "Baza danych jest pusta";
        cout << endl;
        system("pause");
    }
    else
    {
        system("cls");
        for (int i = 0; i <= adresatVector.size()-1; i++)
        {
            cout << adresatVector[i].id << ". ";
            cout << adresatVector[i].imie << " ";
            cout << adresatVector[i].nazwisko << ", ";
            cout << adresatVector[i].email << ", ";
            cout << adresatVector[i].adres << ", ";
            cout << adresatVector[i].nrTelefonu << endl;
        }
        cout << endl;
        system("pause");
    }
}

vector <Adresat> edycjaAdresata (Adresat adresat, vector<Adresat> adresatVector)
{
    string idString;
    string wybor;
    ofstream plik;
    bool znalezionoID = false;
    if (adresatVector.size() == 0)
    {
        system("cls");
        cout << "Baza danych jest pusta";
        cout << endl;
        system("pause");
    }
    else
    {
        cout << "Podaj ID adresata, ktorego chcesz edytowac: ";
        cin >> idString;
        int id = atoi(idString.c_str());
        for (int i = 0; i <= adresatVector.size()-1; i++)
        {
            if (id == adresatVector[i].id)
            {
                znalezionoID = true;
                system("cls");
                cout << "1 - imie" << endl;
                cout << "2 - nazwisko" << endl;
                cout << "3 - email" << endl;
                cout << "4 - adres" << endl;
                cout << "5 - numer telefonu" << endl;
                cout << "6 - powrot do menu" << endl;
                cin >> wybor;
                if (wybor == "1")
                {
                    cout << "Podaj nowe imie: ";
                    cin >> adresatVector[i].imie;
                }
                else if (wybor == "2")
                {
                    cout << "Podaj nowe nazwisko: ";
                    cin >> adresatVector[i].nazwisko;
                }
                else if (wybor == "3")
                {
                    cout << "Podaj nowy email: ";
                    cin >> adresatVector[i].email;
                }
                else if (wybor == "4")
                {
                    cout << "Podaj nowy adres: ";
                    cin >> adresatVector[i].adres;
                }
                else if (wybor == "5")
                {
                    cout << "Podaj nowy numer telefonu: ";
                    cin >> adresatVector[i].nrTelefonu;
                }
                else if (wybor == "6")
                {
                    break;
                }
                else
                {
                    cout << "Nieprawidlowy wybor." << endl;
                    system("pause");
                }
                if (adresatVector.size() != 0)
                {
                    plik.close();
                    plik.open("przyjaciele.txt");
                    for (int i = 0; i <= adresatVector.size()-1; i++)
                    {
                        plik << adresatVector[i].id << "|" << adresatVector[i].imie << "|" << adresatVector[i].nazwisko <<
                             "|" << adresatVector[i].email << "|" << adresatVector[i].adres << "|" << adresatVector[i].nrTelefonu <<
                             "|" << endl;
                    }
                }
            }
        }
        if (znalezionoID == false)
        {
            cout << "Nieprawidlowe ID" << endl;
            system("pause");
        }
    }
    return adresatVector;
}


vector <Adresat> usuniecieAdresata (Adresat adresat, vector<Adresat> adresatVector)
{
    string idString;
    string wybor;
    ofstream plik;
    bool znalezionoID = false;
    int i = 0;
    if (adresatVector.size() == 0)
    {
        system("cls");
        cout << "Baza danych jest pusta";
        cout << endl;
        system("pause");
    }
    else
    {
        cout << "Podaj ID adresata, ktorego chcesz usunac: ";
        cin >> idString;
        int id = atoi(idString.c_str());
        for (vector<Adresat>::iterator it = adresatVector.begin(), koniec = adresatVector.end(); it != koniec; it++)
        {
            if (id == adresatVector[i].id)
            {
                znalezionoID = true;
                system("cls");
                cout << "Czy na pewno chcesz usunac adresata? (t/n)" << endl;
                cin >> wybor;
                if (wybor == "t")
                {
                    adresatVector.erase(it);
                }
                else
                {
                    break;
                }
                if (adresatVector.size() != 0)
                {
                    plik.close();
                    plik.open("przyjaciele.txt");
                    for (int i = 0; i <= adresatVector.size()-1; i++)
                    {
                        plik << adresatVector[i].id << "|" << adresatVector[i].imie << "|" << adresatVector[i].nazwisko <<
                             "|" << adresatVector[i].email << "|" << adresatVector[i].adres << "|" << adresatVector[i].nrTelefonu <<
                             "|" << endl;
                    }
                }
                else
                {
                    plik.close();
                    plik.open("przyjaciele.txt");

                }
            }
            i ++;
        }
        if (znalezionoID == false)
        {
            cout << "Nieprawidlowe ID" << endl;
            system("pause");
        }
    }
    return adresatVector;
}

int main()
{
    Adresat adresat;
    vector <Adresat> adresatVector;
    int liczbaPrzyjaciol = 0;
    fstream plik;
    plik.open("przyjaciele.txt", ios::in | ios::out);
    if (plik.good() == false)
    {
        cout << "Baza danych jest pusta" << endl;
        system("pause");
        system("cls");
    }
    string linia;
    int licznik = 0;
    int nr_przyjaciela = 0;
    while(getline(plik, linia, '|'))
    {
        licznik = licznik + 1;

        if (licznik == 1)
        {
            adresat.id = atoi(linia.c_str());
        }
        else if (licznik == 2)
        {
            adresat.imie = linia;
        }
        else if (licznik == 3)
        {
            adresat.nazwisko = linia;
        }
        else if (licznik == 4)
        {
            adresat.email = linia;
        }
        else if (licznik == 5)
        {
            adresat.adres = linia;
        }
        else if (licznik == 6)
        {
            adresat.nrTelefonu = linia;
        }

        if (licznik == 6)
        {
            licznik = 0;
            adresatVector.push_back(adresat);
        }
    }

    while(1)
    {
        system("cls");
        cout << "KSIAZKA ADRESOWA" << endl << endl;
        cout << "1. Dodaj adresata." << endl;
        cout << "2. Wyszukaj po imieniu." << endl;
        cout << "3. Wysukaj po nazwisku." << endl;
        cout << "4. Wyswietl wszystkich adresatow." << endl;
        cout << "5. Usun adresata." << endl;
        cout << "6. Edytuj adresata." << endl;
        cout << "9. Zakoncz program." << endl;

        char wybor;
        cin >> wybor;
        if (wybor == '1')
        {
            adresatVector = dodajAdresata(adresat, adresatVector);
        }
        else if (wybor == '2')
        {
            wyszukajAdresataPoImieniu(adresat, adresatVector);
        }
        else if (wybor == '3')
        {
            wyszukajAdresataPoNazwisku(adresat, adresatVector);
        }
        else if (wybor == '4')
        {
            listaAdresatow(adresat, adresatVector);
        }
        else if (wybor == '5')
        {
            adresatVector = usuniecieAdresata(adresat, adresatVector);
        }
        else if (wybor == '6')
        {
            adresatVector = edycjaAdresata (adresat, adresatVector);
        }
        else if (wybor == '9')
        {
            exit(0);
        }
        else
        {
            cout << "Nieprawidlowy wybor." << endl;
            cout << endl;
            system("pause");
        }
    }
    plik.close();
    return 0;
}
