#include "Vehicle.h"
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

Vehicle::Vehicle()
{
    //ctor
}
Vehicle::~Vehicle()
{
    //dtor
}
void Vehicle::CheckSystem()
{
    pFlag = PEvaluateData();
    bFlag = BEvaluateData();

    if(pFlag == 0 && bFlag == 0)
    {
        cout<<"\tThere is no problem with your car. \n\tIt is working perfectly.\n\tYAY! :D\n"<<endl;
    }


}
