/*
CH08-320143
a2_p3.cpp
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
        //dynamically allocating a fixed size
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
    void resize(int size);
    int getSize();

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
    if (count!=qsize)
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

//returns the allowed size of the queue:

template<class T>
int Queue<T>::getSize()
{
    return qsize;
}

//if size is smaller than the count, previous
//elements (that were added first) have to be lost
//we create a new queue
//if count < allowed size, then there's no problem
//and all elements can be copied into the new queue
//at the end, we say q=newnode to over write values
//in our original queue. we also have to update size
//in both cases:

template<class T>
void Queue<T>::resize(int size)
{
    T *new_node = new T[size];
    int i;
    if (count>size)
    {
        for(i = 0; i < size; i++)
        {
            new_node[i] = q[count-size+i];
        }
        count = size;
    }
    else
    {
        for(i = 0; i < count; i++)
        {
            new_node[i] = q[i];
        }
    }
    delete [] q;
    q = new_node;
    qsize = size;
}
