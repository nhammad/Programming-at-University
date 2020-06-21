/*
CH08-320143
a3_p6.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include <queue>
using namespace std;

//returns the larger one:
class comparator
{
    bool operator()(const int &int1, const int &int2) const
    {
        return int1 > int2;
    }
};

//in PQ, 1st element is always the greatest
//works like a max heap

int main()
{
    std::priority_queue<int> q1;
    cout << "Queue 1:  " << endl;
    cout << "Is Queue Empty? ";

    if (q1.empty() == 1)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;


    for (int i = 0; i < 10; i++)
    {
        q1.push(i);
    }

    cout << "Size=  " << q1.size() << endl;
    cout << "What's on Top?  " << q1.top() << endl;

    q1.emplace(5);
    q1.emplace(420);
    q1.emplace(10);

    cout << "What's on Top After Emplacing?  " << q1.top() << endl;

    cout << "My Priority Queue contains: " << endl;
    while (!q1.empty())
    {
        cout << ' ' << q1.top();
        q1.pop();
    }
    cout << endl;


    std::priority_queue<int> q2;
    for (int i = 0; i < 4; i++)
    {
        q2.push(i);
    }
    cout << "Size of Q2 =  " << q2.size() << endl;

    //swapping:
    q2.swap(q1);
    cout << "Sizes After Swapping: " << endl;
    cout << "Size of Q1 =  " << q1.size() << endl;
    cout << "Size of Q2 =  " << q2.size() << endl;

    //to test a user defined comparator:
    int info[] = {4, 9, 5, 3, 11, 5, 15, 6, 7, 8, 2};

    //self defined ordering criterion
    auto comparator = [](int a, int b)
    {
        return a > b;
    };

    priority_queue<int, vector<int>, decltype(comparator)> q3(comparator);
    cout << "Pushing Values into Q3 = " << endl;

    for(int i = 0; i < 11; i++)
    {
        q3.push(info[i]);
    }

    for(int i = 0; i < 11; i++)
    {
        cout << "Popping  " << q3.top() << endl;
        q3.pop();
    }
    cout << endl;
    return 0;
}
//top: max element (like in a max heap)
//pop: removes top element
