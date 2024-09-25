#pragma once
#include <iostream>
#include "../Products/Product.h"


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
	List(){
		Head = nullptr;
		Tail = nullptr;
	}

	~List(){
		delList();
	}

	void push_back(T value) {
		Node<T>* new_cell = new Node<T>;//создали новый элемент
		new_cell->inf = value;//присвоили ему значение;
		if (!Head && !Tail) {//если список пуст
			new_cell->prev = nullptr;// предыдущий пустой 
			Head = new_cell;//делаем новый элемент головой
		}
		else {
			Tail->next = new_cell;//делаем новый элемент следующим после хвоста
			new_cell->prev = Tail;//хвост - предыдущий элемент для нового элемента
		}
		Tail = new_cell;//делаем новый элемент хвостом
	}

	void print() {
		Node<T>* temp = Head;//доп указатель на голову
		while (temp != Tail->next && temp != nullptr) {//пока не дошли до конца
			//вывод значения элемента на котором находится указатель temp
			std::cout << temp->inf << " ";
			//передвигаем указатель на следующий элемент
			temp = temp->next;
		}
		std::cout << std::endl;
	}

	void printProduct() {
		Node<T>* temp = Head;//доп указатель на голову
		while (temp != Tail->next && temp != nullptr) {//пока не дошли до конца
			//вывод значения элемента на котором находится указатель temp
			temp->inf.printAll();
			//передвигаем указатель на следующий элемент
			temp = temp->next;
		}
		std::cout << std::endl;
	}

	bool findNode(T value){
		Node<T>* temp = Head;
		while (temp != nullptr) {
			if (temp->inf == value){
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	bool findProduct(T value){
		Node<T>* temp = Head;
		while (temp != nullptr) {
			if (value.compareArticle(temp->inf)){
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	void insertAfter(Node<T>* afterThis, T value) {
		Node<T>* temp = new Node<T>;//новый элемент
		temp->inf = value;//присваиваем значение
		//если вставляем после хвоста
		if (afterThis == Tail) {
			temp->next = nullptr;//вставляемый элемент будет последним
			Tail->next = temp;//делаем связи между хвостом и последним элементом
			temp->prev = Tail;
			Tail = temp;//ставим указатель на хвост на последний элемент
		}
		else {
			//для temp следующий элемент это следующий за afterThis
			temp->next = afterThis->next;
			
			//для temp предыдущий afterThis
			temp->prev = afterThis;
			//для следуещего за afterThis элемента предыдущий temp
			afterThis->next->prev = temp;
			//для afterThis следующий 
			
			afterThis->next = temp;
		}
	}

	void del_elem(Node<T>* del_this) {
		//если один элемент в списке то 
		if (Head == Tail) {
			//Head и Tail обнуляем
			Head = Tail = NULL;
		}
		//если удаляем голову  
		else if (Head == del_this) {
			//то сдвигаем указатель на голову на следующий элемент
			Head = Head->next;
			//обнуляем указатель на предыдущий
			Head->prev = NULL;
		}
		//если удаляем хвост
		else if (Tail == del_this) {
			//то сдвигаем указатель на хвост на предыдущий элемент
			Tail = Tail->prev;
			//обнуляем указатель на следующий элемент
			Tail->next = NULL;
		}
		//удаляем из середины
		else {
			//у элемента после удаляемого предыдущий = элементу перед удалемым
			(del_this->next)->prev = del_this->prev;
			//у элемента перед удаляемым следующий = элементу после удалемого
			(del_this->prev)->next = del_this->next;
		}
	
		delete del_this;
	}

	void delList() {
		//пока не дошли до конца
		while (Head) {
			Node<T>* temp = Head;//создали доп указатель на голову
			if (Head != Tail) {
				Head = Head->next;//двигаем голову на следующий элемент
				Head->prev = nullptr;//обнуляем указатель на предыдущий элемент
				delete temp;//удаляем элемент
			}
			else {
				Head = Tail = nullptr;
				break;
			}
		}
	}
};
