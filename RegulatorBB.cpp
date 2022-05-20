//
// Created by Patrick on 20.05.2022.
//

#include "RegulatorBB.h"

float RegulatorBB::steruj(float wartosc_zadana_temperatury, float wartosc_zmierzona_temperatury, float probkowanie)
{
    if (wartosc_zadana_temperatury > wartosc_zmierzona_temperatury)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}