#pragma
#include <iostream>
#include <string>
#include "Pracownik.h"

class Inzynier : public Pracownik 
{
	//Pola nieodziedziczone
private:
	static int licznik_inz;
	std::string wydzial;
	static const double CI; //stale pole statyczne
	//Metody
public:
	double getPensja() const override;
	virtual std::string getImie() override;
	//Konstruktor
	Inzynier(std::string name, std::string faculty);
	//Destruktor
	~Inzynier();
	virtual void print() override;
	static int getLiczbaInzynierow();
	static const double getCI();
};
