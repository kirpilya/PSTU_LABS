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
    void set_s(double se)
    {
        this->s = se;
    }

    double sum() const
    {
        return this->f + this->s;
    }

    /*Pair& operator =(Pair& other)
    {
        this->f = other.f;
        this->s = other.s;
        return *this;
    }*/

    Pair operator =(Pair other)
    {
        this->f = other.f;
        this->s = other.s;
        return *this;
    }
    friend istream& operator >>(istream&, Pair&);
    friend ostream& operator <<(ostream&, Pair&);
    friend ostream& operator <<(ostream&, const Pair&);

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
    bool operator ==(const Pair& p) const
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
    bool operator <(const Pair& p) const
    {
        if (this->f + this->s < p.f + p.s) return true;
        return false;
    }
    bool operator <=(const Pair& p) const
    {
        if (this->f + this->s <= p.f + p.s) return true;
        return false;
    }
    bool operator >(const Pair& p) const
    {
        if (this->f + this->s > p.f + p.s) return true;
        return false;
    }
    bool operator >=(const Pair& p) const
    {
        if (this->f + this->s >= p.f + p.s) return true;
        return false;
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
ostream& operator <<(ostream& out, const Pair& p)
{
    out << p.f << ":" << p.s;
    return out;
}

bool pair_greater(Pair p1, Pair p2)
{
    return p1 > p2;
}

bool pair_less(Pair p1, Pair p2)
{
    return p1 < p2;
}

bool pair_in_range(Pair main, Pair r_b, Pair r_e)
{
    return (main.sum() > r_b.sum() && main.sum() < r_e.sum());
}