#include "Person.h"

Person::Person()
{
	this->name = "";
	this->age = 0;
}

Person::Person(string n, int a)
{
	this->name = n;
	this->age = a;
}

Person::Person(const Person& p)
{
	this->name = p.name;
	this->age = p.age;
}

Person::~Person() {}

string Person::get_name()
{
	return this->name;
}

int Person::get_age()
{
	return this->age;
}

void Person::set_name(string n)
{
	this->name = n;
}

void Person::set_age(int a)
{
	this->age = a;
}

Person& Person::operator =(Person& p)
{
	this->name = p.name;
	this->age = p.age;
	return *this;
}

ostream& operator<<(ostream& os, Person& p)
{
	os << "name: " << p.name << endl << "age: " << p.age;
	return os;
}

istream& operator>>(istream& is, Person& p)
{
	cout << "name: ";
	getline(is, p.name);
	cout << "age: ";
	is >> p.age;
	CLEARBUFFER;
	return is;
}

void Person::show()
{
	cout << *this;
}