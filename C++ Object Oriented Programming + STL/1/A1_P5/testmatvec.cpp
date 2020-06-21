/*
CH08-320143
a1_p5.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/
#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{

    Vector v1;
    Matrix m1;

    ifstream in1("in1.txt");
    ifstream in2("in2.txt");
    ofstream out1("out1.txt");
    ofstream out2("out2.txt");

    if (!in1.is_open())
        in1.open("in1.txt",ios::in);
    if (!in1.good())
    {
        cout << "Error Occured" << endl;
        exit(1);
    }
    in1 >> m1;


    if (!in2.is_open())
        in2.open("in2.txt",ios::in);
    if (!in2.good())
    {
        cout << "Error Occured" << endl;
        exit(1);
    }
    in2 >> v1;

    //outputting on screen:
    cout << "Vector : " << endl;
    cout << v1 << endl;
    cout << "Matrix : " << endl;
    cout << m1 << endl ;

    cout << "Result of Mat * Vec Multiplication:" << endl;
    cout << m1 * v1 << endl;
    cout << "Result of Vec * Mat Multiplication:" << endl;
    cout << v1* m1;

    //outputting in files
    out1 << m1;
    out2 << v1;

    return 0;
}
