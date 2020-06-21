/*
CH08-320143
a4_p6.cpp
nhammad
n.hammad@jacobs-university.de
*/
#include <map>
#include<iostream>

using namespace std;

class Access
{
public:
    void activate(unsigned long code, unsigned int level);
    void deactivate(unsigned long code);
    bool isactive(unsigned long code, unsigned int level) const;

private:
    map<unsigned int, unsigned int> database;
};

//map can store same values more than once too
