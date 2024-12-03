#include "Inzynier.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>



Inzynier::Inzynier(std::string name, std::string faculty)
{
	imie = name;
	wydzial = faculty;
	licznik_inz++;
	//std::cout << "Nowy pracownik. Inzynier " << imie << ". Wydzial: " << wydzial << std::endl;
}

Inzynier::~Inzynier()
{
	licznik_inz--;
	std::cout << "Pracownik " << imie << " zostal usuniety." << std::endl;
}


void Inzynier::print()
{
	std::cout << "Inzynier: " << imie << ". Wydzial: " << wydzial << std::endl;
}

int Inzynier::getLiczbaInzynierow()
{
	return licznik_inz;
}

const double Inzynier::getCI()
{
	return CI;
}

double Inzynier::getPensja() const
{
	return 10000.0;
}

std::string Inzynier::getImie()
{
	return std::string(imie);
}
