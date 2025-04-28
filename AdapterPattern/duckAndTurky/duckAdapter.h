#pragma once
#include "duck.h"
#include "turkey.h"
#include <iostream>

class DuckAdapter : public Turkey
{
private:
    Duck *duck;

public:
    DuckAdapter(Duck *du) : duck(du) {}
    void gooble() override
    {
        duck->quack();
    }
    void fly() override
    {
        duck->fly();
    }
};