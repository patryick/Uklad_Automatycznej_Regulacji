#pragma once

#include <vector>
#include "POMIESZCZENIE.h"
#include "Grzejnik.h"
#include "Regulator.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"
#include "RegulatorException.h"

class Symulacja
{
private:
    Pomieszczenie* pomieszczenie;
    Grzejnik* grzejnik;
    Regulator* regulator;
    std::vector<float> zapis_przebiegu{};
public:
    Symulacja(Pomieszczenie& pomieszczenie, Grzejnik& grzejnik, int typ_regulatora)
    : pomieszczenie(&pomieszczenie), grzejnik(&grzejnik)
    {
        if (typ_regulatora == 1)
        {
            regulator = new RegulatorBB{};
        }
        else if (typ_regulatora == 2)
        {
            regulator = new RegulatorPID{};
        }
        else
        {
            throw RegulatorException();
        }
        regulator->zainincujSkladowe(pomieszczenie, grzejnik);
    }

    ~Symulacja()
    {
        delete regulator;
    }

    void iteracja(float probkowanie);
    void przebieg(int ilosc_iteracji, float czas_probkowania);
    void zapisz_do_pliku();
};
