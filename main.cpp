#include <iostream>
#include "Symulacja.h"
#include "POMIESZCZENIE.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"

int main()
{
    int wybor;
    std::cout << "Wybierz rodzaj regulatora:\n";
    std::cout << "1. RegulatorBB\n";
    std::cout << "2. RegulatorPID\n";
    std::cin >> wybor;

    Pomieszczenie pomieszczenie{1, 1, 1};
    Grzejnik grzejnik{500, 0.9};

    try
    {
        Symulacja symulacja(pomieszczenie, grzejnik, wybor);
        symulacja.przebieg(100, 0.5);
        symulacja.zapisz_do_pliku();
    }
    catch (RegulatorException& e)
    {
        std::cout << e.what();
    }



    return 0;
}
