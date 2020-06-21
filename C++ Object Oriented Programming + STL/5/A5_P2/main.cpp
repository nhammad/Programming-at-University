/*
CH08-320143
a5_p2.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include <exception>

using namespace std;

class OwnException: public exception
{
public:
    string display;
public:
    //parametric constructor:
    OwnException(string newdisplay)
    {
        this->display = newdisplay;
    }

    //copy constructor:
    OwnException(const OwnException &d)
    {
        display = d.display;
    }

    //destructor:
    virtual ~OwnException() {}

    //overwriting of what method. if this is
    //virtual, destructor also has to be virtual
    virtual const char* what() const throw()
    {
        return "This is an OwnException\n";
    }
};
void type_error(int para)
{
    switch(para)
    {
    case '1':
        throw('e');
        break;
    case '2':
        throw(99);
        break;
    case '3':
        throw(false);
        break;
    default:
        throw OwnException("This is a default case exception\n");
        break;
    }
}
int main()
{
    try
    {
        type_error('1');
    }
    catch(char c)
    {
        cerr << "Exception caught in main: " << c << endl;
    }

    try
    {
        type_error('2');
    }
    catch(int c)
    {
        cerr << "Exception caught in main: " << c << endl;
    }

    try
    {
        type_error('3');
    }
    catch(bool c)
    {
        //prints 0
        cerr << "Exception caught in main: " << c << endl;
    }

    try
    {
        type_error('4');
    }

    //this is a type so we write OwnException:
    //prints the result of overwriting what()
    catch(OwnException &c)
    {
        cerr << c.what() << endl;
    }

    return 0;
}
