#include "Vector.h"

Vector::Vector(int n)
{
	this->arr = new Object * [n];
	this->size = n;
	this->it = 0;
}

Vector::~Vector()
{
	if (this->size != 0)
	{
		delete[] arr;
	}
}

void Vector::add(Object* obj)
{
	if (this->it < this->size)
	{
		arr[it] = obj;
		it++;
	}
}

ostream& operator <<(ostream& os, Vector& vec)
{
	if (vec.size == 0)
	{
		os << "Пустой Vector\n";
	}
	else
	{
		os << "Содержимое Vector:\n\n";
		for (int i = 0; i < vec.it; i++)
		{
			cout << i + 1 << ".\n";
			vec.arr[i]->show();
			os << endl << endl;
		}
	}
	return os;
}