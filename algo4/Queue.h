#pragma once
#include "Node.h"

template<class T>
class Queue
{
private:
	Node<T>* top;
	Node<T>* bottom;
	int size;
public:
	Queue();
	~Queue();
	void Add(T item);
	const T Remove();
	int GetSize();
	bool IsEmpty();
};

