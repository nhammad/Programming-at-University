/*
CH08-320143
a4_p4.cpp
nhammad
n.hammad@jacobs-university.de
*/
#include <set>
#include<iostream>

using namespace std;
class Access
{
public:
    void activate(unsigned long code);
    void deactivate(unsigned long code);
    bool isactive(unsigned long code) const;

private:
    set<int> A;
};

//we're using a set instead of multiset
//because multiset can contain the same code
//value more than once
