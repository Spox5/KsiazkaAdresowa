#include <iostream>
#include <vector>

using namespace std;

class Uzytkownik
{
public:
    int idUzytkownika;
    string nazwaUzytkownika, hasloUzytkownika;

    vector <Uzytkownik> rejestracjaUzytkownika (Uzytkownik uzytkownik, vector <Uzytkownik> uzytkownikVector);
    int logowanieUzytkownika (vector <Uzytkownik> uzytkownikVector);
};
