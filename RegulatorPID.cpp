#include "RegulatorPID.h"
#include "WyjatekDzieleniePrzez0.h"


void RegulatorPID::steruj(float wartosc_zadana_temperatury, float dt)
{
    if (pomieszczenie == nullptr || grzejnik == nullptr)
    {
        throw WyjatekRegulator();
    }
    if (dt == 0)
    {
        throw WyjatekDzieleniePrzez0();
    }
    float e = wartosc_zadana_temperatury - pomieszczenie->getTemperatura();
    float up = Kp * e;
    e_calka += e * dt;
    float ui = Ki * e_calka;
    float de = (e - e_poprzednia) / dt;
    float ud = Kd * de;
    e_poprzednia = e;
    float dodawane_cieplo = grzejnik->getCieplo() * (ui + up + ud);
    if (dodawane_cieplo < 0)
    {
        dodawane_cieplo = 0;
    }
    pomieszczenie->dodajCieplo(dodawane_cieplo);
    zapis_mocy.push_back(dodawane_cieplo);
}