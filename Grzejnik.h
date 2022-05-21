#pragma once

class Grzejnik
{
private:
    float moc_nominalna;
    float aktualny_poziom_mocy;
public:
    Grzejnik(float moc_nominalna, float aktualny_poziom_mocy)
    :moc_nominalna(moc_nominalna)
    {
        if (aktualny_poziom_mocy > 1 || aktualny_poziom_mocy < 0)
        {
            aktualny_poziom_mocy = 0.5;
        }
        else
        {
            this->aktualny_poziom_mocy = aktualny_poziom_mocy;
        }
    }

    float getCieplo() const;
};



