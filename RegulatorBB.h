#pragma once

#include "Regulator.h"
#include "POMIESZCZENIE.h"
#include "Grzejnik.h"

class RegulatorBB : public Regulator
{
public:

    void steruj(float wartosc_zadana_temperatury, float probkowanie) override;
};
