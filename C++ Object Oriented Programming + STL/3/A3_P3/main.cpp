/*
CH08-320143
a3_p3.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/
#include <iostream>
#include <list>
#include <fstream>
#include <iterator>
#include <algorithm>
//^for reverse:

using namespace std;

int main()
{
    list <int> A;
    list <int> B;
    int num;

    while (cin >> num)
    {
        if (num > 0)
        {
            A.push_front(num);
            B.push_back(num);
        }
        else
        {
            break;
        }
    }

    //printing A with index operator:
    //next = built in

    cout << "Printing A with Iterator" << endl;
    list<int>::iterator i;
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

    //printing reversed B in a file:

    //opening file:
    ofstream out;
    if (!out.is_open())
        out.open("listB.txt",ios::out| ios::binary);
    if (!out.good())
    {
        cout << "Error Occured" << endl;
        exit(1);
    }

    //reversing:
    std::reverse(B.begin(),B.end());

    //printing in file:
    list<int>::iterator it;
    for(it = B.begin(); it != B.end(); ++it)
    {
        if (it == B.end())
        {
            out << *it << endl;
        }
        else
            out << *it << " ";
    }
    out.close();
    cout << endl;

    //Moving last element of the lists to the beginning:
    //A.splice(destination, lst, element at end)
    //A.end is after the last element so we use "prev"
    //prev is also built in:

    A.splice(A.begin(), A, prev(A.end()));
    B.splice(B.begin(), B, prev(B.end()));

    cout << "Printing Lst A with Iterator= " << endl;

    list<int>::iterator j;
    for (j= A.begin(); j != A.end(); ++j)
    {
        if(next(j) == (A.end()))
        {
            cout << *j << endl;
        }
        else
        {
            cout << *j << ",";
        }
    }

    cout << "Printing Lst B with Iterator= " << endl;

    list<int>::iterator k;
    for (k= B.begin(); k != B.end(); ++k)
    {
        if(next(k) == (B.end()))
        {
            cout << *k << endl;
        }
        else
        {
            cout << *k << ",";
        }
    }
    cout << endl;

    //we need to sort lists before merging them
    //this merge function is like merge sort
    //2 sorted lists are merged and automatically
    //arranged in a sorted arr.
    //B.merge(A) = A is merged into B

    A.sort();
    B.sort();
    B.merge(A);

    cout << "Printing Sorted B= " << endl;

    list<int>::iterator x;
    for (x= B.begin(); x != B.end(); ++x)
    {
        if(next(x) == (B.end()))
        {
            cout << *x << endl;
        }
        else
        {
            cout << *x << " ";
        }
    }
    return 0;
}
