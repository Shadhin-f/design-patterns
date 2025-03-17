#include <string>
#include <iostream>

using namespace std;

class Alarm
{
public:
    void activate()
    {
        cout << "Alarm is on. House is secured." << endl;
    }
    void deActivated()
    {
        cout << "Alarm is off. House is not secured." << endl;
    }
};

class Fan
{
public:
    void on()
    {
        cout << "Fan is on." << endl;
    }
    void off()
    {
        cout << "Fan is off." << endl;
    }
};

class Light
{
public:
    void on()
    {
        cout << "Light is on." << endl;
    }
    void off()
    {
        cout << "Light is off." << endl;
    }
};

class SmartHomeFacade
{
private:
    Alarm alarm;
    Fan fan;
    Light light;

public:
    SmartHomeFacade() {};
    void goToWork()
    {
        alarm.activate();
        fan.off();
        light.off();
    }
    void comeHome()
    {
        alarm.deActivated();
        fan.on();
        light.on();
    }
};

int main()
{
    SmartHomeFacade smartHome;
    smartHome.goToWork();
    smartHome.comeHome();
    return 0;
}