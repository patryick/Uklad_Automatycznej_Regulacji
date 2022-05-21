#include "RegulatorPID.h"

void RegulatorPID::steruj(float wartosc_zadana_temperatury, float probkowanie)
{
    float uchyb_aktualny = wartosc_zadana_temperatury - pomieszczenie->getTemperatura();
    float czesc_proporcjonalna = Kp * uchyb_aktualny;

    calka_uchybu += uchyb_aktualny * probkowanie;
    float czesc_calkujaca = Ki * calka_uchybu;

    float pochodna_uchybu = (uchyb_aktualny - uchyb_poprzedni) / probkowanie;
    float czesc_rozniczkujaca = Kd * pochodna_uchybu;

    uchyb_poprzedni = uchyb_aktualny;

    float dodawane_cieplo = grzejnik->getCieplo() * (czesc_calkujaca + czesc_proporcjonalna + czesc_rozniczkujaca);
    if (dodawane_cieplo < 0)
    {
        dodawane_cieplo = 0;
    }
    pomieszczenie->dodajCieplo(dodawane_cieplo);
    zapis_mocy.push_back(dodawane_cieplo);
}