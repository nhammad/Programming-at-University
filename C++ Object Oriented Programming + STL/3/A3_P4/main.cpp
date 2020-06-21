/*
CH08-320143
a3_p4.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/
#include <iostream>
#include <deque>
#include <fstream>
#include <iterator>

using namespace std;

int main()
{
   deque <double> A;
   double num;

    while (cin >> num)
    {
        if (num != 0)
        {
            if (num > 0)
            {
                A.push_front(num);
            }
            else
            {
                A.push_back(num);
            }
        }
        else
        {
            break;
        }
    }

    cout << "Printing A with Iterator" << endl;
    deque<double>::iterator i;
    for (i = A.begin(); i != A.end(); ++i)
    {
        if(next(i) == (A.end()))
        {
            cout << *i << endl;
        }
        else
        {
            cout << *i << " ";
        }
    }
    cout << endl;


    //finding last positive number:
    deque<double>::iterator k;
    deque<double>::iterator pos;
    for(k = A.begin(); k != A.end(); k++)
    {
        if(*k < 0.0)
        {
            pos = k;
            break;
        }
    }
    //inserting 0 at pos:
    A.insert(pos, 0.0);

    deque<double>::iterator j;
    for (j = A.begin(); j != A.end(); ++j)
    {
        if(next(j) == (A.end()))
        {
            cout << *j << endl;
        }
        else
        {
            cout << *j << ";";
        }
    }
    return 0;
}
