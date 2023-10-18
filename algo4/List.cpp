#include "List.h"


template <class T> List<T>::List() {
	top = nullptr;
	end = nullptr;
	size = 0;
}

template <class T> List<T>::~List() {
	while (!IsEmpty()) {
		RemoveTop(); // Пока список не пуст, удаляем элементы с вершины.
	}
}

template <class T> bool List<T>::IsEmpty() {
	return top == nullptr;
}

template <class T> void List<T>::AddTop(T item) {
	Node<T>* node = new Node<T>(item); // Создаем новый узел с заданным элементом.
	if (IsEmpty()) {
		top = end = node; // Если список пуст, устанавливаем top и end на новый узел.
	}
	else {
		node->next = top; // Связываем новый узел с текущим верхним элементом.
		top->prev = node; // Связываем текущий конечный элемент с новым узлом.
		top = node; // Обновляем указатель на верхний элемент.
	}
	size++; // Увеличиваем размер списка.
}

template <class T> void List<T>::AddEnd(T item) {
	Node<T>* node = new Node<T>(item); // Создаем новый узел с заданным элементом.
	if (IsEmpty()) {
		top = end = node; // Если список пуст, устанавливаем top и end на новый узел.
	}
	else {
		node->prev = end; // Связываем новый узел с текущим конечным элементом.
		end->next = node; // Связываем текущий верхний элемент с новым узлом.
		end = node; // Обновляем указатель на верхний элемент.
	}
	size++; // Увеличиваем размер списка.
}

template <class T> const T List<T>::RemoveTop() {
	if (IsEmpty()) {
		throw "List is empty!"; // Если список пуст, выбрасываем исключение.
	}
	Node<T>* oldTop = top; // Сохраняем указатель на текущий верхний элемент.
	T value = oldTop->key; // Сохраняем значение текущего верхнего элемента.
	top = oldTop->next; // Обновляем указатель на верхний элемент.
	if (top) {
		top->prev = nullptr; // Если верхний элемент существует, обнуляем его указатель на предыдущий элемент.
	}
	else {
		end = nullptr; // Если верхний элемент был последним, устанавливаем end в nullptr.
	}
	delete oldTop; // Удаляем старый верхний элемент.
	size--; // Уменьшаем размер списка.
	return value; // Возвращаем значение удаленного элемента.
}

template <class T> const T List<T>::RemoveEnd() {
	if (IsEmpty()) {
		throw "List is empty!"; // Если список пуст, выбрасываем исключение.
	}
	Node<T>* oldEnd = end; // Сохраняем указатель на текущий конечный элемент.
	T value = oldEnd->key; // Сохраняем значение текущего конечного элемента.
	end = oldEnd->prev; // Обновляем указатель на конечный элемент.
	if (end) {
		end->next = nullptr; // Если конечный элемент существует, обнуляем его указатель на следующий элемент.
	}
	else {
		top = nullptr; // Если конечный элемент был первым элементом, устанавливаем top в nullptr.
	}
	delete oldEnd; // Удаляем старый конечный элемент.
	size--; // Уменьшаем размер списка.
	return value; // Возвращаем значение удаленного элемента.
}

template <class T> int List<T>::GetSize() {
	return size;
}
