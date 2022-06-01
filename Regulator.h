#pragma once
#include "POMIESZCZENIE.h"
#include "Grzejnik.h"
#include "WyjatekRegulator.h"
#include <vector>

class Regulator
{
protected:
    Pomieszczenie* pomieszczenie;
    Grzejnik* grzejnik;
public:
    std::vector<float> zapis_mocy{};

    virtual ~Regulator() = default;

    void zainincujSkladowe(Pomieszczenie* p, Grzejnik* g)
    {
        this->grzejnik = g;
        this->pomieszczenie = p;
    }
    virtual void steruj(float wartosc_zadana_temperatury, float probkowanie) = 0;
};