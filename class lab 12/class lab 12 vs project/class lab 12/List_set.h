#pragma once
#include <set>
#include <list>
#include <iostream>

using namespace std;

template <class T>
class List_set
{
private:
	set<T> SET;
public:
	List_set();
	List_set(initializer_list<T>);
	~List_set();

	void show();
	int size();
	void push(T);
	void pop(T);

	double avg();
	T max();
	void remove_range(T, T);
	void increase_all(T);
};

template <class T>
List_set<T>::List_set() {};

template <class T>
List_set<T>::List_set(initializer_list<T> i_l)
{
	const T* p = i_l.begin();
	while (p != i_l.end())
	{
		this->SET.insert(*p);
		p++;
	}
}

template <class T>
List_set<T>::~List_set() {};

template <class T>
void List_set<T>::show()
{
	for (auto& val : this->SET)
	{
		cout << val << " ";
	}
	cout << '\n';
}

template <class T>
int List_set<T>::size()
{
	return this->SET.size();
}

template <class T>
void List_set<T>::push(T val) 
{
	this->SET.insert(val);
}

template <class T>
void List_set<T>::pop(T val)
{
	this->SET.erase(val);
}

template <class T>
double List_set<T>::avg()
{
	double AVG = 0;
	for (auto& val : this->SET)
	{
		AVG += val;
	}
	return AVG / this->SET.size();
}

template <class T>
T List_set<T>::max()
{
	auto it = this->SET.begin();
	advance(it, SET.size() - 1);
	return *it;
}

template <class T>
void List_set<T>::remove_range(T r_beg, T r_end)
{
	auto it = SET.begin();
	while (it != SET.end())
	{
		if (*it > r_beg && *it < r_end)
		{
			it = SET.erase(it);
		}
		else
		{
			it++;
		}
	}
}

template <class T>
void List_set<T>::increase_all(T val)
{
	list<T> tmp;
	auto itr = SET.begin();
	while (itr != SET.end())
	{
		tmp.push_back(*itr);
		itr = SET.erase(itr);
	}
	for (auto& val : tmp)
	{
		SET.insert(val + val);
	}
}