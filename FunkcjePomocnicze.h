#ifndef FUNKCJEPOMOCNICZE_H
#define FUNKCJEPOMOCNICZE_H

#include <sstream>

using namespace std;

class FunkcjePomocnicze
{


public:

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int konwersjaStringNaInt(string liczba);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
};

#endif
