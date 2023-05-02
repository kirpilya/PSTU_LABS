#pragma once
#include <iostream>
#include <fstream>
#include "Pair.h"

using namespace std;

int make_file(const char* path)
{
	fstream f(path, ios::out);
	if (!f) return -1;
	Pair p;
	int n;
	cout << "N: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		f << p << '\n';
	}
	f.close();
	return n;
}

int print_file(const char* path)
{
	fstream f(path, ios::in);
	if (!f) return -1;
	Pair p; int n = 0;
	while (f >> p)
	{
		cout << p << '\n';
		n++;
	}
	f.close();
	return n;
}

int del_file(const char* path, int k)
{
	fstream temp("temp", ios::out);
	fstream f(path, ios::in);
	if (!f) return -1;
	Pair p; int i = 0;
	while (f >> p)
	{
		if (f.eof()) break;
		if (i != k) temp << p;
		i++;
	}
	f.close(); temp.close();
	remove(path);
	rename("temp", path);
	return i;
}

int del_by_data_file(const char* path, Pair pp)
{
	fstream temp("temp.txt", ios::out);
	fstream f(path, ios::in);
	if (!f) return -1;
	Pair p; int i = 0;
	while (f >> p)
	{
		if (f.eof()) break;
		if (!(p == pp)) temp << p << '\n';
		i++;
	}
	f.close(); temp.close();
	remove(path);
	rename("temp.txt", path);
	return i;
}

int add_after_file(const char* path, Pair pp, int K)
{
	fstream temp("temp", ios::out);
	fstream f(path, ios::in);
	if (!f) return -1;
	Pair p, pt; int i = 0;
	while (f >> p)
	{
		if (f.eof()) break;
		temp << p << '\n';
		if ((p == pp))
		{
			for (int i = 0; i < K; i++)
			{
				cin >> pt;
				temp << pt << '\n';
			}
			cout << endl << endl;
		}
		i++;
	}
	f.close(); temp.close();
	remove(path);
	rename("temp", path);
	return i;
}

int add_file(const char* path, int k, Pair pp)
{
	fstream temp("temp", ios::out);
	fstream f(path, ios::in);
	if (!f) return -1;
	Pair p; int i = 0, l = 0;
	while (f >> p)
	{
		if (f.eof()) break;
		if (i == k)
		{
			temp << pp;
			l++;
		}
		temp << p;
		i++;
	}
	f.close(); temp.close();
	remove(path);
	rename("temp", path);
	return l;
}

int add_end(const char* path, Pair pp)
{
	fstream f(path, ios::app);
	if (!f) return -1;
	f << pp;
	return 1;
}

int change_file(const char* path, int k, Pair pp)
{
	fstream temp("temp", ios::out);
	fstream f(path, ios::in);
	if (!f) return -1;
	Pair p; int i = 0, l = 0;
	while (f >> p)
	{
		if (f.eof()) break;
		if (i == k)
		{
			temp << pp;
			l++;
		}
		else temp << p;
		i++;
	}
	f.close(); temp.close();
	remove(path);
	rename("temp", path);
	return l;
}

int change_file_by_data(const char* path, Pair pp, int L)
{
	fstream temp("temp", ios::out);
	fstream f(path, ios::in);
	if (!f) return -1;
	Pair p; int i = 0;
	while (f >> p)
	{
		if (f.eof()) break;
		if (p == pp)
		{
			p.set_f(p.get_f() - L);
			p.set_s(p.get_s() - L);
		}
		temp << p << '\n';
		i++;
	}
	f.close(); temp.close();
	remove(path);
	rename("temp", path);
	return i;
}