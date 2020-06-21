/*
CH08-320143
a1_p5.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/
#ifndef _MATRIX_H
#define _MATRIX_H
#include <cstdlib>
#include <iostream>
#include "Vector.h"

class Matrix
{
//we crate a dynamic array to store matrix
private:
    int row;
    int col;
    double* arr;

public:
    Matrix();
    Matrix(int row, int col); //constructor
    ~Matrix();

    int num_rows() const;
    int num_col() const;
    void setPos(int row, int col, double val);
    double val_idx(int row, int col) const;
    int returnIndex(int row, int col) const;
    void resize(int row, int col);
};

std::istream& operator>>(std::istream& in, Matrix& m);
std::ostream& operator<<(std::ostream& out, const Matrix& m);

Vector operator*(const Matrix& m, const Vector& v);
Vector operator*(const Vector& v, const Matrix& m);

#endif
