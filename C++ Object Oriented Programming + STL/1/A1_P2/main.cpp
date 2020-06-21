/*
CH08-320143
a1_p2.cpp
nhammad
n.hammad@jacobs-university.de
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include <string>
using namespace std;

int main()
{
    int n;
    char fname[20];
    ofstream out;
    cin >> n;

    const int SZ = 100; //buffer size
    char buffer[SZ];    //buffer to read lines
    int length;

    if (!out.is_open())
        out.open("concatn.txt",ios::out| ios::binary);
    if (!out.good())
    {
        cout << "Error Occured" << endl;
        exit(1);
    }

    for (int i=1; i<=n; i++)
    {
        //reading name of the file
        cin >> fname;
        //pointer to input file
        ifstream name;

        if (!name.is_open())
            name.open(fname, ios::in | ios::binary);
        if (!name.good())
        {
            cout << "Error Occured" << endl;
            exit(1);
        }

        //moves the cursor to the end of the file
        name.seekg (0,name.end);
        //tells the # of places moved (total chars)
        length = name.tellg();
        //comes back to 0th position
        name.seekg (0);
        name.read(buffer,length);
        out.write(buffer,length);
        //\r returns to the back
        out.write("\r\n", 2);
        name.close();
    }
    out.close();
    return 0;
}

//Alternative Way
/*
int main()
{
    int n;
    char fname[20];
    ofstream out;
    cin >> n;

    const int SZ = 100; // Buffer size
    char buf[SZ];// buffer to read lines

    if (!out.is_open())
            out.open("output.txt",ios::out| ios::binary);
        if (!out.good())
        {
            cout << "Error Occured" << endl;
            exit(1);
        }
    for (int i=1; i<=n; i++)
    {
        cin >> fname;
        ifstream name; //in

        if (!name.is_open())
            name.open(fname, ios::in | ios::binary);
        if (!name.good())
        {
            cout << "Error Occured" << endl;
            exit(1);
        }

          while(name.get(buf, SZ))
        {
            // Leaves \n in input
            name.get();
            out << buf << endl;
            out << "\n" <<endl;
        }
        name.close();
    }
    out.close();
    return 0;*/
