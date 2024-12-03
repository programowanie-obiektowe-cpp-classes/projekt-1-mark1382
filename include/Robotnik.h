#pragma
#include "Pracownik.h"
#include <iostream>
#include <string>


class Robotnik : public Pracownik
{
	//Pola nieodziedziczone
private:
	double rozmiar_buta;
	static const double CR; //stale pole statyczne
	static int licznik_rob;
	//Metody
public:
	double getPensja() const override;
	virtual std::string getImie() override;
	//Konstruktor
	Robotnik(std::string name_r, double but);
	//Destruktor
	~Robotnik ();
	virtual void print();
	static int getLiczbaRobotnik();
	static const double getCR();
};
