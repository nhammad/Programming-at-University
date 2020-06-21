/*
CH08-320143
a4_p6.cpp
nhammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include <map>
#include <algorithm>
#include "Access.h"


using namespace std;

//adds an element to the map with corresponding level:

void Access::activate(unsigned long code, unsigned int level)
{
    database.insert(pair<unsigned long, unsigned int>(code, level));
}

//removes the element from the set:

void Access::deactivate(unsigned long code)
{
    database.erase(code);
}

//map stores key and value
//-> second is to access the value
//access code will only be considered active if
//the level value is equivalent or greater than that
//which was used to activate that particular code

bool Access::isactive(unsigned long code, unsigned int level) const
{
    map<unsigned int, unsigned int>::const_iterator it;
    it = database.find(code);
    if(it != database.end())
    {
        if(database.find(code)->second >= level)
        {
            return true;
        }
    }
    return false;
}
