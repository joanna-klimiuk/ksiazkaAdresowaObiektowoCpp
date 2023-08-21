#include <iostream>

#include "UzytkownikMeneger.h"
#include "AdresatMeneger.h"

using namespace std;


class KsiazkaAdresowa
{
    UzytkownikMeneger uzytkownikMeneger;
    AdresatMeneger *adresatMeneger;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
        : uzytkownikMeneger(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        adresatMeneger = NULL;
    };

    ~KsiazkaAdresowa()
    {
        delete adresatMeneger;
        adresatMeneger = NULL;
    }

    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogujUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    bool czyUzytkownikJestZalogowany();
    void opcjeMenu();
};
