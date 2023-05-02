#pragma once
#include <iostream>
#include "Object.h"

using namespace std;

class Vector
{
private:
	int size;
	int it;
	Object** arr;
public:
	Vector(int);
	~Vector();
	void add(Object*);
	friend ostream& operator<<(ostream&, Vector&);
};

