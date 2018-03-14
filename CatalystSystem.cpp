#include "CatalystSystem.h"

CatalystSystem::CatalystSystem()
{
    //ctor
}

CatalystSystem::~CatalystSystem()
{
    //dtor
}
bool CatalystSystem::checkRearSensor(double f)
{
    frontO2Sensor=f;
    if(frontO2Sensor<0.1 || frontO2Sensor>0.9)
        return true;
    else
        return false;
}

bool CatalystSystem::checkFrontSensor(double r)
{
    rearO2Sensor=r;
    if(rearO2Sensor<0.1 || rearO2Sensor>0.9)
        return true;
    else
        return false;
}
