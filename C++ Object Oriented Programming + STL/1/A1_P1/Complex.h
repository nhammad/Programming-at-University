/*
CH08-320142
a1_p1.cpp
nhammad
n.hammad@jacobs-university.de
*/
#include <iostream>
#include <stdlib.h>
//#include <cmath>


class Complex
{
private:
    float real;
    float imag;

public:
    Complex();              //default constructor
    Complex(float real, float imag);
    Complex (Complex &c);
    //conjugate();
    void setReal(float);    //setters
    void setImag (float);
    float getReal();        //getters
    float getImag();
    ~Complex();             //destructor

    Complex operator+(const Complex &c);
    Complex operator-(const Complex &c);
    Complex operator*(const Complex &c);
    Complex operator = (const Complex &c);

    friend std::ostream& operator<<(std::ostream& out, const Complex &c);
    friend std:: istream& operator>>(std::istream& in, Complex &c);
};
