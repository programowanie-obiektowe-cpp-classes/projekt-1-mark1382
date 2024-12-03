#pragma once
#include <iostream>
#include <string>

class Pracownik // klasa nadrzedna Pracownik - z niej bêd¹ dziedziczyæ klasy ró¿nych typow pracownikow
{
protected:
	std::string imie;  // wspolne maja tylko imie
	//metody 
	virtual void print()=0; //wirtualna metoda drukujaca
public:
	virtual double getPensja() const = 0;
	virtual std::string getImie() = 0;

};