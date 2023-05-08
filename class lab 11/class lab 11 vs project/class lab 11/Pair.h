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
        this->f = 0;
        this->s = 0;
    }
    Pair(int fi, double se)
    {
        this->f = fi;
        this->s = se;
    }
    Pair(const Pair& pa)
    {
        this->f = pa.f;
        this->s = pa.s;
    }
    ~Pair() {}

    int get_f()
    {
        return this->f;
    }
    double get_s()
    {
        return this->s;
    }
    void set_f(int fi)
    {
        this->f = fi;
    }
    void set_s(int se)
    {
        this->s = se;
    }

    double sum()
    {
        return this->f + this->s;
    }

    Pair& operator =(Pair& other)
    {
        this->f = other.f;
        this->s = other.s;
        return *this;
    }
    friend istream& operator >>(istream&, Pair&);
    friend ostream& operator <<(ostream&, Pair&);

    bool operator ==(Pair& p)
    {
        if ((this->f + this->s) == (p.f + p.s))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator <(Pair& p)
    {
        if ((this->f + this->s) < (p.f + p.s))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator >(Pair& p)
    {
        if ((this->f + this->s) > (p.f + p.s))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Pair& operator --()
    {
        this->f--;
        return *this;
    }
    Pair& operator --(int v)
    {
        this->s--;
        return *this;
    }
    Pair& operator +(double v)
    {
        this->s += v;
        return *this;
    }
};

istream& operator >>(istream& in, Pair& p)
{
    //cout << "first: ";
    in >> p.f;
    //cout << "second: ";
    in >> p.s;
    return in;
}
ostream& operator <<(ostream& out, Pair& p)
{
    out << p.f << ":" << p.s;
    return out;
}