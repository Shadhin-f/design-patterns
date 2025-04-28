#pragma once
#include "turkey.h"
#include "duck.h"
#include <iostream>

class TurkeyAdapter : public Duck
{
private:
    Turkey *turkey;

public:
    TurkeyAdapter(Turkey *tur) : turkey(tur) {}

    void quack() override
    {
        turkey->gooble();
    }
    void fly() override
    {
        for (int i = 0; i < 3; i++)
        {
            turkey->fly();
        }
    }
};