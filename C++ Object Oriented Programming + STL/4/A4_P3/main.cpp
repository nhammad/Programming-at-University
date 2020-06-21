/*
CH08-320143
a4_p3.cpp
nhammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    set<int> A;
    multiset<int> B;
    int num;

    while (cin >> num)
    {
        if (num >= 0)
        {
            A.insert(num);
            B.insert(num);
        }
        else
        {
            break;
        }
    }

    //printing set A with an iterator:
    set <int>::iterator j;
    for (j = A.begin(); j != A.end(); ++j)
    {
        cout << *j << " ";
    }
    cout << endl << endl;

    //printing set B with an iterator:
    multiset <int>::iterator i;
    for (i = B.begin(); i != B.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl << endl;

    //removing 11 from both sets:
    A.erase (11);
    B.erase (11);

    //printing A after removing 11:
    set <int>::iterator id;
    for (id = A.begin(); id != A.end(); ++id)
    {
        cout << *id << " ";
    }
    cout << endl << endl;

    //printing B after removing 11:
    multiset <int>::iterator it;
    for (it = B.begin(); it != B.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl << endl;

    //inserting values into set A:
    A.insert(5);
    A.insert(421);

    //set union. result is in a form of multiset:
    multiset<int> C;
    set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(C,C.begin()));

    //printing set union's result:
    multiset <int>::iterator mult;
    for (mult = C.begin(); mult != C.end(); ++mult)
    {
        cout << *mult << " ";
    }
    cout << endl << endl;

    //set intersection. result is in a form of multiset:
    multiset<int> D;
    set_intersection(A.begin(),A.end(),
                     B.begin(),B.end(),inserter(D,D.begin()));

    //printing set intersection's result:
    multiset<int>::iterator inter;
    for (inter = D.begin(); inter != D.end(); ++inter)
    {
        cout << *inter << " ";
    }
    cout << endl << endl;

    //difference:
    set<int>df;
    set_difference(A.begin(),A.end(),
                   B.begin(),B.end(),inserter(df,df.begin()));

    //printing difference
    //cout << "Difference" << endl;
    set<int>::iterator diff;
    for (diff = df.begin(); diff != df.end(); ++diff)
    {
        cout << *diff << " ";
    }
    cout << endl << endl;

    //symmetric difference:
    set<int>sm;
    set_symmetric_difference(A.begin(),A.end(),B.begin(),
                             B.end(),inserter(sm,sm.begin()));

    //printing symmetric difference
    set<int>::iterator sym_diff;
    for (sym_diff = df.begin(); sym_diff != df.end(); ++sym_diff)
    {
        cout << *sym_diff << " ";
    }

    return 0;
}
