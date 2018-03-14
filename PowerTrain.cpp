#include "PowerTrain.h"
#include<iostream>
#include <unistd.h>
#include <cstring>
#include <string>
#include <strings.h>
#include <fstream>
#include<stdlib.h>

using namespace std;

PowerTrain::PowerTrain()
{
    //ctor
}

PowerTrain::~PowerTrain()
{
    //dtor
}

int PowerTrain::PEvaluateData()
{

    int flag=0;
    //Evaluating EGR data
    ifstream file("Data.csv");
    string value,value1,value2;
    while(file.good())
    {
        getline(file,value,',');
        getline(file,value1,',');
        getline(file,value2,'\n');
        //cout << "\n" << string(value,0,value.length());
        string temp = string(value,0,value.length());
        dpfe = atof(temp.c_str());

        if(checkDPFE(dpfe))
        {
            cout << "\t" << "P0401:\n -> Check Engine Light Blinking- EGR System\n"<<endl;
            cout<<"\n The DPFE (differential pressure feedback EGR) sensor is faulty and needs to be replaced"<<endl;
            flag=1;
            //writingData(temp);
        }


        //cout << "\n" << string(value1,0,value1.length());
        temp = string(value1,0,value1.length());
        egrTubeFull = atoi(temp.c_str());

        if(checkBlockage(egrTubeFull))
        {
             cout << "\t" << "P0401:\n -> Check Engine Light Blinking- EGR System\n";
             cout<<"\n There is a blockage in the EGR (tube), most likely carbon buildup"<<endl;
             flag=1;
        }

        //cout << "\n" << string(value2,0,value2.length());
        temp = string(value2,0,value2.length());
        egrValve = atoi(temp.c_str());

        if(checkegrValve(egrValve))
        {
            cout << "\t" << "P0401:\n -> Check Engine Light Blinking- EGR System\n";
            cout<<"\n The EGR valve is faulty The EGR valve may not be opening due to a lack of vacuum"<<endl;
            flag=1;
        }
        usleep(900000);
    }
    file.close();

    //Evaluating Catalyst System Data data
    ifstream oxyfile("OxygenSensor.csv");
    string o1,o2;
    while(oxyfile.good())
    {
        getline(oxyfile,o1,',');
        getline(oxyfile,o2,'\n');

        //cout << "\n" << string(o1,0,o1.length());
        string temp1 = string(o1,0,o1.length());
         o2Front = atof(temp1.c_str());

        if(checkFrontSensor(o2Front))
        {
            cout << "\t" << "P0420:\n -> Faulty Catalytic Convertor\n"<<endl;
            cout<<"\n The front oxygen sensor shows greater value. "<<endl;
            flag=1;
            //writingData(temp);
        }


        //cout << "\n" << string(o2,0,o2.length());
        temp1 = string(o2,0,o2.length());
        o2Rear = atof(temp1.c_str());

        if(checkRearSensor(o2Rear))
        {
             cout << "\t" << "P0420:\n -> Faulty Catalytic Convertor\n";
             cout<<"\n The rear oxygen sensor shows greater value.  "<<endl;
             flag=1;
        }
    }
    return flag;
}

