#include "htable.h"

template<class T>
HTable<T>::HTable(int s)
{
    size = s;
    for(int i=0;i<size;i++)
    {
        table[i]=new stack<T>();
    }
}
template<class T>
HTable<T>::~HTable()
{
    for(int i=0;i<size;i++)
    {
        table[i].clear();
    }
}
template<class T>
size_t HTable<T>::hash(const T& key)
{
    return abs(key)%size;
}
template<class T>
void HTable<T>::insert(const T& key)
{
    table[hash(key)]->push(key);
}
template<class T>
void HTable<T>::remove(const T& key)
{
    stack<T>* stackPtr = table[hash(key)];
    stack<T>* stackBuf;
    while(!stackPtr->empty())
    {
        T current = stackPtr->pop();
        if(current!=key)
        {
            stackBuf->push(current);
        }
    }
    while(!stackBuf->empty())
    {
        stackPtr->push(stackBuf->pop());
    }
}
template<class T>
bool HTable<T>::search(const T& key) const
{
    stack<T>* stackPtr = table[hash(key)];
    stack<T> stackBuf;
    bool is_here = false;
    while(!stackPtr->empty())
    {
        T current = stackPtr->pop();
        if(current==key)
        {
            is_here=true;
        }
        stackBuf.push(current);
    }
    while(!stackBuf.empty())
    {
        stackPtr->push(stackBuf.pop());
    }
    return is_here;
}










