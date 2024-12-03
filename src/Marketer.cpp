#include "Marketer.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

double Marketer::getPensja() const
{
	return 12000.0;
}

std::string Marketer::getImie()
{
	return std::string(imie);
}

Marketer::Marketer(std::string name_mkt, int followers)
{
	licznik_mark++;
	imie = name_mkt;
	liczba_obserwujacych = followers;
	//std::cout << "Nowy pracownik. Marketer " << imie << ". Liczba obserwujacych: " << liczba_obserwujacych << std::endl;
}

Marketer::~Marketer()
{
	licznik_mark--;
	std::cout << "Pracownik " << imie << " zostal usuniety." << std::endl;

}

void Marketer::print()
{
	std::cout << "Marketer: " << imie << ". Liczba obserwujacych: " << liczba_obserwujacych << std::endl;

}

int Marketer::getLicznikMark()
{
	return licznik_mark;
}

const double Marketer::getCMkt()
{
	return CMkt;
}
