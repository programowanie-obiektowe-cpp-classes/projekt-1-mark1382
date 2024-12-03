#include<iostream>
#include <string>
#include "Kredyt.h"

double Kredyt::getDlug()
{
    return dlug;
}

int Kredyt::getRaty()
{
    return pozostale_raty;
}

Kredyt::Kredyt(double ile_kwota, int ile_rat)
{
    std::cout << "Wziales kredyt na kwote: " << ile_kwota << "  Ilosc rat: " << ile_rat << std::endl;
    pozostale_raty = ile_rat;
    odsetki = 0.01 * ile_rat;
    kwota_raty = (1+odsetki)*(ile_kwota / ile_rat);
    dlug+=ile_kwota+(odsetki*ile_kwota);
    std::cout << "Odsetki wynosza: " << odsetki<<" procent."<<std::endl;
}

double Kredyt::splacRate()
{
    pozostale_raty--;
    dlug=dlug-kwota_raty;
    return dlug;
}
