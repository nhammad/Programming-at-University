/*
CH08-320143
a4_p2.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

int main()
{
    vector<int> IntVec;
    int num;

    //initializing the random number generator
    //with the local time of my system:
    srand(time(NULL));

    //generating random numbers
    //duplicates are removed so we keep generating
    //until size is 6:

    while(IntVec.size()<6)
    {
        num = rand() % 49 + 1;
        //cout << "Random #" << num << endl;
        IntVec.push_back(num);

        //sorting in ascending order:
        sort(IntVec.begin(), IntVec.end());

        //removing duplicates:
        IntVec.erase(unique(IntVec.begin(),IntVec.end() ),IntVec.end());
    }

    //printing with an iterator:
    vector <int>::iterator j;
    for (j = IntVec.begin(); j != IntVec.end(); ++j)
    {
        if(j == (IntVec.end()-1))
        {
            cout << *j << endl;
        }
        else
        {
            cout << *j << " ";
        }
    }
    return 0;
}
