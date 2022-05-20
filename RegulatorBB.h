#pragma once

#include "Regulator.h"

class RegulatorBB : public Regulator
{
public:
    float steruj(float wartosc_zadana_temperatury, float wartosc_zmierzona_temperatury, float probkowanie) override;
};
