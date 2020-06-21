/*
CH08-320142
a1_p1.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include <stdlib.h>
#include "Complex.h"

using namespace std;

//for default constructor

Complex::Complex()
{
    real = 0;
    imag = 0;
    //cout<<"Constructor one is being called."<<endl;
}

Complex::~Complex()
{
    //cout<<"Destructor is being called."<<endl;
}

Complex::Complex(float newreal, float newimag)
{
    real = newreal;
    imag = newimag;
}

//copy constructor
Complex::Complex (Complex &c)
{
    real =c.real;
    imag =c.imag;
}

//setters
void Complex::setReal(float newreal)
{
    real = newreal;
}

void Complex::setImag(float newimag)
{
    imag = newimag;
}

float Complex::getReal()
{
    return real;
}
float Complex::getImag()
{
    return imag;
}

/*Complex::conjugate()
{
    Complex New;
    real = real;
    imag = -imag;
    return New;
}*/
//for adding complex numbers

Complex Complex :: operator+(const Complex& c)
{
    Complex New;
    New.real = real + c.real;
    New.imag = imag + c.imag;
    return New;
}

Complex Complex :: operator-(const Complex& c)
{
    Complex New;
    New.real = real - c.real;
    New.imag = imag - c.imag;
    return New;
}

Complex Complex :: operator=(const Complex& c)
{
    //Complex New;
    real = c.real;
    imag = c.imag;
    return *this;
}

Complex Complex :: operator*(const Complex& c)
{
    Complex New;
    New.real = (real * c.real) - (imag * c.imag);
    New.imag = (real * c.imag) + (c.real *imag);
    return New;
}
// for printing results
// noshowpos doesn't show the + sign
//showpos shows the + or - sign

std::ostream& operator<<(std::ostream& out, const Complex &c)
{
    out << noshowpos << c.real << showpos << c.imag << "i" << endl;
    return out;
}

//for inputting values from the user
std:: istream& operator>>(std::istream& in, Complex &c)
{
    in >>c.real >> c.imag;
    return in;
}
