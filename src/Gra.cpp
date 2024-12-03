#include "Gra.h"
#include "Firma.h"
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <deque>

Gra::Gra(double poczatkowy_stan)
{
        firma = std::make_unique<Firma>(poczatkowy_stan);
}

const double Gra::getKwota_Wygryw()
{
    return kwota_wygrywajaca;
}


void Gra::menu()

    {
        std::string wybor;
        bool kontynuuj = true;

        while (kontynuuj) 
        {
            std::cout << std::endl << "=== MENU ===\n"
                << "lp    - Wylistuj pracownikow (imiona i wynagrodzenia)\n"
                << "zinz  - Zatrudnij inzyniera\n"
                << "zmag  - Zatrudnij magazyniera\n"
                << "zmkt  - Zatrudnij marketera\n"
                << "zrob  - Zatrudnij robotnika\n"
                << "kred  - Wez kredyt (podaj kwote i czas splaty)\n"
                << "kt    - Zakoncz ture i wyswietl stan firmy\n"
                << "exit  - Wyjscie\n"
                << "Wybierz opcje: \n";
            std::cin >> wybor;

            if (wybor == "lp") {
                firma->drukujPracownikow();
            }
            else if (wybor == "zinz") {
                std::string imie;
                std::string wydzial;
                std::cout << "Podaj imie i ukonczony wydzial: " << std::endl;
                std::cin >> imie;
                std::cout << std::endl;
                std::cin >> wydzial;
                std::cout << std::endl;
                firma->zatrudnijPracownika("Inzynier", imie, wydzial);
            }
            else if (wybor == "zmag") {
                std::string imie;
                std::string wozek;
                std::cout << "Podaj imie i informacje o uprawnieniach na wozek widlowy: " << std::endl;
                std::cin >> imie;
                std::cout << std::endl;
                std::cin >> wozek;
                std::cout << std::endl;
                firma->zatrudnijPracownika("Magazynier", imie, wozek);
            }
            else if (wybor == "zmkt") {
                std::string imie;
                std::string follow;
                std::cout << "Podaj imie i informacje o liczbie followersow: " << std::endl;
                std::cin >> imie;
                std::cout << std::endl;
                std::cin >> follow;
                std::cout << std::endl;
                firma->zatrudnijPracownika("Marketer", imie, follow);
            }
            else if (wybor == "zrob") {
                std::string imie;
                std::string but;
                std::cout << "Podaj imie i numer buta: " << std::endl;
                std::cin >> imie;
                std::cout << std::endl;
                std::cin >> but;
                std::cout << std::endl;
                firma->zatrudnijPracownika("Robotnik", imie, but);
            }
 //Sp³acanie kredytu trzeba uwzglêdniæ w stanie konta. Trzeba te¿ uwzglêdniæ max liczbê kredytow oraz usuwanie kredytu po jego splaceniu.
            else if (wybor == "kred") 
            {
                double kwota;
                int czasSplaty;

                std::cout << "Podaj kwote kredytu: ";
                while (!(std::cin >> kwota) || kwota <= 0) {
                    std::cout << "Nieprawidlowa kwota. Podaj jeszcze raz: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                std::cout << "Podaj czas splaty (w miesiacach): ";
                while (!(std::cin >> czasSplaty) || czasSplaty <= 0) {
                    std::cout << "Nieprawidlowy czas splaty. Podaj jeszcze raz: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                firma->wezKredyt(kwota, czasSplaty); //Tworzymy obiekt klasy Kredyt
            }
            //Zakoñczenie tury: powinno powodowaæ szereg skutków zwi¹zanych z finansowym podsumowaniem tury
            //Zatrudni³em kogo mia³em zatrudniæ, wzi¹³em kredyty etc.
            //Okreœlony stan pracowników determinuje przychód -- wywo³aj double Firma::obliczPrzychod() i void Firma::otrzymajPrzychod
            else if (wybor == "kt")  {
                firma->obliczPrzychod(); 
                firma->otrzymajPrzychod();
                firma->zaplac_wynagrodzenie();
                firma->splacKredyty();
                std::cout << std::endl << "PODSUMOWANIE PO RUNDZIE NR " << licznik_tur << std::endl << std::endl;
                std::cout << "Stan konta: "<<firma->getStan_konta()<<std::endl;
                std::cout << "Przychod: " << firma->obliczPrzychod() << std::endl;
                std::cout << "Sumaryczny dlug: "<< firma->obliczSumarycznyDlug() <<std::endl;
                std::cout << "Wartosc firmy: " <<firma->wartoscFirmy() << std::endl;
                std::cout << "Wartosc netto firmy (indykator wygranej): " << firma->wartosc_Netto() << std::endl;
                if (licznik_tur>=(firma->getN_miesiecy()))
                {
                    if (firma->wartosc_Netto() >= kwota_wygrywajaca)
                    {
                        std::cout << "Gratulacje!!! Wygrales w rundzie nr: " << licznik_tur << std::endl;
                        kontynuuj = false;
                        std::cout << "Zakonczono program." << std::endl;
                    }
                    else if (firma->getStan_konta() < 0)
                    {
                        std::cout << "Utonales w dlugach. Zakonczyles gre w rundzie nr: " << licznik_tur << std::endl;
                        kontynuuj = false;
                        std::cout << "Zakonczono program." << std::endl;
                    }
                }

                //Co wyœwietliæ: stan konta (getStan_konta), wartoœæ firmy, d³ug ca³kowity, liczba kredytów, Wartoœæ netto
                //if wartosc firmy netto >=wartosc graniczna  - gratulacje wygrales w rundzie nr <<licznik; -exit()
                //else if wartosc firmy netto < 0 - Utonales w dlugach - zakonczyles gre w rundzie nr 2; - exit()
                
                licznik_tur++;
            }
            else if (wybor == "exit") {
                kontynuuj = false;
                std::cout << "Zakonczono program." << std::endl;
            }
            else {
                std::cout << "Nieprawidlowy wybor. Sprobuj ponownie." << std::endl;
            }

        }
}

 