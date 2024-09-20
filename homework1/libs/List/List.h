#pragma once


template <typename T>
struct Node {
	T inf;
	Node* next;
	Node* prev;
};

template <typename T>
class List{
private:
    Node<T>* Head;
    Node<T>* Tail;

public:
    List();

    ~List();

    void push_back(T value);

    void print();

    void insertAfter(Node<T>* afterThis, T value);

    bool findNode(T value);

    void del_elem(Node<T>* del_this);

    void delList();
};
