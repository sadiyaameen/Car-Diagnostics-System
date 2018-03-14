#include "EGR.h"
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <fstream>
using namespace std;


EGR::EGR()
{
    //ctor
}

EGR::~EGR()
{
    //dtor
}
bool EGR::checkDPFE(float d)
{
    dpfe=d;
    if(dpfe<0.8 || dpfe>1.0)
        return true;
    else
        return false;
}

bool EGR::checkBlockage(int e)
{
    egrTubeFull=e;
    if(egrTubeFull==1)
        return true;
    else
    return false;
}

bool EGR::checkegrValve(int ev)
{
    egrValve=ev;
    if(egrValve == 0)
        return true;
    else
        return false;
}
