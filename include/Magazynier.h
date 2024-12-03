#pragma
#include "Pracownik.h"
#include <iostream>
#include <string>


class Magazynier : public Pracownik
{
	//Pola nieodziedziczone
private:
	bool widlak;
	static const double CMag; //stale pole statyczne
	static int licznik_mag;
	//Metody
public:
	double getPensja() const override;
	virtual std::string getImie() override;
	//Konstruktor
	Magazynier(std::string name_m, bool wozek);
	//Destruktor
	~Magazynier();
	virtual void print();
	static int getLiczbaMag();
	static const double getCMag();
};
