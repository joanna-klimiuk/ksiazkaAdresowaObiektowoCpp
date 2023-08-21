#include "KsiazkaAdresowa.h"


void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMeneger.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMeneger.logowanieUzytkownika();

    if (uzytkownikMeneger.czyUzytkownikJestZalogowany())
    {
        adresatMeneger = new AdresatMeneger(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMeneger.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMeneger.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMeneger.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika()
{
    uzytkownikMeneger.wylogujUzytkownika();
    delete adresatMeneger;
    adresatMeneger = NULL;
}

void KsiazkaAdresowa::dodajAdresata()
{
    if (uzytkownikMeneger.czyUzytkownikJestZalogowany())
    {
        adresatMeneger -> dodajAdresata();
    }
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
     if (uzytkownikMeneger.czyUzytkownikJestZalogowany())
    {
        adresatMeneger -> wyswietlWszystkichAdresatow();
    }
}

