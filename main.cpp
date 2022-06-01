#include <iostream>
#include "Symulacja.h"
#include "POMIESZCZENIE.h"

int main()
{
    int wybor;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Wybierz rodzaj regulatora:" << std::endl;
    std::cout << "1. RegulatorBB" << std::endl;
    std::cout << "2. RegulatorPID" << std::endl;
    std::cin >> wybor;

    Pomieszczenie pomieszczenie{1, 1, 1};
    Grzejnik grzejnik{1000, 0.5};
    Symulacja symulacja(pomieszczenie, grzejnik, wybor);

    symulacja.przebieg(100, 0.5);
    symulacja.zapisz();





    return 0;
}
