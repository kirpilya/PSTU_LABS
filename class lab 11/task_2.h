#pragma once
#include <iostream>
#include <List>
#include "Pair.h"

using namespace std;

void show(list<Pair>& L)
{
	for (auto i = L.begin(); i != L.end(); i++)
	{
		cout << *i << " ";
	}
	cout << '\n';
}

Pair list_max(list<Pair> l)
{
	Pair max = *(l.begin());
	for (auto i = l.begin(); i != l.end(); i++)
	{
		if (*i > max)
		{
			max = *i;
		}
	}
	return max;
}

double list_avg(list<Pair> l)
{
	double avg = 0;
	for (auto i = l.begin(); i != l.end(); i++)
	{
		avg += (*i).sum();
	}
	return avg / l.size();
}

void task_2()
{
	cout << "Task 2\n\n";

	list<Pair> L = {Pair(1, 1.1), Pair(7, 1.7), Pair(3, 1.3), Pair(4, 1.4), Pair(2, 1.2), Pair(6, 1.6), Pair(5, 1.5)};
	cout << "List<Pair>:\n";
	show(L);

	Pair max = list_max(L);
	cout << "Max:  " << max << '\n';
	L.push_back(max);
	cout << "List<Pair>:\n";
	show(L);

	cout << "range of values to delete: ";
	double r_beg, r_end;
	cin >> r_beg >> r_end;
	auto itr = L.begin();
	while (itr != L.end())
	{
		if (((*itr).sum() > r_beg) && ((*itr).sum() < r_end))
		{
			itr = L.erase(itr);
		}
		else
		{
			itr++;
		}
	}
	cout << "List<Pair>:\n";
	show(L);

	auto l_avg = list_avg(L);
	cout << "List avg: " << l_avg << '\n';
	for (auto i = L.begin(); i != L.end(); i++)
	{
		*i = *i + l_avg;
	}
	cout << "List:\n";
	show(L);

	cout << '\n\n';

}