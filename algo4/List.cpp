#include "List.h"


template <class T> List<T>::List() {
	top = nullptr;
	end = nullptr;
	size = 0;
}

template <class T> List<T>::~List() {
	while (!IsEmpty()) {
		RemoveTop(); // ���� ������ �� ����, ������� �������� � �������.
	}
}

template <class T> bool List<T>::IsEmpty() {
	return top == nullptr;
}

template <class T> void List<T>::AddTop(T item) {
	Node<T>* node = new Node<T>(item); // ������� ����� ���� � �������� ���������.
	if (IsEmpty()) {
		top = end = node; // ���� ������ ����, ������������� top � end �� ����� ����.
	}
	else {
		node->next = top; // ��������� ����� ���� � ������� ������� ���������.
		top->prev = node; // ��������� ������� �������� ������� � ����� �����.
		top = node; // ��������� ��������� �� ������� �������.
	}
	size++; // ����������� ������ ������.
}

template <class T> void List<T>::AddEnd(T item) {
	Node<T>* node = new Node<T>(item); // ������� ����� ���� � �������� ���������.
	if (IsEmpty()) {
		top = end = node; // ���� ������ ����, ������������� top � end �� ����� ����.
	}
	else {
		node->prev = end; // ��������� ����� ���� � ������� �������� ���������.
		end->next = node; // ��������� ������� ������� ������� � ����� �����.
		end = node; // ��������� ��������� �� ������� �������.
	}
	size++; // ����������� ������ ������.
}

template <class T> const T List<T>::RemoveTop() {
	if (IsEmpty()) {
		throw "List is empty!"; // ���� ������ ����, ����������� ����������.
	}
	Node<T>* oldTop = top; // ��������� ��������� �� ������� ������� �������.
	T value = oldTop->key; // ��������� �������� �������� �������� ��������.
	top = oldTop->next; // ��������� ��������� �� ������� �������.
	if (top) {
		top->prev = nullptr; // ���� ������� ������� ����������, �������� ��� ��������� �� ���������� �������.
	}
	else {
		end = nullptr; // ���� ������� ������� ��� ���������, ������������� end � nullptr.
	}
	delete oldTop; // ������� ������ ������� �������.
	size--; // ��������� ������ ������.
	return value; // ���������� �������� ���������� ��������.
}

template <class T> const T List<T>::RemoveEnd() {
	if (IsEmpty()) {
		throw "List is empty!"; // ���� ������ ����, ����������� ����������.
	}
	Node<T>* oldEnd = end; // ��������� ��������� �� ������� �������� �������.
	T value = oldEnd->key; // ��������� �������� �������� ��������� ��������.
	end = oldEnd->prev; // ��������� ��������� �� �������� �������.
	if (end) {
		end->next = nullptr; // ���� �������� ������� ����������, �������� ��� ��������� �� ��������� �������.
	}
	else {
		top = nullptr; // ���� �������� ������� ��� ������ ���������, ������������� top � nullptr.
	}
	delete oldEnd; // ������� ������ �������� �������.
	size--; // ��������� ������ ������.
	return value; // ���������� �������� ���������� ��������.
}

template <class T> int List<T>::GetSize() {
	return size;
}
