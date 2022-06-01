#include "Symulacja.h"
#include "WyjatekDzieleniePrzez0.h"
#include <fstream>
#include <iostream>

void Symulacja::iteracja(float dt)
{
    pomieszczenie.aktualizuj(dt);
    regulator->steruj(21, dt);

    zapis_przebiegu.push_back(pomieszczenie.getTemperatura());
}

void Symulacja::przebieg(int n, float dt)
{
    if (n < 0)
    {
        std::cerr << "Ilosc iteracji nie moze byc mniejsza niz 0!\n";
        return;
    }

    try
    {
        for (int i = 0; i < n; i++)
        {
            this->iteracja(dt);
        }
    }
    catch (WyjatekRegulator& e)
    {
        std::cerr << e.what();
        return;
    }
    catch (WyjatekDzieleniePrzez0& e)
    {
        std::cerr << e.what();
        return;
    }


}

void Symulacja::zapisz()
{
    std::ofstream p("dane.csv");
    for (int i = 0; i < zapis_przebiegu.size(); i++)
    {
        p << zapis_przebiegu.at(i) << ";" << regulator->zapis_mocy.at(i) << "\n";
    }
    p.close();
}
