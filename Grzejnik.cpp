#include "Grzejnik.h"

float Grzejnik::getCieplo() const
{
    return moc_nominalna * aktualny_poziom_mocy;
}