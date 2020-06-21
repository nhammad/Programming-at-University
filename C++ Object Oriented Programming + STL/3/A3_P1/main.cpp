/*
CH08-320143
a3_p1.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    vector <string> WordVec;
    string word;

    //adding words to the vector:

    while (cin >> word)
    {
        if (word != "stop")
        {
            WordVec.push_back(word);
        }
        else
        {
            break;
        }

    }

    //printing using index operator
    //size-1 gives us the last index
    //here, we do not print a comma:

    for (unsigned int i = 0; i < WordVec.size(); i++)
    {
        if (i == (WordVec.size()-1))
        {
            cout << WordVec[i] << endl;
        }
        else
            cout << WordVec[i] << ",";
    }

    //printing using a corresponding iterator
    //no space after last element:

    vector <string>:: const_iterator i;
    for (i = WordVec.begin(); i != WordVec.end(); ++i)

    {
        if(i == (WordVec.end()-1))
        {
            cout << *i << endl;
        }
        else
        {
            cout << *i << " ";
        }
    }
    return 0;
}
