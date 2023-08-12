#include <iostream>

#include "UzytkownikMeneger.h"
#include "AdresatMeneger.h"

using namespace std;


class KsiazkaAdresowa
{
    UzytkownikMeneger uzytkownikMeneger;
    AdresatMeneger adresatMeneger;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMeneger(nazwaPlikuZUzytkownikami), adresatMeneger(nazwaPlikuZAdresatami)
    {
        uzytkownikMeneger.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogujUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
};
