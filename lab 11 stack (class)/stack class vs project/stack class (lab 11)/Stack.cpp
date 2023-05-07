#include <iostream>
#include "Stack.h"


void Stack::operator delete[](void* ptr)
{
	while (((Stack*)ptr)->head != nullptr)
	{
		Node* temp = ((Stack*)ptr)->head;
		((Stack*)ptr)->head = ((Stack*)ptr)->head->next;
		delete temp;
	}
	delete (Stack*)ptr;
}


Stack::Stack()
{
	this->head = nullptr;
	this->size = 0;
}

Stack::Stack(int n, int k)
{
	this->head = nullptr;
	this->size = 0;

	for (int i = 0; i < n; i++)
	{
		this->push(k);
	}
}

Stack::Stack(const Stack& st)
{
	this->head = nullptr;
	this->size = 0;

	Stack* temp_stack = new Stack;
	Node* temp_node = st.head;
	while (temp_node != nullptr)
	{
		temp_stack->push(temp_node->data);
		temp_node = temp_node->next;
	}
	temp_node = temp_stack->head;
	while (temp_node != nullptr)
	{
		this->push(temp_node->data);
		temp_node = temp_node->next;
	}
	temp_stack->operator delete[](temp_stack);
}

Stack::~Stack()
{
	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	size = 0;
}


void Stack::push(int k)
{
	Node* new_node = new Node;
	new_node->data = k;
	new_node->next = this->head;
	this->head = new_node;
	this->size++;
}

void Stack::pop()
{
	if (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
}

void print_nodes(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	else
	{
		print_nodes(node->next);
		std::cout << node->data << ' ';
	}
}

void Stack::print()
{
	if (head == nullptr)
	{
		std::cout << "Стек пуст\n";
		return;
	}
	else
	{
		print_nodes(head);
	}
}

void Stack::erase(int k)
{
	Stack* temp_stack = new Stack;
	while ((this->head->next != nullptr) && (this->head->data != k))
	{
		temp_stack->push(this->head->data);
		this->pop();
	}
	if (this->head->data == k)
	{
		this->pop();
		while (temp_stack->head != nullptr)
		{
			this->push(temp_stack->head->data);
			temp_stack->pop();
		}
	}
	else
	{
		while (temp_stack->head != nullptr)
		{
			this->push(temp_stack->head->data);
			temp_stack->pop();
		}
	}
	temp_stack->operator delete[](temp_stack);
}

void Stack::insert(int n, int k)
{
	Stack* temp_stack = new Stack;
	for (int i = this->size; i > n; i--)
	{
		temp_stack->push(this->head->data);
		this->pop();
	}
	this->push(k);
	while (temp_stack->head != nullptr)
	{
		this->push(temp_stack->head->data);
		temp_stack->pop();
	}
	temp_stack->operator delete[](temp_stack);
}