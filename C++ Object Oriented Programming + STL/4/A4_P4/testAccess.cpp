/*
CH08-320143
a4_p4.cpp
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
    data.activate(123456);
    data.activate(999999);
    data.activate(187692);

    int code;
    cout << "Enter Your Access Code=  " << endl;

    //we read until correct code is entered:
    while (cin >> code)
    {
        if ((data.isactive(code)== 1))
        {
            cout << "Access Code Matched! Door Successfully Opened! " << endl;
            break;
        }
        else
            cout << "Unable to Open Door. Enter Code Again" << endl;

    }

    data.deactivate(code);
    data.deactivate(999999);
    data.activate(111111);

    //for second time:
    int newcode;
    cout << "Second Time " << endl;
    while (cin >> newcode)
    {
        if ((data.isactive(newcode) == 1))
        {
            cout << "Access Code Matched! Door Successfully Opened! " << endl;
            break;
        }
        else
            cout << "Unable to Open Door. Enter Code Again" << endl;
    }
    return 0;
}
