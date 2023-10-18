#pragma once
#include "Node.h"

template<class T>
class Stack
{
private:
    Node<T>* top; //полседний элемент стека
    int size; //резмерность стека
public:
	Stack();
	~Stack();
    void Push(T item);
    const T Pop();
    int GetSize();
    bool IsEmpty();
};

