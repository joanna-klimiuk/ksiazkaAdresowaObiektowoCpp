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

void KsiazkaAdresowa::opcjeMenu()
{
    char wybor;

    while (true)
    {
        if (!czyUzytkownikJestZalogowany())
        {
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                rejestracjaUzytkownika();
                break;

            case '2':
                logowanieUzytkownika();
                break;

            case '9':
                exit(0);
                break;

            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }

        else
        {
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                dodajAdresata();
                break;
     /*       case '2':
                wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
                wyszukajAdresatowPoNazwisku(adresaci);
                break; */
            case '4':
                wyswietlWszystkichAdresatow();
                break;
    /*        case '5':
                idUsunietegoAdresata = usunAdresata(adresaci);
                idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                edytujAdresata(adresaci);
                break; */
            case '7':
                zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                wylogujUzytkownika();
                break;
            }
        }
    }
}

