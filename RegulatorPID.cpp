#include "RegulatorPID.h"

float RegulatorPID::steruj(float wartosc_zadana_temperatury, float wartosc_zmierzona_temperatury, float probkowanie)
{
    float uchyb_aktualny = wartosc_zadana_temperatury - wartosc_zmierzona_temperatury;
    float czesc_proporcjonalna = Kp * uchyb_aktualny;

    calka_uchybu += uchyb_aktualny * probkowanie;
    float czesc_calkujaca = Ki * calka_uchybu;

    float pochodna_uchybu = (uchyb_aktualny - uchyb_poprzedni) / probkowanie;
    float czesc_rozniczkujaca = Kd * pochodna_uchybu;

    uchyb_poprzedni = uchyb_aktualny;

    return czesc_calkujaca + czesc_proporcjonalna + czesc_rozniczkujaca;
}