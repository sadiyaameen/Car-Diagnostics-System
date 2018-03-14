#include "lights.h"
#include<iostream>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <fstream>
using namespace std;

lights::lights()
{
    //ctor
}

lights::~lights()
{
    //dtor
}

bool lights::checkLights(int lights[])
{
    int i,flag=0;
    for(i=0;i<5;i++)
    {
        if(lights[i] == 0)
            cout<<"-> "<<lightNames[i]<<" is not working. "<<endl;
            flag=0;
    }

    if(flag==0)
        return true;
    else
        return false;
}
