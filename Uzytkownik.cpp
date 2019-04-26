#include "Uzytkownik.h"

void Uzytkownik::ustawIdUzytkownika(int noweIdUzytkownika)
{
    idUzytkownika = noweIdUzytkownika;
}

int Uzytkownik::wypiszIdUzytkownika()
{
    return idUzytkownika;
}

void Uzytkownik::ustawNazweUzytkownika(string nowaNazwaUzytkownika)
{
    nazwaUzytkownika = nowaNazwaUzytkownika;
}

string Uzytkownik::wypiszNazweUzytkownika()
{
    return nazwaUzytkownika;
}

void Uzytkownik::ustawHasloUzytkownika(string noweHaslouzytkownika)
{
    hasloUzytkownika = noweHaslouzytkownika;
}

string Uzytkownik::wypiszHasloUzytkownika()
{
    return hasloUzytkownika;
}


