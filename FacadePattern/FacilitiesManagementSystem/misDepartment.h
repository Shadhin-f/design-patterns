#pragma once
#include <iostream>
using namespace std;

class MisDepartment
{
private:
    enum states
    {
        Received,
        DenyAllKnowledge,
        FacilitiesHasNotSentPaperWork,
        ElectricianIsNotDone,
        SignedOff,
        Complete
    };
    int _state;

public:
    void submitNetworkRequest()
    {
        _state = 0;
        cout << "[MIS] Request submitted. Current state: " << _state << endl;
    }
    bool checkOnStatus()
    {
        _state++;
        cout << "[MIS] Current state: " << _state << endl;
        if (_state == Complete)
        {
            cout << "[MIS] Task Complete" << endl;
            return true;
        }
        return false;
    }
};