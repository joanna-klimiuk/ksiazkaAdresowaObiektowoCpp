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

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    if (uzytkownikMeneger.pobierzIdZalogowanegoUzytkownika() > 0)
        return true;

    else
        return false;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

void KsiazkaAdresowa::usunAdresata()
{
    if (uzytkownikMeneger.czyUzytkownikJestZalogowany())
    {
        adresatMeneger -> usunAdresata();
    }
}

