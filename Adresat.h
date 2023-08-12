#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat
{
    int id;
    int idUzytkownika = 0;
    string imie, nazwisko, numerTelefonu, email, adres;

public:
    int pobierzId();
    int pobierzIdUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNrTel();
    string pobierzEmail();
    string pobierzAdres();

    void ustawId(int noweId);
    void ustawIdUzytkownika(int noweIdUzytkownika);
    void ustawImie(string noweImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawNrTel(string nowyNrTel);
    void ustawEmail(string nowyEmail);
    void ustawAdres(string nowyAdres);
};

#endif
