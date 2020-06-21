/*
CH08-320143
a2_p4.cpp
Neeha Hammad
n.hammad@jacobs-university.de
*/

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

using namespace std;

//done similarly in C programming:
template<class T>
class Node
{
private:
public:
    T info;
    //we need two pointers to keep a track of
    //of previous and val and val at front
    Node *prev;
    Node *front;

    //setting pointers to first place:
    Node(T& info)
    {
        this->prev = 0;
        this->front = 0;
        this->info = info;
    }

    Node(T& info, Node *prev, Node *front)
    {
        this->info = info;
        this->prev = prev;
        this->front = front;
    }
    //destructor
    ~Node()
    {

    }
};

template<class T>
class LinkedList
{
private:
    Node<T> *first;
    Node<T> *last;
    int count;

public:
    LinkedList()
    {
        first = 0;
        last = 0;
        count = 0;
    }

    //these return the elements at front
    //and end without removing anything:

    T front(void);
    T end(void);
    T remove_front(void);
    T remove_end(void);

    //returns number of elements in the lst:

    int num_elements();

    //destructor:
    //deleting all nodes untill we reach NULL:

    ~LinkedList()
    {
        Node<T> *front;
        Node<T> *current = this->first;
        while (current != NULL)
        {
            front = current->front;
            delete current;
            current = front;
        }
    }

    //for adding an element in the beginning:
    //we set the first pointer to the new node
    //and increase the count
    //if there's only 1 element in the lst
    //we set both, the first and last pointer
    //to the new node. otherwise, we establish
    //a back link too since it's doubly linked lst

    void PushFront(T element)
    {
        Node<T>* new_node = new Node<T>(element, 0, this->first);
        this->first = new_node;
        this->count++;
        if (count>1)
        {
            new_node->front->prev = new_node;
        }
        else
        {
            this->last = new_node;
        }
        return;
    }

    //inserts a val at the end of the list
    //we set the last pointer to the new node
    //and increase the count
    //if there are more than 1 elements in the lst,
    //we establish the double link by linking
    //the front of new node's prev to new node
    //otherwise, we just point the "first" to
    //the new node:

    void PushEnd(T element)
    {
        Node<T> *new_node = new Node<T>(element, this->last, 0);
        this->last = new_node;
        this->count++;
        if (count > 1)
        {
            new_node->prev->front = new_node;
        }
        else
        {
            this->first = new_node;
        }
        return;
    }
};
//these return the elements at front
//and end without removing anything:

template<class T>
T LinkedList<T>:: front(void)
{
    return first->info;
}

template<class T>
T LinkedList<T>:: end(void)
{
    return last->info;
}

//removes the value at end of list
//and returns it:

template <class T>
T LinkedList<T>::remove_end(void)
{
    T store = end();
    Node<T>* new_end = last->prev;
    if (count >= 1)
    {
        delete last;
        last = new_end;
        count--;
        return store;
    }
    else
    {
cout << "List Already Empty" << endl;
        return 0;
    }
}

//first we store the val @ the front
//we remove the val at the front &
//return the val that was removed/stored:

template <class T>
T LinkedList<T>::remove_front(void)
{
    T store = front();
    Node <T>* new_start = first->front;
    if (count >= 1)
    {
        delete first;
        first = new_start;
        count--;
        return store;
    }
    else
    {
        cout << "List Already Empty" << endl;
        return 0;
    }
}

template <class T>
int LinkedList<T>::num_elements()
{
    return count;
}
#endif
