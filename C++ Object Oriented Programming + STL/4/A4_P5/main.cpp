/*
CH08-320143
a4_p5.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <map>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    unsigned long mat_num;
    string fname, lname;

    map<unsigned long, string> database;

    ifstream in;
    if (!in.is_open())
        in.open("data.txt", ios::in);
    if (!in.good())
    {
        cout << "Error Occured" << endl;
        exit(1);
    }

    //reading till the end of the file:
    while(!in.eof())
    {
        in >> mat_num >> fname >> lname;
        database[mat_num] = fname + " " + lname;
    }

    in.close();

    //we use unsigned long because matriculation ids can
    //be large
    unsigned long id;

    cout << "Please Enter Matriculation Id = " << endl;
    cin >> id;

    //if mat is found in txt file, we print the
    //corresponding name
    if(database.find(id) != database.end())
    {
        cout << "Name: "  << database[id] << endl;
    }
    else
    {
        std:: cerr << "Matriculation number not found! " << endl;
    }
    return 0;
}
