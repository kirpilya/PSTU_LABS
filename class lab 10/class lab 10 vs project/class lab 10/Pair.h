#pragma once
#include <iostream>

class Pair
{
private:
	int f;
	double s;
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair();

	int get_f();
	double get_s();
	void set_f(int);
	void set_s(double);

	bool operator<(Pair&);
	bool operator>(Pair&);
	bool operator==(Pair&);
	void operator--();
	void operator--(int);

	friend std::ostream& operator<<(std::ostream&, Pair&);
	friend std::istream& operator>>(std::istream&, Pair&);
};

