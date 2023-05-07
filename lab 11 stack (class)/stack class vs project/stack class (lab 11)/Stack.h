#pragma once

struct Node
{
	int data;
	Node* next = nullptr;
};

class Stack
{
private:
	int size;
	Node* head;
public:
	Stack();
	Stack(int, int);
	Stack(const Stack&);
	~Stack();
	void push(int);
	void pop();
	void print();
	void erase(int);
	void insert(int, int);

	void operator delete[](void* ptr);
};

