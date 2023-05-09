#pragma once
#include <iostream>
#include "List_set.h"

using namespace std;

void task_3()
{
	cout << "Task 3\n\n";

	List_set<int> LS = { 2, 3, -1, 0, 12, -4, 5, 8, 6, 10 };
	cout << "List_set<int>:\n";
	LS.show();

	int MAX = LS.max();
	cout << "List_set max: " << MAX << '\n';
	LS.push(MAX);
	cout << "List_set<int>:    (set doesnt store identical elements so nothing changes)\n";
	LS.show();

	cout << "range of values to delete:\n";
	int r_beg, r_end;
	cin >> r_beg >> r_end;
	LS.remove_range(r_beg, r_end);
	cout << "List_set<int>:\n";
	LS.show();

	double ls_avg = LS.avg();
	cout << "List_set<int> avg: " << ls_avg << "\n";
	LS.increase_all(ls_avg);
	cout << "List_set<int>:\n";
	LS.show();

	cout << "\n\n";
}