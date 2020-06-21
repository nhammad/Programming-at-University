/*
CH08-320143
a1_p3.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include<iostream>
using namespace std;

class A
{
    int x;
public:
    void setX(int i)
    {
        x = i;
    }
    void print()
    {
        cout << x;
        //cout << static_cast<A *>(this)->x << endl;
    }
};

//changed public A to public virtual A
class B:  public virtual A
{
public:
    B()
    {
        setX(10);
    }
};

//changed public A to public virtual A
class C:  public virtual A
{
public:
    C()
    {
        setX(20);
    }
};

class D: public B, public C
{

};

int main()
{
    D d;
    d.print();
    return 0;
}

//Explanation:

//Class D is inherited from Class B and C, which
//are both derived from Class A and thus, both
//of them had a void printing function which
//caused ambiguity. To avoid the confusion regarding
//which printing function should be used,
//Class A is declared as virtual so that it's functions
//are easily accessible by D as well.Unambiguous is removed
