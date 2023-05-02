#pragma once
#include <iostream>
#include <string>
#undef max()
#define CLEARBUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

class Person
{
private:
	string name;
	int age;
public:
	Person();
	Person(string, int);
	Person(const Person&);
	~Person();
	string get_name();
	int get_age();
	void set_name(string);
	void set_age(int);
	Person& operator =(Person&);
	friend ostream& operator<<(ostream&, Person&);
	friend istream& operator>>(istream&, Person&);
};

