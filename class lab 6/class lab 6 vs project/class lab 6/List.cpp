#include "List.h"
#include <iostream>


List::List()
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

List::List(int s, int k)
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;

	for (int i = 0; i < s; i++)
	{
		this->push_back(k);
	}
}

List::List(const List& a)
{
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
	if (this->size == 0)
	{
		std::cout << "pop_back() : список пуст\n";
	}
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
	if (this->size == 0)
	{
		std::cout << "pop_front() : список пуст\n";
	}
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


List& List::operator=(const List& a)
{
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
		cout << "Error index < 0\n";
	}
	else if (idx >= size)
	{
		cout << "Error index >= size\n";
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

List& List::operator+(int a)
{
	List* temp_list = new List;
	if (this->size != 0)
	{
		Node* temp = this->head;
		while (temp != nullptr)
		{
			temp_list->push_back(temp->data + a);
			temp = temp->next;
		}
	}
	return *temp_list;
}

List& List::operator+(List& a)
{
	if (this->size == a.size)
	{
		List* temp_list = new List;
		for (int i = 0; i < this->size; i++)
		{
			temp_list->push_back(this->operator[](i) + a[i]);
		}
		return *temp_list;
	}
	else
	{
		std::cout << "Can't add Lists of different length\n";
		return *this;
	}
}


List::iter::iter()
{
	this->p = nullptr;
	this->bl = nullptr;
}

List::iter::iter(const List::iter& it)
{
	this->p = it.p;
	this->bl = it.bl;
}


List::iter& List::iter::operator=(const List::iter& it)
{
	this->p = it.p;
	this->bl = it.bl;
	return *this;
}

bool List::iter::operator ==(const List::iter& it)
{
	return this->p == it.p;
}

bool List::iter::operator !=(const List::iter& it)
{
	return this->p != it.p;

}

List::iter& List::iter::operator ++(int v)
{
	this->p = this->p->next;
	return *this;
}

List::iter& List::iter::operator --(int v)
{
	this->p = this->p->prev;
	return *this;
}

int& List::iter::operator *()
{
	return this->p->data;
}


List::iter List::begin()
{
	List::iter temp;
	temp.p = this->head;
	temp.bl = this;
	return temp;
}

List::iter List::end()
{
	List::iter temp;
	temp.p = this->tail->next;
	temp.bl = this;
	return temp;
}