#pragma once
#include "Node.h"

template<class T>
class List
{
private:
	T data;
	Node<T>* top;
	Node<T>* end;
	int size;
public:
	List();
	~List();
	bool IsEmpty();
	void AddTop(T item);
	void AddEnd(T item);
	const T RemoveTop();
	const T RemoveEnd();
	int GetSize();
};

