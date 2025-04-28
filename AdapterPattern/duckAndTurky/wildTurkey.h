#pragma once
#include "turkey.h"
#include <iostream>

class WildTurkey : public Turkey
{
public:
    void gooble() override
    {
        std::cout << "Gooble, gooble" << std::endl;
    }
    void fly() override
    {
        std::cout << "I am flying a sorttt distanceee" << std::endl;
    }
};