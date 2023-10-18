#include "Queue.h"

template <class T> Queue<T>::Queue() {
	top = nullptr;
	bottom = nullptr;
	size = 0;
}

template <class T> Queue<T>::~Queue() {
	while (!IsEmpty()) {
		Remove(); // Пока очередь не пуста, удаляем элементы из нее.
	}
}

template <class T> bool Queue<T>::IsEmpty() {
	return top == nullptr;
}

template <class T> void Queue<T>::Add(T item) {
	Node<T>* node = new Node<T>(item); // Создаем новый узел с заданным элементом.

	if (IsEmpty()) {
		top = bottom = node; // Если очередь пуста, устанавливаем top и bottom на новый узел.
	}
	else {
		bottom->next = node; // Если очередь не пуста, связываем последний элемент с новым узлом.
		bottom = node; // Обновляем указатель на конец очереди.
	}
	size++; // Увеличиваем размер очереди.
}

template <class T> const T Queue<T>::Remove() {
	if (IsEmpty()) {
		throw "Queue is empty"; // Если очередь пуста, выбрасываем исключение.
	}
	Node<T>* oldTop = top; // Сохраняем указатель на текущий верхний элемент.
	T val = oldTop->key; // Сохраняем значение текущего верхнего элемента.
	top = oldTop->next;
	if (!top) {
		bottom = nullptr; // Если верхний элемент был последним, устанавливаем bottom в nullptr.
	}
	delete oldTop; // Удаляем старый верхний элемент.
	size--; // Уменьшаем размер очереди.
	return val; // Возвращаем значение удаленного элемента.
}

template <class T> int Queue<T>::GetSize() {
	return size;
}
