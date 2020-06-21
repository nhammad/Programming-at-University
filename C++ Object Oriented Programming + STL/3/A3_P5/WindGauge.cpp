/*
CH08-320143
a3_p5.cpp
nhammad
n.hammad@jacobs-university.de
*/

#include "WindGauge.h"
#include <iostream>
#include <deque>

using namespace std;

WindGauge::WindGauge(unsigned int newperiod)
{
    period = newperiod;
}

//When currentWindSpeed() is called,
//the current wind speed is added to the history

void WindGauge::currentWindSpeed(int speed)
{
    //if history is then longer than the specified
    //period, the oldest wind speed is discarded.
    //means: if size is already full, we pop the element
    //added earlier & then push a new one
    if(gauge.size() == period)
    {
        gauge.pop_back();
        gauge.push_front(speed);
    }
    else
        gauge.push_front(speed);
}
//we consider the first element (d.begin) as the
//highest one and then keep iterating to compare
//all values with the first one. we return the highest

int WindGauge::highest() const
{
    deque<int>::const_iterator it;
    it = gauge.begin();
    int high = *it;
    while(it != gauge.end())
    {
        if(*it > high)
        {
            high = *it;
        }
        it++;
    }
    return high;
}

//we consider the first element (d.begin) as the
//lowest one and then keep iterating to compare
//all values with the first one. we return the lowest

int WindGauge::lowest() const
{
    deque<int>::const_iterator it;
    it = gauge.begin();
    int low = *it;
    while(it != gauge.end())
    {
        if(*it < low)
        {
            low = *it;
        }
        it++;
    }
    return low;
}

//we move from the beginning till the end
//and add all values to find sum
//and then find avg value by dividing with
//count (.size)

int WindGauge::average() const
{
    int sum = 0;
    deque<int>::const_iterator it;
    if (gauge.size() == 0)
    {
        cout << "Error. Deque Size is 0" << endl;
        exit(1);
    }
    it = gauge.begin();
    while(it != gauge.end())
    {
        sum = sum + *it;
        it++;
    }
    int avg = sum/(gauge.size());
    return avg;
}

void WindGauge::print()
{
    cout << "Lowest Speed: " << lowest() << endl;
    cout << "Highest Speed: " << highest() << endl;
    cout << "Average Speed: " << average() << endl;
    cout << endl;
}

deque<int> WindGauge::getter()
{
    return gauge;
}
