#pragma once
#include <cstddef>
#include <iostream>

struct Node {
	int key;
	Node* next = NULL;
};

class LinkedListQueue
{
	Node* _head;
	Node* _tail;
	int _capacity;
	int _num;
public:
	Node* getHead() { return this->_head; }
	Node* getTail() { return this->_tail; }
	int getCapacity() { return this->_capacity; }
	int getNum() { return this->_num;}

	void setHead(Node* ptr) { this->_head = ptr; }
	void setTail(Node* ptr) { this->_tail = ptr; }
	void setCapacity(int value) { this->_capacity = value; }
	void setNum(int value) { this->_num = value; }

	void init(int);
	void push(int);
	int dequeue();
	int peek();
	bool isEmpty();
	bool isFull();
	void clear();
	void travel();
};