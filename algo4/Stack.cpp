#include "Stack.h"
//����������
template <class T> Stack<T>::Stack() {
    top = nullptr;
    size = 0;
}
//����������
template <class T> Stack<T>::~Stack() {
    while (!IsEmpty()) { //���� ���� �������� ������� ����
        Node<T> *temp = top;
        top = top->next;
        delete temp;
    }
}
//����� �������� �������� � ����
template <class T> void Stack<T>::Push(T item) {
    Node<T> *newNode = new Node<T>(item); //������� ����� ����
    newNode->next = top;

    top = newNode;    //����������� ������� � ������ ����
    size++;           //����������� ������
}
//����� ����������� �� �����
// � ������������ ���� �������
template <class T> const T Stack<T>::Pop() {
    if (top == nullptr) { // ���� ���� ���� �������� ����������
        throw "Stack is empty!";
    }
    T data = top->key; // �������� �������� ������� ��������
    Node<T> *temp = top;    //���������� ���� ������� ����� ������
    top = top->next;   //����������� ������� ��������� ��������
    delete temp;    // ������� ���������� ����
    size--;         //��������� ������ �����
    return data;    // ���������� ��������
}
template <class T> int Stack<T>::GetSize() {
    return size; // ������ �����
}
template <class T> bool Stack<T>::IsEmpty() {
    return top == nullptr;
}
