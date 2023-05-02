#include "Abitur.h"
#include <string>

using namespace std;

Abitur::Abitur()
{
	this->FIO = "NULL";
	this->spec = "NULL";
	this->ege = 0;
}

Abitur::Abitur(string f, string s, int e)
{
	this->FIO = f;
	this->spec = s;
	this->ege = e;
}

Abitur::Abitur(const Abitur& abit)
{
	this->FIO = abit.FIO;
	this->spec = abit.spec;
	this->ege = abit.ege;
}

Abitur::~Abitur() {}

string Abitur::get_fio()
{
	return this->FIO;
}

void Abitur::set_fio(string f)
{
	this->FIO = f;
}

string Abitur::get_spec()
{
	return this->spec;
}

void Abitur::set_spec(string s)
{
	this->spec = s;
}

int Abitur::get_ege()
{
	return this->ege;
}

void Abitur::set_ege(int e)
{
	this->ege = e;
}

void Abitur::show()
{
	cout << this->FIO << "\t" << this->spec << "\t" << this->ege;
}