/*
CH08-320143
a2_p2.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <iostream>
#include <string>

using namespace std;

template <class T>

class Queue
{
private:
    int qsize;
    int count;
    T *q;       //queue

public:
    Queue()
    {
        //dynamically allocating a fixed size=10
        q = new T[10];
        qsize = 10;
        count = 0;
    }

    //copy constructor uses dynamic allocation
    Queue(const Queue& q)
    {
        qsize = q.qsize;
        count = q.count;
        q = new T[qsize];
        for(int i = 0; i < count; i++)
        {
            q[i] = q.q[i];
        }
    }

    Queue(int qsize)
    {
        q = new T[qsize];
        qsize = qsize;
        count = 0;
    }

    bool push(T element);
    bool pop(T& out);
    T back(void);
    T front(void);
    int getNumEntries();

    ~Queue()
    {
        delete [] q;
    }
};

//returns 1 if pushed successfully i.e
//when total number of elements has not
//exceeded possible total size

template <class T>
bool Queue<T>::push(const T element)
{
    if (count != qsize)
    {
        q[count] = element;
        count += 1;
        return true;
    }
    else
        cout <<"Stack is Already Full!"<< endl;
    return false;
}

//returns 1 if popped successfully
//i.e when queue has at least 1 element
//we pop the first[0] element and then shift
//all values to 1 place behind
//First In First Out

template<class T>
bool Queue<T>::pop(T &out)
{
    if (count!=0)
    {
        out = q[0];
        for (int i=0; i<count-1; i++)
        {
            q[i] = q[i+1];
        }
        count = count - 1;
        return true;
    }
    else
    {
        cout << "The Stack is Already Empty Stack" << endl;
        return false;
    }
}

//returns value on the first position:

template<class T>
T Queue<T>:: front(void)
{
    return this->q[0];
}

template<class T>
T Queue<T>:: back(void)
{
    return this->q[this->count-1];
}

template<class T>
int Queue<T>::getNumEntries()
{
    return count;
}
