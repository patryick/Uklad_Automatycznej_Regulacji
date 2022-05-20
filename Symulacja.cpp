#include "Symulacja.h"
#include <iostream>

void Symulacja::iteracja(float probkowanie)
{
    pomieszczenie.aktualizuj(probkowanie);
    float cieplo_do_dodania = grzejnik.getCieplo() * regulator->steruj(21,
                                                                      pomieszczenie.getTemperatura(), probkowanie);
    pomieszczenie.dodajCieplo(cieplo_do_dodania);
    zapis_przebiegu.push_back(pomieszczenie.getTemperatura());
    std::cout << pomieszczenie.getTemperatura() << std::endl;
}

void Symulacja::przebieg(int ilosc_iteracji, float czas_probkowania)
{
    for (int i = 0; i < ilosc_iteracji; i++)
    {
        this->iteracja(czas_probkowania);
    }
}