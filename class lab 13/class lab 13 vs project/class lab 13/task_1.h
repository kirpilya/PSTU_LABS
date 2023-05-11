#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include "Pair.h"

using namespace std;

void show(deque<Pair> dq)
{
	for_each(dq.begin(), dq.end(), [](const Pair& p) {cout << p << " "; });
	cout << endl;
}

double avg(deque<Pair> dq)
{
	double AVG = 0;
	for_each(dq.begin(), dq.end(), [&AVG](const Pair& p) {AVG += p.sum(); });
	return (AVG / dq.size());
}

void task_1()
{
	cout << "Task 1\n\n";

	deque<Pair> DQ = { Pair(3, 1.3), Pair(1, 1.1), Pair(2, 1.2), Pair(7, 1.7), Pair(4, 1.4), Pair(6, 1.6), Pair(8, 1.8), Pair(5, 1.5) };
	cout << "Deque<Pair>:\n";
	show(DQ);

	Pair MAX = *max_element(DQ.begin(), DQ.end());
	cout << "Max: " << MAX << endl;
	DQ.push_back(MAX);
	cout << "Deque<Pair>:\n";
	show(DQ);

	cout << "Sorting deque (less,g reater):\n";
	sort(DQ.begin(), DQ.end(), [](Pair& p1, Pair& p2) {return p1.sum() > p2.sum(); });
	show(DQ);
	sort(DQ.begin(), DQ.end(), [](Pair& p1, Pair& p2) {return p1.sum() < p2.sum(); });
	show(DQ);

	cout << "Range of elements to delete:\n";
	Pair r_beg, r_end;
	cin >> r_beg >> r_end;
	auto it_tmp = remove_if(DQ.begin(), DQ.end(), [&r_beg, &r_end](const Pair& p) {return (p.sum() > r_beg.sum() && p.sum() < r_end.sum()); });
	DQ.erase(it_tmp, DQ.end());
	cout << "Deque<Pair>:\n";
	show(DQ);

	double dq_avg = avg(DQ);
	cout << "Deque<Pair> avg: " << dq_avg << endl;
	
	for_each(DQ.begin(), DQ.end(), [&dq_avg](Pair& p) {p.set_s(p.get_s() + dq_avg); });
	cout << "Deque<Pair>:\n";
	show(DQ);

	cout << "\n\n";
}
