#pragma once

#include <vector>
#include "POMIESZCZENIE.h"
#include "Grzejnik.h"
#include "Regulator.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"

class Symulacja
{
private:
    Pomieszczenie pomieszczenie;
    Grzejnik grzejnik;
    Regulator* regulator;
    std::vector<float> zapis_przebiegu{};
public:
    Symulacja(Pomieszczenie& pomieszczenie, Grzejnik& grzejnik, Regulator& regulator)
    : pomieszczenie(pomieszczenie), grzejnik(grzejnik)
    {
        RegulatorBB* regulatorBB_ptr;
        regulatorBB_ptr = (RegulatorBB*)&regulator;
        if (regulatorBB_ptr)
        {
            this->regulator = (RegulatorBB*)&regulator;
        }
        else
        {
            this->regulator = (RegulatorPID*)&regulator;
        }
    }

    void iteracja(float probkowanie);
    void przebieg(int ilosc_iteracji, float czas_probkowania);
};
