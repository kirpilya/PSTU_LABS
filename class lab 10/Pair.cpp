#include "Pair.h"

Pair::Pair()
{
	this->s = 0;
	this->f = 0;
}

Pair::Pair(int f, double s)
{
	this->s = s;
	this->f = f;
}

Pair::Pair(const Pair& p)
{
	this->f = p.f;
	this->s = p.s;
}

Pair::~Pair()
{

}

int Pair::get_f()
{
	return this->f;
}

double Pair::get_s()
{
	return this->s;
}

void Pair::set_f(int f)
{
	this->f = f;
}

void Pair::set_s(double s)
{
	this->s = s;
}

bool Pair::operator<(Pair& p)
{
	return (this->f + this->s) < (p.f + p.s);
}

bool Pair::operator>(Pair& p)
{
	return (this->f + this->s) > (p.f + p.s);
}

bool Pair::operator==(Pair& p)
{
	return (this->f + this->s) == (p.f + p.s);
}

void Pair::operator--()
{
	this->f -= 1;
}

void Pair::operator--(int v)
{
	this->s -= 1;
}

std::ostream& operator<<(std::ostream& os, Pair& p)
{
	os << p.f << ' ' << p.s;
	return os;
}

std::istream& operator>>(std::istream& is, Pair& p)
{
	is >> p.f >> p.s;
	return is;
}