#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <deque>
#include "Inzynier.h"
#include "Robotnik.h"
#include "Magazynier.h"
#include "Marketer.h"
#include "Pracownik.h"
#include "Firma.h"

Firma::Firma(double pieniadze_pocz=200000.0) //Konstruktor: domyslny stan konta + zatrudnia 4 pracownikow (po 1 kazdego typu)
{
    stan_konta = pieniadze_pocz;
    zatrudnijPracownika("Inzynier", "Jan", "MEiL");
    zatrudnijPracownika("Magazynier", "Maciej", "true");
    zatrudnijPracownika("Robotnik", "Grzegorz", "42");
    zatrudnijPracownika("Marketer", "Anna", "980");
}

void Firma::zatrudnijPracownika(const std::string& typ, const std::string& imie, const std::string& dodatkowePole)
{
    std::unique_ptr<Pracownik> pracownik;
    if (typ == "Inzynier") 
    {
        pracownicy.push_back(std::make_unique<Inzynier>(imie, dodatkowePole));
    }
    else if (typ == "Magazynier") 
    {
        const bool uprawnienia = (dodatkowePole == "true");  // konwersja stringa na bool   
        pracownicy.push_back(std::make_unique<Magazynier>(imie, uprawnienia));
    }
    else if (typ == "Robotnik")
    {
        const double roz_but = std::stod(dodatkowePole.c_str());
        pracownicy.push_back(std::make_unique<Robotnik>(imie, roz_but));
    }
    else if (typ == "Marketer") 
    {
        const int foll = std::stoi(dodatkowePole.c_str());
        pracownicy.push_back(std::make_unique<Marketer>(imie, foll));
    }
    else {
        throw std::invalid_argument("Nieznany typ pracownika: " + typ);
    }


}

void Firma::drukujPracownikow()
{
    for (const auto& pracownik : pracownicy) 
    {
        std::cout << pracownik->getImie() << " - " << pracownik->getPensja() << std::endl;
    }
}

void Firma::wezKredyt(double kwota, int raty)
{
    kredyty.push_back(std::make_unique<Kredyt>(kwota, raty));
    stan_konta += kwota;
}

void Firma::splacKredyty() 
{
    if (kredyty.empty() == true) 
        std::cout << "Nie ma zadnych kredytow"<<std::endl; //wykona siê ta czêœæ instrukcji warunkowej
    else
    {
        for (auto it = kredyty.begin(); it != kredyty.end(); )
        {
            double pozostalosc = (*it)->splacRate();  // Sp³acamy kredyt

            if (pozostalosc > 0) {
                std::cout << "Pozostaly dlug kredytu: " << pozostalosc << std::endl;
                ++it; // Przechodzimy do nastêpnego kredytu, jeœli ten nie zosta³ sp³acony
            }
            else {
                std::cout << "Kredyt zosta³ calkowicie splacony i usuniêty!" << std::endl;
                it = kredyty.erase(it); // Usuwamy kredyt, jeœli zosta³ sp³acony, i aktualizujemy iterator
            }
        }
    }
}


double Firma::obliczSumarycznyDlug()
{
    double suma = 0.0;
    for (const auto& kredyt : kredyty) {
        suma += kredyt->getDlug(); // Sumujemy d³ugi wszystkich kredytów
    }
    return suma;
}

double Firma::obliczPrzychod()
{
    produkcja_max = (double)Robotnik::getLiczbaRobotnik() * Robotnik::getCR();
    pojemnosc_magazyn = (double)Magazynier::getLiczbaMag() * Magazynier::getCMag();
    popyt = (double)Marketer::getLicznikMark() * Marketer::getCMkt();
    cena = (double)Inzynier::getLiczbaInzynierow() * Inzynier::getCI();
    if (pojemnosc_magazyn >= produkcja_max)
    {
        produkcja = produkcja_max;
    }
    else produkcja = pojemnosc_magazyn;
    if (popyt >= produkcja)
    {
        sprzedaz = produkcja;
    }
    else sprzedaz = popyt;
    double przychod = cena * sprzedaz;
    historia_przychodow.push_back(przychod);

    // Usuñ najstarszy element, jeœli kolejka przekroczy zdefiniowana liczbe miesiecy
    if (historia_przychodow.size() > n_miesiecy)
    {
        historia_przychodow.pop_front();
    }
    /*Test - - czy liczba instancji pracownikow jest dobrze generowana
    std::cout << "Liczba Robotnikow: " << Robotnik::getLiczbaRobotnik() << ", CR: " << Robotnik::getCR() << std::endl;
    std::cout << "Liczba Magazynierow: " << Magazynier::getLiczbaMag() << ", CMag: " << Magazynier::getCMag() << std::endl;
    std::cout << "Liczba Marketerow: " << Marketer::getLicznikMark() << ", CMkt: " << Marketer::getCMkt() << std::endl;
    std::cout << "Liczba Inzynierow: " << Inzynier::getLiczbaInzynierow() << ", CI: " << Inzynier::getCI() << std::endl;
    std::cout << "cena" << cena << std::endl;
    std::cout << "popyt" << popyt << std::endl;
    std::cout << "magazyn" << pojemnosc_magazyn << std::endl;
    std::cout << "produkcja max" << produkcja_max << std::endl;
    */
    return przychod;

}

void Firma::otrzymajPrzychod()
{
    stan_konta += obliczPrzychod();
}

void Firma::zaplac_wynagrodzenie()
{
    double suma_wynagrodzen = 0.0;

    // Iteracja przez pracowników
    for (const auto& pracownik : pracownicy) {
        suma_wynagrodzen += pracownik->getPensja();
    }

    // Sprawdzenie, czy firma ma wystarczaj¹ce œrodki
    if (stan_konta >= suma_wynagrodzen) {
        stan_konta -= suma_wynagrodzen;
    }
    else {
        std::cout << "Nie wystarczajace srodki na koncie! "
            << "Potrzebne: " << suma_wynagrodzen
            << ", dostepne: " << stan_konta << std::endl;
    }
}

double Firma::getStan_konta()
{
    return stan_konta;
}

double Firma::wartoscFirmy()
{ 
        if (historia_przychodow.empty()) {
            return 0.0; // Brak danych o przychodach
        }

        // Oblicz œredni¹
        double suma = std::accumulate(historia_przychodow.begin(), historia_przychodow.end(), 0.0);
        return suma / n_miesiecy;
}

double Firma::wartosc_Netto()
{
    return (wartoscFirmy() - obliczSumarycznyDlug());
}

const int Firma::getN_miesiecy()
{
    return n_miesiecy;
}




