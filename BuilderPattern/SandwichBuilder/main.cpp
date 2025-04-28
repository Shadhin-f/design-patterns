#include "director.h"

int main()
{
    Director d;
    Sandwich s;
    d.SetBuilderType(new BurgerBuilder());
    s = d.TakeoutOrder();
    s = d.NoSauce();
}