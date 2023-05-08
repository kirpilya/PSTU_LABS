#pragma once
#include <iostream>
#include <stack>
#include "Pair.h"

using namespace std;

void show(stack<Pair> s)
{
	while (!(s.empty()))
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << '\n';
}

Pair stack_max(stack<Pair> s)
{
	Pair max = s.top();
	while (!(s.empty()))
	{
		if (s.top() > max) max = s.top();
		s.pop();
	}
	return max;
}

double stack_avg(stack<Pair> s)
{
	int size = s.size();
	double avg = 0;
	while (!(s.empty()))
	{
		avg += s.top().sum();
		s.pop();
	}
	return avg / size;
}

void task_4()
{
	cout << "Task 4\n\n";

	stack<Pair> S;
	S.push(Pair(1, 1.1)); S.push(Pair(4, 1.4)); S.push(Pair(5, 1.5)); S.push(Pair(2, 1.2)); S.push(Pair(7, 1.7)); S.push(Pair(3, 1.3)); S.push(Pair(6, 1.6));
	cout << "stack<Pair>:\n";
	show(S);
	
	Pair max = stack_max(S);
	cout << "Max: " << max << '\n';
	S.push(max);
	cout << "stack<Pair>:\n";
	show(S);

	cout << "range of values to delete: ";
	double r_beg, r_end;
	cin >> r_beg >> r_end;
	stack<Pair> temp;
	while (!(S.empty()))
	{
		if (!(S.top().sum() > r_beg && S.top().sum() < r_end))
		{
			temp.push(S.top());
		}
		S.pop();
	}
	while (!(temp.empty()))
	{
		S.push(temp.top());
		temp.pop();
	}
	cout << "stack<Pair>:\n";
	show(S);

	auto s_avg = stack_avg(S);
	cout << "stack avg: " << s_avg << '\n';
	while (!(S.empty()))
	{
		temp.push(S.top() + s_avg);
		S.pop();
	}
	while (!(temp.empty()))
	{
		S.push(temp.top());
		temp.pop();
	}
	cout << "stack<Pair>:\n";
	show(S);

	cout << '\n\n';
	
}