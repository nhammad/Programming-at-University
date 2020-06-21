/*
CH08-320143
a5_p1.cpp
nhammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include <vector>
#include <exception>

using namespace std;

int main()
{
    //initializing a vector:
    vector <char> CharVec;

    //adding "@" into the vector 15 times:
    for (int i = 0; i < 15 ; i++)
    {
        CharVec.push_back('@');
    }

    //accessing 16th element when there
    //are only 15 in the vector
    //this should be out of range
    try
    {
        CharVec.at(16);
    }
    //printing using cerr, standard error stream:
    catch(const out_of_range  &e)
    {
        std::cerr << e.what() << endl;
    }
    return 0;
}
