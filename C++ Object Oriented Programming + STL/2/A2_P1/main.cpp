/*
CH08-320143
a2_p1.cpp
nhammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
private:
    double re, im;

public:
    Complex();

    Complex(double re, double im)
    {
        this->re = re;
        this->im = im;
    }

    Complex& operator=(const Complex o)
    {
        this->re = o.re;
        this->im = o.im;
        return *this;
    }

    //we overload this operator and compare absolute values of
    //the complex numbers. since definition is inside class,
    //we use bool operator

    bool operator < (const Complex &o)
    {
        if (sqrt(re*re + im*im)< sqrt(o.re*o.re + o.im*o.im))
            return 1;
        else
            return 0;
    }

    friend ostream& operator<<(ostream &o, Complex c)
    {
        o << c.re << "+" << c.im << "i" << endl;
        return o;
    }
};

//we initialize the min value to arr[0] and then
//compare with the next ones until the array ends
//second parameter number= # of elements in array

template <class T>
T array_min(T arr[], int number)
{
    T minimum = arr[0];
    for (int i = 1; i < number; i ++)
    {
        if (arr[i] < minimum)
        {
            minimum = arr[i];
        }
    }
    return minimum;
}

int main()
{
    int basic1[] = {1, 2, 3, 4, 5, 6};
    cout << "Minimum Value of First Basic Array:" <<endl;
    cout << array_min(basic1, 6) << endl;

    double basic2[]= {45.12, 35.11, 78.41, 4.10, 51.10, 97.00, 31.22};
    cout << "Minimum Value of Second Basic Array:" <<endl;
    cout << array_min(basic2, 7) << endl;

    Complex object1[] = {Complex(1, 2), Complex(3, 4), Complex(-3, -5)};
    cout << "Minimum Complex Number from Object 1:" <<endl;
    cout << array_min(object1, 3) << endl;

    Complex object2[] = {Complex(5, 3), Complex(2, 3), Complex(-1, -5)};
    cout << "Minimum Complex Number from Object 2:" <<endl;
    cout << array_min(object2, 3) << endl;

    return 0;
}
