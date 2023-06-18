#ifndef HTABLE_H
#define HTABLE_H
#include <iostream>
#include "stack.h"

template<class T>
class HTable
{
protected:
    stack<T>* table;
    size_t size;
    size_t hash(const T& _key);
public:
    HTable(int s);
    ~HTable();
    void insert(const T& key);
    void remove(const T& key);
    bool search(const T& key) const;
};

#endif // HTABLE_H
