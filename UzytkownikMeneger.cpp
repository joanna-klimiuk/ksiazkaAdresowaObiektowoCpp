#include "UzytkownikMeneger.h"

void UzytkownikMeneger::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UzytkownikMeneger::wypiszWszystkichUzytkownikow()
{
    for (auto uzytkownik : uzytkownicy)
    {
        cout << uzytkownik.pobierzLogin() << endl;
    }
}

void UzytkownikMeneger::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";
    idZalogowanegoUzytkownika = 0;
    bool czyUzytkownikJestWBazie = false;

    cout << endl << "Podaj login: ";
    cin >> login;

    for (size_t i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            czyUzytkownikJestWBazie = true;

            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                cin >> haslo;

                if (uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    break;
                }
            }

            if (idZalogowanegoUzytkownika == 0)
            {
                cout << "Wprowadzono 3 razy bledne haslo." << endl;
                system("pause");
            }
        }
    }

    if (!czyUzytkownikJestWBazie)
    {
        cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
        system("pause");
    }
}

void UzytkownikMeneger::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;

    for (size_t i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMeneger::wylogujUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
}

int UzytkownikMeneger::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

Uzytkownik UzytkownikMeneger::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMeneger::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty())
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMeneger::czyIstniejeLogin(string login)
{
    for (size_t i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

 bool UzytkownikMeneger::czyUzytkownikJestZalogowany()
 {
     if (idZalogowanegoUzytkownika > 0)
        return true;

     else
        return false;
 }
