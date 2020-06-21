/*
CH08-320143
a2_p2.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    //initialized a queue of 0 elements
    Queue<float> que1;
    cout << "Queue 1: " <<endl;

    //popping fails since it's empty
    float popping;
    que1.pop(popping);

    cout << "Pushing Values" << endl;
    que1.push(2);
    que1.push(5);
    que1.push(48);
    que1.push(1);
    que1.push(7);

    cout << "Value at Back (End): " << que1.back() <<endl;
    cout << "Value at Front (Beginning): " <<  que1.front() << endl;
    cout << "Total Elements in Queue: " << que1.getNumEntries()<<endl;
    cout << endl;

    Queue<int> que2;
    cout << "Queue 2: " <<endl;
    int i = 6;
    while(i!=0)
    {
        cout << "Pushing: " << i << endl;
        que2.push(i);
        i--;
    }
    cout << endl;

    int total = que2.getNumEntries();
    cout << "Total Elements in Queue: " << total <<endl;
    cout << endl;

    while(que2.getNumEntries() > 0)
    {
        int val;
        que2.pop(val);
        cout << "Popping: " << val << endl;
    }
    cout <<endl;

    //to show stack overflow condition:

    Queue<int> que3;
    cout << "Queue 3: " <<endl;
    int j = 1;
    while(j<12)
    {
        cout << "Pushing: " << j << endl;
        que2.push(j);
        j++;
    }
    return 0;
}

//this works more like a stack, not a
//doubly linked list
//still works on First In First Out Operation
