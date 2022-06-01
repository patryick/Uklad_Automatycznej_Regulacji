#pragma once
#include <exception>

class WyjatekRegulator : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Pomieszczenie lub grzejnik nie zostalo skonfigurowane w regulatorze!\n";
    }
};