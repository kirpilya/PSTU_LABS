#include "List.h"
#include <iostream>


int MAX_SIZE = 30;


List::List()
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

List::List(int s, int k)
{
	if (s > MAX_SIZE) throw 1;

	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;

	for (int i = 0; i < s; i++)
	{
		this->push_back(k);
	}
}

List::List(List& a)
{
	if (a.get_size() > MAX_SIZE) throw 1;

	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;

	if (a.size != 0)
	{
		Node* temp = a.head;
		while (temp != nullptr)
		{
			this->push_back(temp->data);
			temp = temp->next;
		}
	}
}

List::~List()
{
	Node* temp;
	while (this->head != nullptr)
	{
		temp = this->head->next;
		delete this->head;
		this->head = temp;
	}
	this->size = 0;
	this->tail = nullptr;
}

List::List(initializer_list<int> i_l)
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;

	const int* p = i_l.begin();
	while (p != i_l.end())
	{
		this->push_back(*p);
		p++;
	}
}


void List::push_back(int val)
{
	if (this->size > MAX_SIZE-1) throw 1;

	Node* new_node = new Node;
	new_node->data = val;
	if (this->size != 0)
	{
		new_node->prev = this->tail;
		new_node->next = nullptr;
		this->tail->next = new_node;
		this->tail = new_node;
	}
	else
	{
		this->head = new_node;
		this->tail = new_node;
	}
	(this->size)++;
}

void List::pop_back()
{
	if (this->size == 0) throw 5;

	else if (this->size == 1)
	{
		delete this->head;
		this->head = nullptr;
		this->tail = nullptr;
		(this->size)--;
	}
	else
	{
		this->tail = this->tail->prev;
		delete this->tail->next;
		this->tail->next = nullptr;
		(this->size)--;
	}
}

void List::push_front(int val)
{
	if (this->size > MAX_SIZE - 1) throw 1;

	Node* new_node = new Node;
	new_node->data = val;
	if (this->size != 0)
	{
		new_node->prev = nullptr;
		new_node->next = this->head;
		this->head->prev = new_node;
		this->head = new_node;
	}
	else
	{
		this->head = new_node;
		this->tail = new_node;
	}
	(this->size)++;
}

void List::pop_front()
{
	if (this->size == 0) throw 5;

	else if (this->size == 1)
	{
		delete this->head;
		this->head = nullptr;
		this->tail = nullptr;
		(this->size)--;
	}
	else
	{
		this->head = this->head->next;
		delete this->head->prev;
		this->head->prev = nullptr;
		(this->size)--;
	}
}

int List::get_size()
{
	return this->size;
}


List& List::operator=(List& a)
{
	if (a.size > MAX_SIZE) throw 1;

	if (this->head != a.head)
	{
		// очищение контейнера которому присваивается другой
		this->~List();

		//копирование присваемого контейнера
		if (a.size != 0)
		{
			Node* temp = a.head;
			while (temp != nullptr)
			{
				this->push_back(temp->data);
				temp = temp->next;
			}
		}
	}
	return *this;
}

List& List::operator=(initializer_list<int> i_l)
{
	// очищение контейнера
	Node* temp4del;
	while (this->head != nullptr)
	{
		temp4del = this->head->next;
		delete this->head;
		this->head = temp4del;
	}
	this->size = 0;
	this->tail = nullptr;

	const int* p = i_l.begin();
	while (p != i_l.end())
	{
		this->push_back(*p);
		p++;
	}

	return (*this);
}

ostream& operator<<(ostream& os, const List& list)
{
	Node* temp = list.head;
	while (temp != nullptr)
	{
		os << temp->data << ' ';
		temp = temp->next;
	}
	return os;
}

istream& operator>>(istream& is, List& list)
{
	// очищение контейнера
	Node* temp4del;
	while (list.head != nullptr)
	{
		temp4del = list.head->next;
		delete list.head;
		list.head = temp4del;
	}
	list.size = 0;
	list.tail = nullptr;

	std::cout << "Размер списка: ";
	int new_size = 0;
	int tmp;
	std::cin >> new_size;

	for (int i = 0; i < new_size; i++)
	{
		std::cout << i + 1 << ". ";
		std::cin >> tmp;
		list.push_back(tmp);
	}
	return is;
}



int& List::operator[](int idx)
{
	if (idx < 0)
	{
		throw 2;
	}
	else if (idx >= size)
	{
		throw 3;
	}
	else
	{
		Node* temp = this->head;
		for (int i = 0; i < idx; i++)
		{
			temp = temp->next;
		}
		return temp->data;
	}
}

List& List::operator+(List& a)
{
	if (this->size + a.size > MAX_SIZE) throw 4;

	List* new_list = new List(*this);
	Node* temp_node = a.head;

	while (temp_node != nullptr)
	{
		new_list->push_back(temp_node->data);
		temp_node = temp_node->next;
	}

	return *new_list;
}

void List::operator+(int a)
{
	if (this->size > MAX_SIZE - 1) throw 1;
	this->push_front(a);
}
