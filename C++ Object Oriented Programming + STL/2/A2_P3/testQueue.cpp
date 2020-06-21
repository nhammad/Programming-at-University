/*
CH08-320143
a2_p3.cpp
nhammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    //initialized a queue of 0 elements:

    Queue<int> que1;
    cout << "Queue 1: " <<endl;
    cout << "Current Size: " << que1.getSize()<<endl;


    //size is 10 so after successfully pushing 10 elements,
    //even tho it says "pushing i", it's not pushing more elements
    //and thus says that stack is full

    int i = 12;
    while(i!=0)
    {
        cout << "Pushing: " << i << endl;
        que1.push(i);
        i--;
    }
    cout << endl;

    //resizing to bigger size:

    Queue<int> que2;
    que2.resize(14);
    cout << "Current Size: " << que2.getSize()<<endl;
    int j = 12;
    while(j!=0)
    {
        cout << "Pushing: " << j << endl;
        que2.push(j);
        j--;
    }
    cout << endl;

    //resizing to a smaller size:
    //last 5 elements that were pushed will remain
    //while all elements before that will be deleted:

    que2.resize(5);
    cout << "Current Size: " << que2.getSize()<<endl;
    while(que2.getNumEntries() > 0)
    {
        int val;
        que2.pop(val);
        cout << "Popping: " << val << endl;
    }
    return 0;
}

//this works more like a stack, not a
//doubly linked list. First In, First Out
