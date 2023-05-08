#pragma once
#include <iostream>
#include "List.h"

using namespace std;

void show(List<int>& l)
{
	for (auto i = l.begin(); i != l.end(); i++)
	{
		cout << *i << " ";
	}
	cout << '\n';
}

int List_max(List<int>& l)
{
	int max = *(l.begin());
	for (auto i = l.begin(); i != l.end(); i++)
	{
		if (*i > max) max = *i;
	}
	return max;
}

double List_avg(List<int>& l)
{
	double avg = 0;
	for (auto i = l.begin(); i != l.end(); i++)
	{
		avg += *i;
	}
	return avg / l.get_size();
}

void task_3()
{
	cout << "Task 3\n\n";

	List<int> L = { 2, 4, -1, 8, 0, 12, -5, 10, 20, 6 };
	cout << "List<int>:\n";
	show(L);

	int max = List_max(L);
	cout << "Max: " << max << '\n';
	L.push_back(max);
	cout << "List<int>:\n";
	show(L);
	
	cout << "range of values to delete: ";
	int r_beg, r_end;
	cin >> r_beg >> r_end;
	auto itr = L.begin();
	while (itr != L.end())
	{
		if (((*itr) >= r_beg) && ((*itr) <= r_end))
		{
			itr = L.erase(itr);
		}
		else
		{
			itr++;
		}
	}
	cout << "List<int>:\n";
	show(L);

	auto l_avg = List_avg(L);
	cout << "List avg: " << l_avg << '\n';
	for (auto i = L.begin(); i != L.end(); i++)
	{
		*i = *i + l_avg;
	}
	cout << "List<int>:\n";
	show(L);

	cout << '\n\n';

}