#include "Symulacja.h"
#include <fstream>
#include <iostream>

void Symulacja::iteracja(float dt)
{
    pomieszczenie->aktualizuj(dt);
    try
    {
        regulator->steruj(21, dt);
    }
    catch (WyjatekRegulator& e)
    {
        std::cerr << e.what();
        regulator->zainincujSkladowe(this->pomieszczenie, this->grzejnik);
        regulator->steruj(21, dt);
    }
    zapis_przebiegu.push_back(pomieszczenie->getTemperatura());
}

void Symulacja::przebieg(int n, float dt)
{
    for (int i = 0; i < n; i++)
    {
        this->iteracja(dt);
    }

}

void Symulacja::zapisz()
{
    std::ofstream plik("plik.csv");
    for (int i = 0; i < zapis_przebiegu.size(); i++)
    {
        plik << zapis_przebiegu.at(i) << ";" << regulator->zapis_mocy.at(i) << "\n";
    }
    plik.close();
}
