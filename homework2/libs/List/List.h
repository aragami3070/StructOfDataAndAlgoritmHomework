#pragma once
#include <iostream>
#include "../Transports/Transport.h"


struct Node {
	Transport* inf;
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

	void push_back(Transport* value);

	void printTransport();

	bool findNode(Transport* value);

	bool findTransport(Transport* value);

	void insertAfter(Node* afterThis, Transport* value);

	void del_elem(Node* del_this);
    
	void delList(); 
};
