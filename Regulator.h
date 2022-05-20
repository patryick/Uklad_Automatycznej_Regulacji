#pragma once

class Regulator
{
public:
    virtual float steruj(float wartosc_zadana_temperatury, float wartosc_zmierzona_temperatury, float probkowanie) = 0;
};