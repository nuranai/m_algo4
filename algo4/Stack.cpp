#include "Stack.h"
//коструктор
template <class T> Stack<T>::Stack() {
    top = nullptr;
    size = 0;
}
//деструктор
template <class T> Stack<T>::~Stack() {
    while (!IsEmpty()) { //пока есть элементы удаляем узлы
        Node<T> *temp = top;
        top = top->next;
        delete temp;
    }
}
//метод кладущий значение в стек
template <class T> void Stack<T>::Push(T item) {
    Node<T> *newNode = new Node<T>(item); //создаем новый узел
    newNode->next = top;

    top = newNode;    //присваиваем вершину к новуму узлу
    size++;           //увеличиваем размер
}
//метод извлекающий из стека
// и возвращающий этот элемент
template <class T> const T Stack<T>::Pop() {
    if (top == nullptr) { // если стек пуст вызываем исключение
        throw "Stack is empty!";
    }
    T data = top->key; // получаем значения которое удалится
    Node<T> *temp = top;    //запоминаем узел который будет удален
    top = top->next;   //присваиваем верщине следующее значение
    delete temp;    // удаляем предыдущий узел
    size--;         //уменьшаем размер стека
    return data;    // возвращаем значение
}
template <class T> int Stack<T>::GetSize() {
    return size; // размер стека
}
template <class T> bool Stack<T>::IsEmpty() {
    return top == nullptr;
}
