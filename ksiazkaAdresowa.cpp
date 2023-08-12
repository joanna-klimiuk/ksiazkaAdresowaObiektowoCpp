#include "KsiazkaAdresowa.h"


void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMeneger.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMeneger.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMeneger.logowanieUzytkownika();
    adresatMeneger.ustawIdZalogowanegoUzytkownika(uzytkownikMeneger.pobierzIdZalogowanegoUzytkownika());
    adresatMeneger.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMeneger.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika()
{
    uzytkownikMeneger.wylogujUzytkownika();
    adresatMeneger.wyczyscWektorAdresatow();
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMeneger.dodajAdresata();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMeneger.wyswietlWszystkichAdresatow();
}

