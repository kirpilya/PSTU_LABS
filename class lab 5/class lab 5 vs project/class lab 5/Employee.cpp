#include "Employee.h"

Employee::Employee() : Person()
{
	this->role = "";
	this->salary = 0;
}

Employee::Employee(string n, int a, string r, double s) : Person(n, a)
{
	this->role = r;
	this->salary = s;
}

Employee::Employee(Employee& emp)
{
	this->set_name(emp.get_name());
	this->set_age(emp.get_age());
	this->role = emp.role;
	this->salary = emp.salary;
}

Employee::~Employee() {}

string Employee::get_role()
{
	return this->role;
}

double Employee::get_sal()
{
	return this->salary;
}

void Employee::set_role(string r)
{
	this->role = r;
}

void Employee::set_sal(double s)
{
	this->salary = s;
}

Employee& Employee::operator =(Employee& p)
{
	this->set_name(p.get_name());
	this->set_age(p.get_age());
	this->role = p.role;
	this->salary = p.salary;
	return *this;
}

ostream& operator<<(ostream& os, Employee& p)
{
	os << "name: " << p.get_name() << endl << "age: " << p.get_age() << endl << "role: " << p.role << endl << "salary: " << p.salary;
	return os;
}

istream& operator>>(istream& is, Employee& p)
{
	string tmp_name;
	int tmp_age;
	cout << "name: ";
	getline(is, tmp_name);
	cout << "age: ";
	is >> tmp_age;
	CLEARBUFFER;
	p.set_name(tmp_name);
	p.set_age(tmp_age);
	cout << "role: ";
	getline(is, p.role);
	cout << "salary: ";
	is >> p.salary;
	CLEARBUFFER;
	return is;
}

double Employee::CountSalary(int per)
{
	return (this->salary + this->salary * per / 100);
}

void Employee::show()
{
	cout << *this;
}