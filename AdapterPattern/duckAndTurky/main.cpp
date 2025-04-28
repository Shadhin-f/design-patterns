#include "turkeyAdapter.h"
#include "duckAdapter.h"
#include "mallarDuck.h"
#include "wildTurkey.h"

#include <iostream>

void testDuck(Duck *duck)
{
    duck->quack();
    duck->fly();
}
void testTurkey(Turkey *turkey)
{
    turkey->gooble();
    turkey->fly();
}

int main()
{
    Duck *duck = new MallarDuck();
    Turkey *turkey = new WildTurkey();

    std::cout << "Duck Says..." << std::endl;
    testDuck(duck);
    std::cout << "Turkey Says..." << std::endl;

    testTurkey(turkey);
    std::cout << std::endl
              << std::endl;

    Duck *turkeyAdapter = new TurkeyAdapter(turkey);
    testDuck(turkeyAdapter);
    Turkey *duckAdapter = new DuckAdapter(duck);
    testTurkey(duckAdapter);
    return 0;
}