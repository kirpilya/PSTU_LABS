#pragma once
#include <iostream>

using namespace std;

class Pair
{
private:
    int f;
    double s;
public:
    Pair()
    {
        f = 0;
        s = 0;
    }
    Pair(int f, double s)
    {
        this->f = f;
        this->s = s;
    }
    friend ostream& operator<<(ostream& os, const Pair& p);
    void set(int f, double s)
    {
        this->f = f;
        this->s = s;
    }
};

ostream& operator<<(ostream& os, const Pair& p)
{
    os << p.f << " : " << p.s << "\n";
    return os;
}

