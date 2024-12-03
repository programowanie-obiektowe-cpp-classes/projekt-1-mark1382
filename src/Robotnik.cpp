#include "Robotnik.h"
#include <iostream>
#include <string>

double Robotnik::getPensja() const
{
	return 5500.0;
}

std::string Robotnik::getImie()
{
	return std::string(imie);
}

Robotnik::Robotnik(std::string name_r, double but)
{
	licznik_rob++;
	imie = name_r;
	rozmiar_buta = but;
	//std::cout << "Nowy pracownik. Robotnik " << imie << ". Rozmier buta: " << rozmiar_buta << std::endl;
}

Robotnik::~Robotnik()
{
	licznik_rob--;
	std::cout << "Pracownik " << imie << " zostal usuniety." << std::endl;
}

void Robotnik::print()
{
	std::cout << "Robotnik " << imie << ". Rozmiar buta: " << rozmiar_buta << std::endl;

}

int Robotnik::getLiczbaRobotnik()
{
	return licznik_rob;
}

const double Robotnik::getCR()
{
	return CR;
}
