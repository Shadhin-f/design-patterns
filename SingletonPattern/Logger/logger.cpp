#include "logger.h"

int Logger::counter = 0;
Logger *Logger::loggerInstance = nullptr;

Logger::Logger()
{
    counter++;
    cout << "New instance of the logger created.  Instances: " << counter << endl;
}
void Logger::log(string msg)
{
    cout << msg << endl;
}

Logger *Logger::getLogger()
{
    if (loggerInstance == nullptr)
    {
        loggerInstance = new Logger();
    }
    return loggerInstance;
}
