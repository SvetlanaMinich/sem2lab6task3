#pragma once
#ifndef STACK_H
#define STACK_H
#include <iostream>

template<class T>
class stack
{
private:
    struct Node
    {
        Node* next;
        T data;
        Node():next(nullptr),data(T()){}
        Node(const T& _data):next(nullptr),data(_data){}
    };
    size_t size;
    Node* _top;
public:
    stack();
    stack(const stack& other);
    ~stack();
    void push(const T& el);
    T& top();
    T pop();
    bool empty();
    void clear();
};

#endif // STACK_H
