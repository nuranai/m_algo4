#include "Queue.h"

template <class T> Queue<T>::Queue() {
	top = nullptr;
	bottom = nullptr;
	size = 0;
}

template <class T> Queue<T>::~Queue() {
	while (!IsEmpty()) {
		Remove(); // ���� ������� �� �����, ������� �������� �� ���.
	}
}

template <class T> bool Queue<T>::IsEmpty() {
	return top == nullptr;
}

template <class T> void Queue<T>::Add(T item) {
	Node<T>* node = new Node<T>(item); // ������� ����� ���� � �������� ���������.

	if (IsEmpty()) {
		top = bottom = node; // ���� ������� �����, ������������� top � bottom �� ����� ����.
	}
	else {
		bottom->next = node; // ���� ������� �� �����, ��������� ��������� ������� � ����� �����.
		bottom = node; // ��������� ��������� �� ����� �������.
	}
	size++; // ����������� ������ �������.
}

template <class T> const T Queue<T>::Remove() {
	if (IsEmpty()) {
		throw "Queue is empty"; // ���� ������� �����, ����������� ����������.
	}
	Node<T>* oldTop = top; // ��������� ��������� �� ������� ������� �������.
	T val = oldTop->key; // ��������� �������� �������� �������� ��������.
	top = oldTop->next;
	if (!top) {
		bottom = nullptr; // ���� ������� ������� ��� ���������, ������������� bottom � nullptr.
	}
	delete oldTop; // ������� ������ ������� �������.
	size--; // ��������� ������ �������.
	return val; // ���������� �������� ���������� ��������.
}

template <class T> int Queue<T>::GetSize() {
	return size;
}
