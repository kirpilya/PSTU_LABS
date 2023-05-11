#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include "Pair.h"

using namespace std;

void show(stack<Pair, deque<Pair>> st)
{
	while (!(st.empty()))
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << '\n';
}

Pair stack_max(stack<Pair, deque<Pair>> st)
{
	Pair max = st.top();
	while (!(st.empty()))
	{
		if (st.top() > max) max.operator=(st.top());
		st.pop();
	}
	return max;
}

double stack_avg(stack<Pair, deque<Pair>> st)
{
	int size = st.size();
	double avg = 0;
	while (!(st.empty()))
	{
		avg += st.top().sum();
		st.pop();
	}
	return avg / size;
}

void task_2()
{
	cout << "Task 2\n\n";

	stack<Pair, deque<Pair>> ST;
	ST.push(Pair(3, 1.3)); ST.push(Pair(1, 1.1)); ST.push(Pair(2, 1.2)); ST.push(Pair(7, 1.7));
	ST.push(Pair(4, 1.4)); ST.push(Pair(6, 1.6)); ST.push(Pair(8, 1.8)); ST.push(Pair(5, 1.5));
	cout << "Stack<Pair, deque<Pair>>: \n";
	show(ST);

	Pair MAX = stack_max(ST);
	cout << "Max: " << MAX << endl;
	ST.push(MAX);
	cout << "Stack<Pair, deque<Pair>>: \n";
	show(ST);

	cout << "Range of elements to delete:\n";
	Pair r_beg, r_end;
	cin >> r_beg >> r_end;
	stack<Pair, deque<Pair>> temp;
	while (!(ST.empty()))
	{
		if (!(ST.top().sum() > r_beg.sum() && ST.top().sum() < r_end.sum()))
		{
			temp.push(ST.top());
		}
		ST.pop();
	}
	while (!(temp.empty()))
	{
		ST.push(temp.top());
		temp.pop();
	}
	cout << "Stack<Pair, deque<Pair>>: \n";
	show(ST);

	auto AVG = stack_avg(ST);
	cout << "Stack avg: " << AVG << endl;
	while (!(ST.empty()))
	{
		temp.push(ST.top() + AVG);
		ST.pop();
	}
	while (!(temp.empty()))
	{
		ST.push(temp.top());
		temp.pop();
	}
	cout << "Stack<Pair, deque<Pair>>: \n";
	show(ST);

	cout << "\n\n";
}