#include "logger.cpp"

int main()
{
    Logger *logger1 = Logger::getLogger();
    logger1->log("from user 1");
    Logger *logger2 = Logger::getLogger();
    logger2->log("from user 2");
}
