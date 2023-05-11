#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include <set>
#include "Pair.h"

using namespace std;

void show(set<Pair> s)
{
	for_each(s.begin(), s.end(), [](const Pair& p) {cout << p << " "; });
	cout << endl;
}

double avg(set<Pair> s)
{
	double AVG = 0;
	for_each(s.begin(), s.end(), [&AVG](const Pair& p) {AVG += p.sum(); });
	return (AVG / s.size());
}

void task_3()
{
	cout << "Task 3\n\n";

	set<Pair> S = { Pair(3, 1.3), Pair(1, 1.1), Pair(2, 1.2), Pair(7, 1.7), Pair(4, 1.4), Pair(6, 1.6), Pair(8, 1.8), Pair(5, 1.5) };
	cout << "Set<Pair>:\n";
	show(S);

	Pair MAX = *max_element(S.begin(), S.end());
	cout << "Set<Pair> max: " << MAX << endl;
	S.insert(MAX);
	cout << "set<Pair>:    (set doesnt store indentical elements so nothing changes)\n";
	show(S);

	cout << "Range of elements to delete:\n";
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
	cout << "Set<Pair>:\n";
	show(S);
	
	double s_avg = avg(S);
	cout << "set<Pair> avg: " << s_avg << endl;
	list<Pair> temp;
	auto itr = S.begin();
	while (itr != S.end())
	{
		temp.push_back(*itr);
		itr = S.erase(itr);
	}
	for_each(temp.begin(), temp.end(), [&S, &s_avg](Pair& p) {S.insert(p + s_avg); });
	cout << "Set<Pair>:\n";
	show(S);


	cout << "\n\n";

}