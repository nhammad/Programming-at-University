/*
CH08-320143
a4_p4.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include <set>
#include <algorithm>
#include "Access.h"


using namespace std;

//adds an element to the set:

void Access::activate(unsigned long code)
{
    A.insert(code);
}

//removes the element from the set:

void Access::deactivate(unsigned long code)
{
    A.erase(code);
}

//returns 1 if element is present in the set
//else, returns 0:

bool Access::isactive(unsigned long code) const
{
    set<int>::iterator it;
    it = A.find(code);
    if(it == A.end())
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
