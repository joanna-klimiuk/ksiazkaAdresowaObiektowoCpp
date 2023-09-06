#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <fstream>
#include <sstream>

using namespace std;

class PlikTekstowy
{
protected:
    const string NAZWA_PLIKU;

    bool czyPlikJestPusty(fstream &plikTekstowy);

public:
    PlikTekstowy(string nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {};
};


#endif
