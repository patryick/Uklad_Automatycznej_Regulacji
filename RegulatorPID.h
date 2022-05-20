#pragma once

#include "Regulator.h"

class RegulatorPID : public Regulator
{
    const float Kp = 4;
    const float Ki = 0.02;
    const float Kd = 0.1;
    float calka_uchybu = 0;
    float uchyb_poprzedni = 0;
public:
    float steruj(float wartosc_zadana_temperatury, float wartosc_zmierzona_temperatury, float probkowanie);
};