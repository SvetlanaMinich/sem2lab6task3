#include "stack.h"

template<class T>
stack<T>::stack()
{
    size = 0;
    _top = new Node();
}
template<class T>
stack<T>::stack(const stack& other)
{
    if(!other._top)
    {
        _top = nullptr;
        size = 0;
    }
    else
    {
        auto t = other._top;
        auto t2 = new Node(t->data);
        t = t->next;
        _top = t2;
        size = other.size;
        while(t)
        {
            t2->next = new Node();
            t2=t2->next;
            t2->data=t->data;
            t=t->next;
        }
        t2->next=nullptr;
    }
}
template<class T>
stack<T>::~stack()
{
    Node* t = _top;
    for(int i=0;i<size;i++)
    {
        Node* buf = t->next;
        delete t;
        t=buf;
    }
}
template<class T>
void stack<T>::push(const T& el)
{
    auto newEl = new Node(el);
    if(size>0)
    {
        newEl->next=_top;
        _top=newEl;
    }
    else
    {
        newEl->next=nullptr;
        _top=newEl;
    }
    size++;
}
template<class T>
T& stack<T>::top()
{
    if(!_top)
    {
        _top=new Node();
    }
    return _top->data;
}
template<class T>
T stack<T>::pop()
{
    if(size)
    {
        auto d = _top->data;
        Node* t = _top->next;
        delete _top;
        _top=t;
        size--;
        return d;
    }
    else
    {
        return T();
    }
}
template<class T>
bool stack<T>::empty()
{
    return !size;
}
template<class T>
void stack<T>::clear()
{
    while(size)
    {
        pop();
    }
    _top=new Node();
}










