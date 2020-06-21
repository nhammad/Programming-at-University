/*
CH08-320143
a1_p5.cpp
nhammad
n.hammad@jacobs-university.de
*/
#include "Matrix.h"
using namespace std;

Matrix::Matrix()
{
    row = 0;
    col = 0;
    this->arr = NULL;
}

//dynamically allocating memory:

Matrix::Matrix(int newrow, int newcol)
{
    row = newrow;
    col = newcol;
    arr = new double[newrow * newcol];
}

int Matrix::num_rows() const
{
    return row;
}

int Matrix::num_col() const
{
    return col;
}

Matrix::~Matrix()
{
    delete [] this->arr;
}

void Matrix::resize(int newrow, int newcol)
{
    delete [] this->arr;
    row = newrow;
    col = newcol;
    arr = new double[newrow * newcol];
    return;
}

//returns index from the dynamically allocated arr
int Matrix::returnIndex(int row, int col) const
{
    return row * (this->col) + col;
}

//this sets read values into correct corresponding indexes:

void Matrix::setPos(int row, int col, double val)
{
    int index = returnIndex(row, col);
    this->arr[index] = val; //assign the data
    return;
}

//this returns the value at a particular index:

double Matrix::val_idx(int row, int col) const
{
    return this->arr[returnIndex(row, col)];
}

//reading values from file:
//for each row, another for loop allows reading
//values acc to number of columns
//after reading, we set values at corresponding indexes:

std::istream& operator >> (std::istream& in, Matrix& m)
{
    int row, col;
    double val;
    in >> row;
    in >> col;
    m.resize(row, col);
    for(int i = 0; i < m.num_rows(); i++)
    {
        for(int j = 0; j < m.num_col(); j++)
        {
            in >> val;
            m.setPos(i, j, val);
        }
    }
    return in;
}

//for outputting values in file
//val_idx returns the value at a particular index:

std::ostream& operator << (std::ostream& out, const Matrix& m)
{
    int i, j;
    for(i = 0; i < m.num_rows(); i++)
    {
        for(j = 0; j < m.num_col(); j++)
        {
            out << m.val_idx(i, j) << " ";
        }
        out << endl;
    }
    return out;
}

//for vector* matrix multiplication:

Vector operator * (const Vector& v, const Matrix& m)
{
    if (m.num_rows() == v.len())
    {
        Vector ans(m.num_col());
        for(int i = 0; i < m.num_col(); i++)
        {
            double sum = 0.0;
            for(int j = 0; j < m.num_rows(); j++)
            {
                sum += m.val_idx(j, i) * v.val_idx(j);
            }
            ans.setValAt(i, sum);
        }
        return ans;
    }
    else
        return Vector();
}
//for matrix * vector multiplication:
//multiplication is only possible when
//col of matrix == size of vector

Vector operator * (const Matrix& m, const Vector& v)
{
    if (m.num_col() == v.len())
    {
        Vector ans(m.num_rows());
        for(int i = 0; i < m.num_rows(); i++)
        {
            double sum = 0.0;
            for(int j = 0; j < m.num_col(); j++)
            {
                sum += m.val_idx(i,j) * v.val_idx(j);
            }
            ans.setValAt(i, sum);
        }
        return ans;
    }
    else
    {
        return Vector();
    }
}
