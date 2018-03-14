#include "AirBag.h"
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <fstream>
using namespace std;


AirBag::AirBag()
{
    //ctor
}

AirBag::~AirBag()
{
    //dtor
}
bool AirBag::checkLampCondition(int l)
{
    lamp=l;
    if(lamp == 1)
        return true;
    else
        return false;
}
bool AirBag::checkLampHarness(int h)
{

    lampHarness=h;
    if(lampHarness == 0)
        return true;
    else
        return false;

}
bool AirBag::checkElectricalConnections(int e)
{
    electricalConnection=e;
    if(electricalConnection == 0)
        return true;
    else
        return false;
}
