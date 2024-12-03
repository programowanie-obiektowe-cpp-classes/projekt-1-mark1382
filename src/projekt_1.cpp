#include <iostream>
#include <string>
#include <limits>
#include "Firma.h"
#include "Pracownik.h"
#include "Inzynier.h"
#include "Magazynier.h"
#include "Marketer.h"
#include "Robotnik.h"
#include "Kredyt.h"
#include "Gra.h"


//Stałe statyczne - wydajnosc 
const double Robotnik::CR = 800;
const double Inzynier::CI = 500;
const double Magazynier::CMag = 950;
const double Marketer::CMkt = 300;
//Pola statyczne - liczba poszczegolnych typow pracownikow
int Inzynier::licznik_inz = 0;
int Robotnik::licznik_rob = 0;
int Magazynier::licznik_mag = 0;
int Marketer::licznik_mark = 0;
//Wartość netto firmy gwarantujaca wygrana
const double Gra::kwota_wygrywajaca = 3000.0;
const int Firma::n_miesiecy = 3;


//W mainie tworzymy tylko obiekt klasy Gra. Gier może być wiele.
//Każda gra przyjmuje w konstruktorze początkową ilość pieniędzy - jest ona przekierowywna do dynamiczngo wskaźnika tworzącego obiekt klasy Firma
int main()
{
    Gra gra1{ 200000.0 };
    gra1.menu();

}