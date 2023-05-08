#pragma once
#include <iostream>
#include "List_stack.h"

using namespace std;

void task_5()
{
	cout << "Task 5\n\n";

	List_stack<int> LS = { 1, 4, 2, -4, 10, 0, 6, 8, -2, 12 };
	cout << "List_stack<int>:\n";
	LS.show();

	int max = LS.max();
	cout << "Max: " << max << '\n';
	LS.push_back(max);
	cout << "List_stack<int>:\n";
	LS.show();

	cout << "range of values to delete: ";
	int r_beg, r_end;
	cin >> r_beg >> r_end;
	LS.remove_in_range(r_beg, r_end);
	cout << "List_stack<int>:\n";
	LS.show();

	auto ls_avg = LS.avg();
	cout << "List_stack avg: " << ls_avg << '\n';
	LS.increase_elements(ls_avg);
	cout << "List_stack<int>:\n";
	LS.show();

	cout << '\n\n';
}