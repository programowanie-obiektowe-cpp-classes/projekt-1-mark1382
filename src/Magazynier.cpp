#include "Magazynier.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

double Magazynier::getPensja() const
{
	return 8000.0;
}

std::string Magazynier::getImie()
{
	return std::string(imie);
}

Magazynier::Magazynier(std::string name_m, bool wozek)
{
	licznik_mag++;
	imie = name_m;
	widlak = wozek;
	//std::cout << "Nowy pracownik. Magazynier " << imie << ". Uprawnienia na wozek: " << widlak << std::endl;
}

Magazynier::~Magazynier()
{
	licznik_mag--;
	std::cout << "Pracownik " << imie << " zostal usuniety." << std::endl;
}

void Magazynier::print()
{
	std::cout << "Magazynier " << imie << ". Uprawnienia na wozek: " << widlak << std::endl;
}

int Magazynier::getLiczbaMag()
{
	return licznik_mag;
}

const double Magazynier::getCMag()
{
	return CMag;
}
