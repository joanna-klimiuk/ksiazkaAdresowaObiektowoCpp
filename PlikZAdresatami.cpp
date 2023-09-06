#include "PlikZAdresatami.h"

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    vector <Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }

    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    else
        idOstatniegoAdresata = 0;

    return adresaci;
}

void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
        idOstatniegoAdresata++;

        if (czyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    plikTekstowy.close();
    system("pause");
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}

void PlikZAdresatami::usunWybranaLinieWPliku(int idAdresata)
{
    int numerLiniiWPlikuTekstowym = 1;
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int idAdresataZPierwszejLinii = 0;
    string nazwaTymczasowegoPlikuZAdresatami = "adresaci_tymczasowo.txt";

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true && idAdresata != 0)
    {
        while(getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            if(idAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia) && numerLiniiWPlikuTekstowym == 1)
            {
                idAdresataZPierwszejLinii = idAdresata;
            }

            else if(idAdresata == idAdresataZPierwszejLinii && numerLiniiWPlikuTekstowym == 2)
            {
                tymczasowyPlikTekstowy << wczytanaLinia;
            }

            else if(idAdresata != pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia) && numerLiniiWPlikuTekstowym == 1)
            {
                tymczasowyPlikTekstowy << wczytanaLinia;
            }

            else if(idAdresata != pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia))
            {
                tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }
            numerLiniiWPlikuTekstowym++;
        }
    }

        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        remove(NAZWA_PLIKU.c_str());
        rename(nazwaTymczasowegoPlikuZAdresatami.c_str(), NAZWA_PLIKU.c_str());
}

void PlikZAdresatami::ustawIdOstatniegoAdresata(int noweId)
{
    idOstatniegoAdresata = noweId;
}

void PlikZAdresatami::zaktualizujDaneWybranegoAdresata(Adresat adresat)
{
    edytujWybranaLinieWPliku(adresat);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

void PlikZAdresatami::edytujWybranaLinieWPliku(Adresat adresat)
{
    int numerLiniiWPlikuTekstowym = 1;
    int idAdresata = adresat.pobierzId();
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    string nazwaTymczasowegoPlikuZAdresatami = "adresaci_tymczasowo.txt";
    string liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true && idAdresata != 0)
    {
        while(getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            if(idAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia) && numerLiniiWPlikuTekstowym == 1)
            {
                tymczasowyPlikTekstowy << liniaZDanymiAdresata;
            }

            else if(idAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia) && numerLiniiWPlikuTekstowym > 1)
            {
                tymczasowyPlikTekstowy << endl << liniaZDanymiAdresata;
            }

            else if(idAdresata != pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia) && numerLiniiWPlikuTekstowym == 1)
            {
                tymczasowyPlikTekstowy << wczytanaLinia;
            }

            else if(idAdresata != pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia) && numerLiniiWPlikuTekstowym > 1)
            {
                tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }
            numerLiniiWPlikuTekstowym++;
        }
    }

        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        remove(NAZWA_PLIKU.c_str());
        rename(nazwaTymczasowegoPlikuZAdresatami.c_str(), NAZWA_PLIKU.c_str());
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNrTel() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

string PlikZAdresatami::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (size_t pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNrTel(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}
