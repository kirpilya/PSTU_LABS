#pragma once
#include <iostream>
#include <stack>

using namespace std;

template <class T>
class List_stack
{
private:
	stack<T> STACK;
public:
	List_stack();
	List_stack(int, T);
	List_stack(initializer_list<T>);
	~List_stack();

	void show();
	int size();
	void push_back(T);
	void pop_back();
	
	double avg();
	T max();
	void remove_in_range(T, T);
	void increase_elements(T);
};

template <class T>
List_stack<T>::List_stack() { }

template <class T>
List_stack<T>::List_stack(int n, T val)
{
	for (int i = 0; i < n; i++)
	{
		STACK.push(val);
	}
}

template <class T>
List_stack<T>::List_stack(initializer_list<T> i_l)
{
	const T* p = i_l.begin();
	while (p != i_l.end())
	{
		this->STACK.push(*p);
		p++;
	}
}

template <class T>
List_stack<T>::~List_stack() { }

template <class T>
void List_stack<T>::show()
{
	stack<T> temp;
	while (!(STACK.empty()))
	{
		cout << STACK.top() << " ";
		temp.push(STACK.top());
		STACK.pop();
	}
	while (!(temp.empty()))
	{
		STACK.push(temp.top());
		temp.pop();
	}
	cout << '\n';
}

template <class T>
int List_stack<T>::size()
{
	return STACK.size();
}

template <class T>
void List_stack<T>::push_back(T val)
{
	STACK.push(val);
}

template <class T>
void List_stack<T>::pop_back()
{
	STACK.pop();
}

template <class T>
double List_stack<T>::avg()
{
	double AVG = 0;
	stack<T> temp;
	while (!(STACK.empty()))
	{
		AVG += STACK.top();
		temp.push(STACK.top());
		STACK.pop();
	}
	while (!(temp.empty()))
	{
		STACK.push(temp.top());
		temp.pop();
	}
	return AVG / STACK.size();
}

template <class T>
T List_stack<T>::max()
{
	T MAX = STACK.top();
	stack<T> temp;
	while (!(STACK.empty()))
	{
		if (STACK.top() > MAX) MAX = STACK.top();
		temp.push(STACK.top());
		STACK.pop();
	}
	while (!(temp.empty()))
	{
		STACK.push(temp.top());
		temp.pop();
	}
	return MAX;
}

template <class T>
void List_stack<T>::remove_in_range(T r_beg, T r_end)
{
	stack<T> temp;
	while (!(STACK.empty()))
	{
		if (!(STACK.top() > r_beg && STACK.top() < r_end))
		{
			temp.push(STACK.top());
		}
		STACK.pop();
	}
	while (!(temp.empty()))
	{
		STACK.push(temp.top());
		temp.pop();
	}
}

template <class T>
void List_stack<T>::increase_elements(T val)
{
	stack<T> temp;
	while (!(STACK.empty()))
	{
		temp.push(STACK.top() + val);
		STACK.pop();
	}
	while (!(temp.empty()))
	{
		STACK.push(temp.top());
		temp.pop();
	}
}