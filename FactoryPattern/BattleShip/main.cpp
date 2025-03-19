#include <iostream>
using namespace std;

class BattleShip
{
public:
    BattleShip()
    {
        cout << "Battleship Created" << endl;
    }
    virtual void fire() = 0;
    virtual void steer() = 0;
    virtual ~BattleShip()
    {
        cout << "Battleship Destroyed" << endl;
    }
};

class Destroyer : public BattleShip
{
public:
    Destroyer()
    {
        cout << "Destroyer Created" << endl;
    }
    void fire() override
    {
        cout << "Destroyer Fire" << endl;
    }
    void steer() override
    {
        cout << "Destroyer steer" << endl;
    }
};

class Carrier : public BattleShip
{
public:
    Carrier()
    {
        cout << "Carrier Created" << endl;
    }
    void fire() override
    {
        cout << "Carrier Fire" << endl;
    }
    void steer() override
    {
        cout << "Carrier steer" << endl;
    }
};

class ShipCreator
{
public:
    virtual BattleShip *factoryMethod() = 0;
    virtual ~ShipCreator() {}

    BattleShip *CreateShip()
    {
        BattleShip *ptr = this->factoryMethod();
        return ptr;
    }
};

class CarrierCreator : public ShipCreator
{
public:
    BattleShip *factoryMethod() override
    {
        return new Carrier();
    }
};
class DestroyerCreator : public ShipCreator
{
public:
    BattleShip *factoryMethod() override
    {
        return new Destroyer();
    }
};

int main()
{
    ShipCreator *creator = new CarrierCreator();
    BattleShip *battleShip1 = creator->CreateShip();
    battleShip1->fire();
    battleShip1->steer();

    creator = new DestroyerCreator();
    BattleShip *battleShip2 = creator->CreateShip();
    battleShip2->fire();
    battleShip2->steer();
}