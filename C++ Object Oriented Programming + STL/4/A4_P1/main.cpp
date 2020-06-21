/*
CH08-320143
a4_p1.cpp
nhammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <char> CharVec;
    char alphabet;

    //pushing values into the vector:
    for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
    {
        CharVec.push_back(alphabet);
    }

    //reversing the vector:
    std::reverse(CharVec.begin(),CharVec.end());

    //printing reversed vector:
    vector<char>::iterator it;
    for(it = CharVec.begin(); it != CharVec.end(); ++it)
    {
        if (it == CharVec.end())
        {
            cout << *it << endl;
        }
        else
            cout << *it << " ";
    }

    cout << endl;

    //pushing "f" at the end of the vector
    CharVec.push_back('f');

    //replacing all occurrences of "f" by "$"
    //(start from, scan till, character to change, new char to enter)

    replace(CharVec.begin(), CharVec.end(), 'f', '$');

    cout << "Printing After Replacement" << endl;
    vector <char>::iterator j;
    for (j = CharVec.begin(); j != CharVec.end(); ++j)
    {
        if(j == (CharVec.end()-1))
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
