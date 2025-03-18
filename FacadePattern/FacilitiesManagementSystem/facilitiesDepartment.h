#pragma once
#include <iostream>
using namespace std;

class FacilitiesDepartment
{
private:
    enum States
    {
        Received,
        AssignToEngineer,
        EngineerResearches,
        RequestIsNotPossible,
        AssignToNewEngineer,
        EngineerResearchesAgain,
        EngineerFillsOutPaperWork,
        Complete
    };
    int _state;

public:
    void submitNetworkRequest()
    {
        _state = 0;
        cout << "[Facilities] Request submitted. Current state: " << _state << endl;
    }
    bool checkOnStatus()
    {
        _state++;
        cout << "[Facilities] current state: " << _state << endl;
        if (_state == Complete)
        {
            cout << "[Facilities] Task completed." << endl;
            return true;
        }
        return false;
    }
};