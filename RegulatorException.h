#pragma once

#include <exception>

class RegulatorException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Podano zly rodzaj regulatora\n";
    }
};