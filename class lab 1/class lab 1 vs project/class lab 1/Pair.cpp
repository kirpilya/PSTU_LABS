#include <iostream>
#include "Pair.h"
using namespace std;

void Pair::init(int f, double s)
{
	this->first = f;
	this->second = s;
}

double Pair::get()
{
	return this->first + this->second;
}

void Pair::read()
{
	cout << "Целая часть: ";
	cin >> this->first;
	cout << "Дробная часть: ";
	cin >> this->second;
}

void Pair::show()
{
	cout << "First: " << this->first << "\tSecond: " << this->second << "\t=\t" << this->first + this->second;
}

double Pair::multiply(double k)
{
	return (this->first + this->second) * k;
}