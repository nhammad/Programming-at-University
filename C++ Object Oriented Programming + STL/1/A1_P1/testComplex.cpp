/*
CH08-320142
a1_p1.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Complex.h"

using namespace std;

int main()
{
    //input & output files:

    ifstream in1;
    ifstream in2;
    ofstream out;

    //file 1
    //checking if file opened or not

    if (!in1.is_open())
        in1.open("in1.txt",ios::in);

    //good(): no errors
    if (!in1.good())
    {
        cout << "Error Occured" << endl;
        exit(1);
    }

    //file 2
    if (!in2.is_open())
        in2.open("in2.txt",ios::in);
    if (!in2.good())
    {
        cout << "Error Occured" << endl;
        exit(1);
    }

    //output file
    if (!out.is_open())
        out.open("output.txt",ios::out);
    if (!out.good())
    {
        cout << "Error Occured" << endl;
        exit(1);
    }


    Complex A,B;

    //reading complex numbers from files:
    in1 >> A;
    in2 >> B;

    //printing in file:
    out << "Complex Number from File 1 = " << A << endl;
    out << "Complex Number from File 2 = " << B << endl;
    out << "Sum of Complex Numbers = " << A+B << endl;
    out << "Difference of Complex Numbers = " << A-B << endl;
    out << "Product of Complex Numbers = " << A*B << endl;

    // displaying on screen
    cout << "Complex Number from File 1 = " << A << endl;
    cout << "Complex Number from File 2 = " << B << endl;
    cout << "Sum of Complex Numbers = " << A+B << endl;
    cout << "Difference of Complex Numbers = " << A-B << endl;
    cout << "Product of Complex Numbers = " << A*B << endl;
}
