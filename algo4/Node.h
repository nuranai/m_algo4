#pragma once
//класс односвязного списка
template<class T>
class Node {
public:
    //конструктор без аргаументов
    Node() {
        key = nullptr;
        next = nullptr;
        prev = nullptr;
    }
    //конструктор с аргументами
    Node(T argKey) {
        key = argKey;
        next = nullptr;
        prev = nullptr;
    }
    T key; //значение узла
    Node* next; //ссылка на предыдущее звено
    Node* prev; //ссылка на след звено
};