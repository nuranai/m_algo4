#pragma once
//����� ������������ ������
template<class T>
class Node {
public:
    //����������� ��� �����������
    Node() {
        key = nullptr;
        next = nullptr;
        prev = nullptr;
    }
    //����������� � �����������
    Node(T argKey) {
        key = argKey;
        next = nullptr;
        prev = nullptr;
    }
    T key; //�������� ����
    Node* next; //������ �� ���������� �����
    Node* prev; //������ �� ���� �����
};