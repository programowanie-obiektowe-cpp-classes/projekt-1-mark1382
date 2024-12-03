#pragma once
#include <iostream>
#include <vector>
#include <numeric>
#include <deque>
#include <string>
#include <memory>
#include "Pracownik.h"
#include "Kredyt.h"

class Firma
{
private:
	//Pola
	double stan_konta;
	double dlug_calkowity;
	int n_pracownikow;
	int n_kredytow;
	double produkcja_max;
	double cena;
	double popyt;
	double pojemnosc_magazyn;
	double produkcja;
	double sprzedaz;
	static const int n_miesiecy;     // Liczba miesiêcy do przechowywania
	std::deque<double> historia_przychodow; // Kolejka przychodów
	std::vector<std::unique_ptr<Pracownik>> pracownicy;
	std::vector<std::unique_ptr<Kredyt>> kredyty;


public:
	//Metody
	//Niech konstruktor ustawia stan poczatkowy (do zmiennej stan konta) oraz niech wygeneruje 4 pracownikow -- po 1 kazdego typu
    Firma(double pieniadze_pocz);
	//Niezale¿nie musi byæ metoda, generuj¹ca pracowników
	void zatrudnijPracownika(const std::string& typ, const std::string& imie, const std::string& dodatkowePole = "");
	void drukujPracownikow();
	void wezKredyt(double kwota, int raty);
	void splacKredyty();
	void otrzymajPrzychod();
	void zaplac_wynagrodzenie();
	double getStan_konta();
	double wartoscFirmy();
	double obliczPrzychod();
	double obliczSumarycznyDlug(); //uwzgledniamy wszystkie kredyty
	double wartosc_Netto(); //funkcja sluzy jako indykator gry
	const int getN_miesiecy();
};