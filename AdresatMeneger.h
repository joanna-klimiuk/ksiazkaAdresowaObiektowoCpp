#include <windows.h>
#include <fstream>
#include <sstream>

#include "PlikZAdresatami.h"
#include "UzytkownikMeneger.h"

using namespace std;

class AdresatMeneger
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata = 0;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    void dopiszAdresataDoPliku(Adresat adresat);
    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatMeneger(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};
    int dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void ustawIdZalogowanegoUzytkownika(int idUzytkownika);
    void wyczyscWektorAdresatow();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
};
