/*
CH08-320143
a1_p5.cpp
nhammad
n.hammad@jacobs-university.de
*/
#ifndef _VECTOR_H
#define _VECTOR_H
#include <iostream>

class Vector
{
private:
    int size;
    double* loc;

public:
    Vector();
    Vector(int);
    Vector(const Vector& v);
    ~Vector();

    void print() const;
    int len() const;
    void expand(int val);
    double val_idx(int idx) const;
    void setValAt(int index, double val);
};

std::istream& operator >> (std::istream& in, Vector& v);
std::ostream& operator << (std::ostream& out, const Vector& v);

#endif
