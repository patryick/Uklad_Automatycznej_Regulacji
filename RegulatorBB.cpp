#include <iostream>
#include "RegulatorBB.h"

void RegulatorBB::steruj(float wartosc_zadana_temperatury, float probkowanie)
{
    float dodawane_cieplo = 0;
    if (wartosc_zadana_temperatury > pomieszczenie->getTemperatura())
    {
        dodawane_cieplo = grzejnik->getCieplo();
        pomieszczenie->dodajCieplo(dodawane_cieplo);
    }
    zapis_mocy.push_back(dodawane_cieplo);
}