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

    if (wybor == 1)
    {
        RegulatorBB regulatorBB{};
        Symulacja symulacja{pomieszczenie, grzejnik, regulatorBB};
        symulacja.przebieg(100, 0.1);
    }
    else if (wybor == 2)
    {
        RegulatorPID regulatorPID{};
        Symulacja symulacja{pomieszczenie, grzejnik, regulatorPID};
        symulacja.przebieg(100, 0.1);
    }
    else
    {
        std::cerr << "Nieprawidlowy wybor!!!\n";
    }




    return 0;
}
