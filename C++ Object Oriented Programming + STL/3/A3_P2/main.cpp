/*
CH08-320143
a3_p2.cpp
nhammad
n.hammad@jacobs-university.de
*/
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    vector <string> WordVec;
    string word;

    //adding words to the vector:
    //we read with getline so that all strings are
    //taken as one element and not words separated by space

    while (getline(cin,word))
    {
        if (word != "STOP")
        {
            WordVec.push_back(word);
        }
        else
        {
            break;
        }
    }

    //checking if size is greater than 4
    //if size > 4 then it means that element 2
    //and 4 do exist
    //replacing elements 2 and 4

    if (WordVec.size()>= 4)
    {
        swap(WordVec[1], WordVec[3]);
    }
    else
        std::cerr << "Swap Not Possible" << endl;


    //replacing last element with ?

    if(WordVec.size()==0)
    {
        std::cerr << "Vector Empty" << endl;
    }
    else
    {
        WordVec[WordVec.size()-1] = "?";
    }

    //printing with index operator:

    cout << "Printing with Index Operator" << endl;
    for (unsigned int i = 0; i < WordVec.size(); i++)
    {
        if (i == (WordVec.size()-1))
        {
            cout << WordVec[i] << endl;
        }
        else
            cout << WordVec[i] << ";";
    }

    //printing with iterator:

    cout << "Printing with Iterator" << endl;
    vector <string>::iterator i;
    for (i = WordVec.begin(); i != WordVec.end(); ++i)

    {
        if(i == (WordVec.end()-1))
        {
            cout << *i << endl;
        }
        else
        {
            cout << *i << "-";
        }
    }

    //printing in reverse:

    cout << "Printing in Reverse" << endl;

    std::reverse(WordVec.begin(),WordVec.end());

    vector<string>::iterator it;
    for(it = WordVec.begin(); it != WordVec.end(); ++it)
    {
        if (it == WordVec.end())
        {
            cout << *it << endl;
        }
        else
            cout << *it << " ";
    }
    return 0;
}

/*vector<string>::reverse_iterator it;
for(it = WordVec.rbegin; it != WordVec.rend(); ++it)
{
    if (it == WordVec.rend())
    {
        cout << WordVec[i] << endl;
    }
    else
        cout << *it << " ";
}*/
