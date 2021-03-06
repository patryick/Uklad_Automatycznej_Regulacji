#pragma once

#include "Regulator.h"

class RegulatorPID : public Regulator
{
private:
    const float Kp = 4;
    const float Ki = 0.02;
    const float Kd = 0.1;
    float e_calka = 0;
    float e_poprzednia = 0;
public:

    void steruj(float wartosc_zadana_temperatury, float dt) override;
};
