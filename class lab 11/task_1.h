#pragma once
#include <iostream>
#include <deque>

using namespace std;

void show(deque<double>& d)
{
	for (auto i = d.begin(); i != d.end(); i++)
	{
		cout << *i << " ";
	}
	cout << '\n';
}

double deque_max(deque<double>& d)
{
	double max = d.at(0);
	for (auto i = d.begin(); i != d.end(); i++)
	{
		if (*i > max) max = *i;
	}
	return max;
}

double deque_avg(deque<double>& d)
{
	double avg = 0;
	for (auto i = d.begin(); i != d.end(); i++)
	{
		avg += *i;
	}
	return avg / d.size();
}

void task_1()
{
	cout << "Task 1\n\n";

	deque<double> deq = { 1.1, 10.3, 4.6, -2.8, 12.5, 8.7, 8.45, -7.22, 20.88, 14,9 };
	cout << "Deque:\n";
	show(deq);

	cout << "Max: " << deque_max(deq) << '\n';
	deq.push_back(deque_max(deq));
	cout << "Deque:\n";
	show(deq);

	cout << "range of values to delete: ";
	double r_beg, r_end;
	cin >> r_beg >> r_end;
	auto itr = deq.begin();
	while (itr != deq.end())
	{
		if (((*itr) >= r_beg) && ((*itr) <= r_end))
		{
			itr = deq.erase(itr);
		}
		else
		{
			itr++;
		}
	}
	cout << "Deque:\n";
	show(deq);

	auto deq_avg = deque_avg(deq);
	cout << "Deque avg: " << deq_avg << '\n';
	for (auto i = deq.begin(); i != deq.end(); i++)
	{
		*i += deq_avg;
	}
	cout << "Deque:\n";
	show(deq);

	cout << '\n\n';
}
