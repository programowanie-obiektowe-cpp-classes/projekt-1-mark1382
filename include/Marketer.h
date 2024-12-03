#pragma
#include "Pracownik.h"
#include <iostream>
#include <string>


class Marketer : public Pracownik
{
	//Pola nieodziedziczone
private:
	int liczba_obserwujacych;
	static const double CMkt; //stale pole statyczne
	static int licznik_mark;
	//Metody
public:
	double getPensja() const override;
	virtual std::string getImie() override;
	//Konstruktor
	Marketer(std::string name_mkt, int followers);
	//Destruktor
	~Marketer();
	virtual void print();
	static int getLicznikMark();
	static const double getCMkt();
};
