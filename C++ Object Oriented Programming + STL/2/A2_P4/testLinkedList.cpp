/*
CH08-320143
a2_p4.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    cout << "List 1: " <<endl;
    LinkedList<int> list1;
    cout << "Number of elements= " << list1.num_elements() <<endl;
    cout << endl;

    //pushing elements at the end:
    //extends the list from left to right:

    for (int i = 0; i< 5; i++)
    {
        cout << "Pushing At End= " << i <<endl;
        list1.PushEnd(i);
    }
    cout << endl;

    //checking number of elements again:
    cout << "Number of elements= " << list1.num_elements()<<endl;
    cout << "Value at Front= " << list1.front() << endl;
    cout << "Value at End= " << list1.end() << endl;


    for (int i = 16; i< 18; i++)
    {
        cout << "Pushing At Front= " << i <<endl;
        list1.PushFront(i);
    }

    cout << endl;
    cout << "Number of elements= " << list1.num_elements()<<endl;
    cout << "Value at Front= " << list1.front() << endl;
    cout << "Value at End= " << list1.end() << endl;
    cout << endl;

    cout << "Value Removed from Front = " << list1.remove_front() <<endl;
    cout << "New Value at Front= " << list1.front() << endl;
    cout << endl;

    cout << "Value Removed from End= " << list1.remove_end() << endl;
    cout << "New Value at End= " << list1.end() << endl;

    return 0;
}
