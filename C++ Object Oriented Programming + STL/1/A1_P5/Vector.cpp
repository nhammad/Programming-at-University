/*
CH08-320143
a1_p5.cpp
nhammad
n.hammad@jacobs-university.de
*/

#include <cstdlib>
#include <cstring>
#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector()
{
    size = 0;
    loc = NULL;
}

Vector::Vector(int newsize)
{
    size = newsize;
    loc = new double[newsize];
}

//copy constructor
//since one val is a double pointer,
//we have to use dynamic memory allocation

Vector::Vector(const Vector& v)
{
    size = v.size;
    loc = new double[size];
    for (int i=0; i<v.size; i++)
    {
        loc[i] = v.loc[i];
    }
}

Vector::~Vector()
{
    delete[]loc;
}

int Vector::len() const
{
    return size;
}

//returns value at a particular index:

double Vector::val_idx(int idx) const
{
    return loc[idx];
}

//sets the value at a particular index:

void Vector::setValAt(int index, double val)
{
    if (index<size)
    {
        loc[index] = val;
    }
    else
        exit(0);
}

//we expand the dynamically allocated array
//to a size according to the values and space
//required by our vector:

void Vector::expand(int i)
{
    double* new_array = loc;
    int original_size = size;
    if (i > size)
    {
        loc = new double[i];
        size = i;
    }
    else
    {
        return;
    }
    if (new_array != NULL && original_size != 0)
    {
        for (int j=0; j<i; j++)
        {
            loc[j] = new_array[j];
        }
        delete [] new_array;
    }
    else
        return;
}

void Vector::print() const
{
    if (size>0)
    {
        cout << "[ ";
        for(int i = 0; i < size; i++)
        {
            cout << loc[i] << " ";
        }
        cout << "]" << endl;
    }
    else
    {
        cout << "[Empty]" <<endl;
        return;
    }
}

//first we read the (int) dimensions of the vector
//then we expand the size of our dynamic array accordingly
//then we read values of the vector acc to dimensions
//and set them at their respective indexes

std::istream& operator >> (std::istream& in, Vector& v)
{
    int dimen, value;
    in >> dimen;
    v.expand(dimen);
    for(int i = 0; i < dimen; i++)
    {
        in >> value;
        v.setValAt(i, value);
    }
    return in;
}

//for the file output:
//indexes start from 0 so we subtract 1 from len

std::ostream& operator << (std::ostream& out, const Vector& v)
{
    if(v.len() > 0)
    {
        out << "[";
        for(int i = 0; i < v.len()-1; i++)
        {
            out << v.val_idx(i) << "  ";
        }
        out << v.val_idx(v.len()-1);
        out << "]" <<endl;
            return out;
    }
    else
        return out;
}
