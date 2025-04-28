#pragma once
#include "duck.h"
#include <iostream>

class MallarDuck : public Duck
{
public:
    void quack() override
    {
        std::cout << "quack" << std::endl;
    }
    void fly() override
    {
        std::cout << "I am flyingggg" << std::endl;
    }
};