#pragma once
#include <iostream>
#include <mutex>
using namespace std;

class Logger
{
public:
    static Logger *getLogger();
    void log(string msg);

private:
    static int counter;
    Logger();
    static Logger *loggerInstance;
};
