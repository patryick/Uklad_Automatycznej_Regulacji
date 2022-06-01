#pragma once

#include <vector>
#include "POMIESZCZENIE.h"
#include "Grzejnik.h"
#include "Regulator.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"
#include "WyjatekRegulator.h"

class Symulacja
{
private:
    Pomieszczenie* pomieszczenie;
    Grzejnik* grzejnik;
    Regulator* regulator;
    std::vector<float> zapis_przebiegu{};
public:
    Symulacja(Pomieszczenie& p, Grzejnik& g, const int& w)
    : pomieszczenie(&p), grzejnik(&g)
    {
        if (w == 1)
        {
            regulator = new RegulatorBB{};
        }
        else if (w == 2)
        {
            regulator = new RegulatorPID{};
        }
        regulator->zainincujSkladowe(pomieszczenie, grzejnik);
    }

    ~Symulacja()
    {
        delete regulator;
    }

    void iteracja(float dt);
    void przebieg(int n, float dt);
    void zapisz();
};
