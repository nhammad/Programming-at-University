/*
CH08-320143
a6_p1.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/
#include <iostream>
using namespace std;

//I ran the debugger. went to debugging windows
//and opened watches.
//I added breaking points where functions are being called
//after running the debuger, I go to the breaking point
//and select the "Step Into" option from the tool bar.
//then, I use the "next line" option.


//in this function, i looked at the step by step iterations
//and noticed that the value of i changes nr+1 times even
//though it should only change nr times.

//for loop is starting from 0 and <= nr
//it will go out of index. we have to change it to < nr

int find(int a[], int nr, int el)
{
    for(int i=0; i<=nr; i++)
        if (a[i] == el)
            return i;
    return -1;
}

//When I go to the second func call in the main,
//and click "step into", the cursor goes straight to
//the last line "return a-b". that's because unsigned
//int can't store negative values and change them to positive
//automatically so (a-b) is never < 0. to change this,
//we could either just return a-b without if else statements
//or else say log diff = a - b and then compare

unsigned long difference(unsigned long a, unsigned long b)
{
    if (a-b < 0)
        return b-a;
    else
        return a-b;
}

int main()
{
    int n, val;
    cout << "n=";
    cin >> n;
    int *v=new int[n];
    cout << "Elements the elements of array:" << endl;
    for(int i=0; i<n; i++)
        cin >> v[i];
    cout << "val=";
    cin >> val;
    int result = find(v, n, val);
    cout << "Position of the searched element=" << result << endl;
    delete v;
    unsigned long x, y;
    x=550000;
    y=550005;
    cout << "Difference=" << difference(x, y) << endl;
    return 0;
}
