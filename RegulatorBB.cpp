#include <iostream>
#include "RegulatorBB.h"

void RegulatorBB::steruj(float temperatura, float dt)
{
    if (pomieszczenie == nullptr || grzejnik == nullptr)
    {
        throw WyjatekRegulator();
    }
    float cieplo_dodane = 0;
    if (temperatura > pomieszczenie->getTemperatura())
    {
        cieplo_dodane = grzejnik->getCieplo();
        pomieszczenie->dodajCieplo(cieplo_dodane);
    }
    zapis_mocy.push_back(cieplo_dodane);
}