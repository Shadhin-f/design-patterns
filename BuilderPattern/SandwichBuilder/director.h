#pragma once
#include "concreteBuilder.h"

class Director
{
public:
    SandwichBuilder *builder;
    void SetBuilderType(SandwichBuilder *builder)
    {
        this->builder = builder;
    }
    Sandwich dineInOrder()
    {
        builder->AddBread();
        builder->AddProtein();
        builder->LoadSides();
        builder->DrizzleSauces();
        return builder->ReturnProduct();
    }
    Sandwich TakeoutOrder()
    {
        builder->AddBread();
        builder->AddProtein();
        builder->LoadSides();
        builder->DrizzleSauces();
        builder->AddWrapper();
        return builder->ReturnProduct();
    }
    Sandwich NoSauce()
    {
        builder->AddBread();
        builder->AddProtein();
        builder->DrizzleSauces();
        return builder->ReturnProduct();
    }
    Sandwich NoSides()
    {
        builder->AddBread();
        builder->AddProtein();
        builder->DrizzleSauces();
        return builder->ReturnProduct();
    }
};