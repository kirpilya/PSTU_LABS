#pragma once
#include <iostream>
#include <string>

using namespace std;

class Abitur
{
private:
	string FIO;
	string spec;
	int ege;
public:
	Abitur();
	Abitur(string, string, int);
	Abitur(const Abitur&);
	~Abitur();
	string get_fio();
	void set_fio(string);
	string get_spec();
	void set_spec(string);
	int get_ege();
	void set_ege(int);
	void show();
};

