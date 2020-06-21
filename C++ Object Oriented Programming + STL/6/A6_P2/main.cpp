/*
CH08-320143
a6_p2.cpp
nhammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include <sstream>
using namespace std;

//I ran the debugger.went to debugging windows & opened watches
//I added breaking points where functions are being called
//after running the debugger, I go to the respective breaking point
//and select the "Step Into" option from the tool bar.
//then, I use the "next line" option.

//in this function, i looked at the step by step iterations
//and noticed that with each iteration, the address of *odds
//changes instead of the value stored. Thus, we change it to
//(*odds)++

void foo(int *array, int n, int *odds)
{
    for(int i=0; i<n; i++)
        if (array[i] % 2 == 1)
            (*odds)++;
}

class Test
{
private:
    double *a;
    int n;
public:
    Test()
    {
        a=NULL;
        n=0;
    }
    Test(double *a, int n)
    {
        this->n = n;
        if (this->a != NULL)
        {
            delete this->a;
        }
        this->a = new double[n];
        for(int i=0; i<n; i++)
            this->a[i] = a[i];
    }
    string toString()
    {
        ostringstream ss;
        ss << "Length: " << n << endl << "Elements: ";
        for(int i=0; i<n; i++)
            ss << a[i] << " ";
        ss << endl;
        return ss.str();
    }
    ~Test()
    {
        delete a;
    }
};

int main()
{
    int array[3] = {1, 2, 3};
    int odd_values=0;
    foo(array, 3, &odd_values);
    cout << "Amount of odd values in the array=" << odd_values << endl;
    Test arr[5];
    double v[3] = {1.2, 2.3, 3.45};
    Test *obj1;                     //declaration only
    obj1=&arr[0];

    //when we observe watches, we see that
    //&arr[0]'s address is same as obj1's address

    Test *obj2 = new Test(v, 3);

    //obj3 is just pointed to NULL & then we're calling
    //toString on Null, which isn't really possible
    //we could change it to:
    //Test *obj3 = new Test(v, 3);

    Test *obj3 = NULL;
    cout << obj1->toString();
    cout << obj2->toString();

    //there's a problem here at obj3:
    cout << obj3->toString();

    //program will crash here, since deletion of obj1 is unsuccessful
    delete obj1;

    //when we observe watches here, we see that deletion doesn't
    //work properly. the arr still exists with 5 elements.
    //address of obj1->n and obj11->a is the same (0 or double *(0x0))

    delete obj2;
    delete obj3;
    return 0;
}
