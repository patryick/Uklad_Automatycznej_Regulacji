#pragma once
#include "POMIESZCZENIE.h"
#include "Grzejnik.h"
#include <vector>

class Regulator
{
protected:
    Pomieszczenie* pomieszczenie;
    Grzejnik* grzejnik;
public:
    std::vector<float> zapis_mocy{};

    void zainincujSkladowe(Pomieszczenie& pomieszczenie, Grzejnik& grzejnik)
    {
        this->grzejnik = &grzejnik;
        this->pomieszczenie = &pomieszczenie;
    }
    virtual void steruj(float wartosc_zadana_temperatury, float probkowanie) = 0;
};