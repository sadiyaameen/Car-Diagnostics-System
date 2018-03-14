#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <fstream>
#include "PowerTrain.h"
#include "Body.h"
#include "Vehicle.h"


using namespace std;


int main()
{
    int engOff;char ch;
    //PowerTrain p1;
    //p1.EvaluateData();
    //Body b1;
    //b1.EvaluateData();
    engOff=0;
    while(1)
    {
        cout<<"*********************************************************************"<<endl;
        cout<<"\t ~~~   Welcome to Car Diagnostics System!   ~~~"<<endl;
        cout<<"*********************************************************************"<<endl;
        cout<<"\tPress 0 to switch OFF the engine\n\tIf you want to switch it on, press 1\n";
        cin>>engOff;

            if(engOff == 0)
            {
                cout<<"\n\tDo you want to diagnose your car?\n\t[y for yes and n for no]\n"<<endl;
                cin>>ch;
                if(ch=='y')
                {
                    Vehicle v1;
                    v1.CheckSystem();
                }
                else
                    cout<<"Bye\n"<<endl;
            }

            else
            {
                cout<<"Starting CAR!!!\n";
                cout<<"*********************************************************************"<<endl;
                return 0;
            }
    }
    return 0;
}
