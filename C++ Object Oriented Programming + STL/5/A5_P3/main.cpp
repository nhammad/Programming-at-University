/*
CH08-320143
a5_p3.cpp
nhammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include <exception>
#include <string>

using namespace std;

//we have to cast messages because otherwise
//they're not recognized as strings

class Motor
{
public:
    Motor()
    {
        throw(string("This motor has problems\n"));
    }
};

//we use a pointer and then dynamically allocate
//to create a motor inside a car
//the error we throw here won't be printed @ the end
//since we only create Garage object in the main

class Car
{
private:
    Motor* m;
public:
    Car()
    {
        try
        {
            m = new Motor;
        }
        catch(string &e)
        {
            throw (string("The Car has a problem\n"));
        }
    }
};
class Garage
{
private:
    Car* c;
public:
    Garage()
    {
        try
        {
            c = new Car;
        }
        catch(string &e)
        {
        throw(string("The car in this garage has problems with the motor\n"));
        }
    }
};
using namespace std;

int main()
{
    try
    {
        Garage g;
    }

    //we use "string" instead of exception since we're
    //throwing strings

    catch(string &e)
    {
        cerr << e << endl;
    }
    return 0;
}
