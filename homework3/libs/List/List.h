#pragma once
#include <iostream>
#include "../Products/Product.h"


struct Node {
	Product inf;
	Node* next;
	Node* prev;
};

class List{
private:
    Node* Head;
    Node* Tail;

public:
	List(){
		Head = nullptr;
		Tail = nullptr;
	}

	~List(){
		delList();
	}

	void push_back(Product value);

	void printProduct();

	bool findNode(Product value);

	bool findProduct(Product value);

	void insertAfter(Node* afterThis, Product value);

	void del_elem(Node* del_this);
    
	void delList(); 
};
