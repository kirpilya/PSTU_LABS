#pragma once
#include "Person.h"

class Employee : public Person
{
private:
	string role;
	double salary;
public:
	Employee();
	Employee(string, int, string, double);
	Employee(Employee&);
	~Employee();
	string get_role();
	double get_sal();
	void set_role(string);
	void set_sal(double);
	Employee& operator =(Employee&);
	friend ostream& operator<<(ostream&, Employee&);
	friend istream& operator>>(istream&, Employee&);
	double CountSalary(int per);
	void show() override;
};
