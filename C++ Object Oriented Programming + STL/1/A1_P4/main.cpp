/*
CH08-320143
a1_p4.cpp
nhammad
n.hammad@jacobs-university.de
*/

#include<iostream>
using namespace std;

class A
{
    int x;
public:
    A(int i)
    {
        x = i;
    }
    void print()
    {
        cout << x;
    }
};


//changing virtual public
//to public virtual
class B: public virtual A
{
public:
    B():A(10) {  }
};

//changing public virtual
//to virtual public
class C:  public virtual  A
{
public:
    C():A(10) {  }
};

//previous version:

/*
class D: public B, public C {
};
*/

//^In the old version, there's no direct connection
//of D and A since an A constructor is lacking
// to overcome this problem, we can simply call
// A manually

//revised:

class D: public B, public C
{
public:
    D():A(20), B(), C() {  }
};

int main()
{
    D d;
    d.print();
    return 0;
}
