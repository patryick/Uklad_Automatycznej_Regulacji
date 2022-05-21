#include "Symulacja.h"
#include <fstream>
#include <iostream>

void Symulacja::iteracja(float probkowanie)
{
    pomieszczenie->aktualizuj(probkowanie);
    regulator->steruj(21, probkowanie);
    zapis_przebiegu.push_back(pomieszczenie->getTemperatura());
}

void Symulacja::przebieg(int ilosc_iteracji, float czas_probkowania)
{
    for (int i = 0; i < ilosc_iteracji; i++)
    {
        this->iteracja(czas_probkowania);
    }

}

void Symulacja::zapisz_do_pliku()
{
    std::ofstream plik("plik.csv");
    for (int i = 0; i < zapis_przebiegu.size(); i++)
    {
        plik << zapis_przebiegu.at(i) << ";" << regulator->zapis_mocy.at(i) << "\n";
    }
    plik.close();
}