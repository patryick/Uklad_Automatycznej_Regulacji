#pragma once
#include <exception>

class WyjatekDzieleniePrzez0 : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Dzielenie przez zero jest zabronione!\n";
    }
};
