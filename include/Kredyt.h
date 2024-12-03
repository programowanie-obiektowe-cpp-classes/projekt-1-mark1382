#pragma once

class Kredyt
{
//Pola
private:
	double dlug = 0.0;
	int pozostale_raty;
	double odsetki;
	double kwota_raty;

public:
	double getDlug();
	int getRaty();
	//konstruktor
	Kredyt(double ile_kwota, int ile_rat);
	//Metoda do splacania raty
	double splacRate();
};
