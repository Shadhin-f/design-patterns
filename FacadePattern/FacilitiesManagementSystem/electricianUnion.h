#pragma once
#include <iostream>
using namespace std;

class ElectricianUnion
{
private:
    enum states
    {
        Received,
        RejectTheForm,
        SizeTheJob,
        WaitForAuthorization,
        ComplainToEngineer,
        Complete
    };
    int _state;

public:
    void submitNetworkRequest()
    {
        _state = 0;
        cout << "[Electrician] Request submitted. Current state: " << _state << endl;
    }
    bool checkOnStatus()
    {
        _state++;
        cout << "[Electrician] Current state: " << _state << endl;
        if (_state == Complete)
        {
            cout << "[Electrician] Task Completed." << endl;
            return true;
        }
        return false;
    }
};
