#include "facilitiesFacade.h"

int main()
{
    FacilitiesFacade facilities;
    facilities.submitToNetworkRequest();
    while (!facilities.checkOnStatus())
        ;
    cout << "job completed " << endl;
}