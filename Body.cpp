#include "Body.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <fstream>
#include <string>
#include <strings.h>
#include "AirBag.h"
#include "lights.h"
using namespace std;


Body::Body()
{
    //ctor
}

Body::~Body()
{
    //dtor
}
int Body::BEvaluateData()
{

    int flag=0; //Flag to check if there is one or more error in the code
    //Evaluating Air Bag data:
    ifstream file("Airbag.csv");
    string value,value1,value2;
    while(file.good())
    {
        getline(file,value,',');
        getline(file,value1,',');
        getline(file,value2,'\n');
        //cout << "\n" << string(value,0,value.length());
        string temp = string(value,0,value.length());
        lamp = atof(temp.c_str());

        if(checkLampCondition(lamp))
        {
            cout << "\t B1207:\n ->Air Bag Damage" << "\n"<<endl;
            cout<<"\t  Faulty Passenger Air Bag Indicator Lamp"<<endl;
            flag=1;
            //writingData(temp);
        }


        //cout << "\n" << string(value1,0,value1.length());
        temp = string(value1,0,value1.length());
         lampHarness= atoi(temp.c_str());

        if(checkLampHarness(lampHarness))
        {
             cout << "\t B1207:\n ->Air Bag Damage" << "\n";
             cout<<"\t Passenger Air Bag Indicator Lamp harness is open or shorted"<<endl;
             flag=1;
        }

        //cout << "\n" << string(value2,0,value2.length());
        temp = string(value2,0,value2.length());
        electricalConnection= atoi(temp.c_str());

        if(checkElectricalConnections(electricalConnection))
        {
             cout << "\t B1207:\n ->Air Bag Damage" << "\n";
             cout<<"\t Passenger Air Bag Indicator Lamp circuit poor electrical connection"<<endl;
             flag=1;
        }

        usleep(900000);
    }
    file.close();


    //Evaluating LIGHTS:
    ifstream file1("Lights.csv");
    string temp1,temp2,temp3,temp4,temp5,lfr,lfl,lrr,lrl,lb;
    while(file1.good())
    {
        getline(file1,lfr,',');
        getline(file1,lfl,',');
        getline(file1,lrr,',');
        getline(file1,lrl,',');
        getline(file1,lb,'\n');

        //cout << "\n" << string(lfr,0,lfr.length());
        string temp1 = string(lfr,0,lfr.length());
        lights[0] = atof(temp1.c_str());

        //cout << "\n" << string(lfl,0,lfl.length());
        string temp2 = string(lfl,0,lfl.length());
        lights[1] = atof(temp2.c_str());

        //cout << "\n" << string(lrr,0,lrr.length());
        string temp3 = string(lrr,0,lrr.length());
        lights[2] = atof(temp3.c_str());

        //cout << "\n" << string(lrl,0,lrl.length());
        string temp4 = string(lrl,0,lrl.length());
        lights[3] = atof(temp4.c_str());

        //cout << "\n" << string(lb,0,lb.length());
        string temp5 = string(lb,0,lb.length());
        lights[4] = atof(temp5.c_str());

        if(checkLights(lights))
        {
            cout << "\t" << "\n"<<endl;
            for(int i=0;i<5;i++)
                if(lights[i]==0)
                flag=1;
            //writingData(temp);
        }
    }
    return flag;

}

