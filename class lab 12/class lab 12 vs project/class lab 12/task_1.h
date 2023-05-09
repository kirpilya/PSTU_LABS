#pragma once
#include <iostream>
#include <list>
#include <set>

using namespace std;

void show(set<double> s)
{
	for (auto& val : s)
	{
		cout << val << " ";
	}
	cout << '\n';
}

double max(set<double> s)
{
	auto it = s.begin();
	advance(it, s.size() - 1);
	return *it;
}

double avg(set<double> s)
{
	double AVG = 0;
	for (auto& val : s)
	{
		AVG += val;
	}
	return AVG / s.size();
}

void task_1()
{
	cout << "Task 1\n\n";

	set<double> S = { 2.1, 0.5, -4.4, 7.1, 5.9, 10.6, 9.9, -2.8, 12.6 };
	cout << "set<double>:\n";
	show(S);

	double MAX = max(S);
	cout << "set max: " << MAX << '\n';
	S.insert(MAX);
	cout << "set<double>:    (set doesnt store identical elements so nothing changes)\n";
	show(S);

	cout << "range of values to delete:\n";
	double r_beg, r_end;
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
	cout << "set<double> avg: " << s_avg << "\n";
	list<double> tmp;
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
	cout << "set<double>:\n";
	show(S);

	cout << "\n\n";
}

