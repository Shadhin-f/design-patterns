#include "concreteBuilder.h"

Sandwich CreateSandwich(SandwichBuilder *builder)
{
    builder->AddBread();
    builder->AddProtein();
    builder->LoadSides();
    builder->DrizzleSauces();
    builder->AddWrapper();
    return builder->ReturnProduct();
}

int main()
{
    cout << "Creating Burger : ---------------" << endl;
    CreateSandwich(new BurgerBuilder());
}
