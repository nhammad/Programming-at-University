/*
CH08-320143
a3_p5.cpp
nhammad
n.hammad@jacobs-university.de
*/


#include <iostream>
#include "WindGauge.h"

using namespace std;

int main()
{
    //we create a wind gauge object
    //and add 5 speed values to it
    WindGauge obj;
    obj.currentWindSpeed(14);
    obj.currentWindSpeed(16);
    obj.currentWindSpeed(13);
    obj.currentWindSpeed(15);
    obj.currentWindSpeed(15);

    //dumping and printing lowest,highest,avg.
    obj.print();

    //since the allowed period is only 10,
    //after 10 elements are added, the ones
    //that were added earlier will be popped
    //and will be replaced with new ones

    obj.currentWindSpeed(15);
    obj.currentWindSpeed(17);
    obj.currentWindSpeed(17);
    obj.currentWindSpeed(16);
    obj.currentWindSpeed(20);
    obj.currentWindSpeed(15);
    obj.currentWindSpeed(16);
    obj.currentWindSpeed(20);
    obj.currentWindSpeed(10);

    obj.print();


    return 0;
}
