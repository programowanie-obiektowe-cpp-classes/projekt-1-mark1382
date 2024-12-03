#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <deque>
#include <sstream>
#include "Pracownik.h"
#include "Firma.h"

class Gra
{
private:
    std::unique_ptr<Firma> firma; // Tworzymy obiekt firmy w klasie Gra
    int licznik_tur = 1;
    static const double kwota_wygrywajaca; //stale pole statyczne

public:
    Gra(double poczatkowy_stan); // Konstruktor inicjalizuj¹cy firmê
    static const double getKwota_Wygryw();
    void menu();
 
};

