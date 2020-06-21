/*
CH08-320143
a4_p6.cpp
nhammad
n.hammad@jacobs-university.de
*/

#include <algorithm>
#include "Access.h"
#include <iostream>

using namespace std;

int main()
{
    Access data;
    data.activate(123456, 1);
    data.activate(999999, 5);
    data.activate(187692, 9);

    unsigned long code;
    cout << "Enter Your Access Code=  " << endl;

    //we read until correct code is entered:
    while (cin >> code)
    {
        if (data.isactive(code, 5) == true)
        {
            cout << "Access Code Matched! Door Successfully Opened! " << endl;
            break;
        }
        else
            cout << "Unable to Open Door. Enter Code Again" << endl;

    }

    data.deactivate(code);
    data.activate(999999, 8);
    data.activate(111111, 7);

    //for second time:
    unsigned long newcode;
    cout << "Second Time " << endl;
    while (cin >> newcode)
    {
        if (data.isactive(newcode, 7) == true)
        {
            cout << "Access Code Matched! Door Successfully Opened! " << endl;
            break;
        }
        else
            cout << "Unable to Open Door. Enter Code Again" << endl;
    }
    return 0;
}
