#pragma once
#include <iostream>
#include "Pair.h"
#include <list>
#include <set>

using namespace std;

void show(set<Pair> s)
{
	for (auto& val : s)
	{
		cout << val << " ";
	}
	cout << '\n';
}

Pair max(set<Pair> s)
{
	auto it = s.begin();
	advance(it, s.size() - 1);
	return *it;
}

double avg(set<Pair> s)
{
	double AVG = 0;
	for (auto& val : s)
	{
		AVG += val.sum();
	}
	return AVG / s.size();
}

void task_2()
{
	cout << "Task 2\n\n";

	set<Pair> S = { Pair(3, 1.3), Pair(1, 1.1), Pair(2, 1.2), Pair(7, 1.7), Pair(4, 1.4), Pair(6, 1.6), Pair(8, 1.8), Pair(5, 1.5) };
	cout << "set<Pair>:\n";
	show(S);

	Pair MAX = max(S);
	cout << "set max: " << MAX << '\n';
	S.insert(MAX);
	cout << "set<Pair>:    (set doesnt store identical elements so nothing changes)\n";
	show(S);

	cout << "range of values to delete: (Pair)\n";
	Pair r_beg, r_end;
	cin >> r_beg >> r_end;
	auto it = S.begin();
	while (it != S.end())
	{
		if (*it > r_beg && *it < r_end)
		{
			it = S.erase(it);
		}
		else
		{
			it++;
		}
	}
	cout << "set<double>:\n";
	show(S);

	double s_avg = avg(S);
	cout << "set<Pair> avg: " << s_avg << "\n";
	list<Pair> tmp;
	auto itr = S.begin();
	while (itr != S.end())
	{
		tmp.push_back(*itr);
		itr = S.erase(itr);
	}
	for (auto& val : tmp)
	{
		S.insert(val + s_avg);
	}
	cout << "set<Pair>:\n";
	show(S);

	cout << "\n\n";
}