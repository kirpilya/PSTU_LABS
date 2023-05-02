#include <iostream>
#include "Pair.h"

using namespace std;

Pair make_pair(int f, double s)
{
    Pair temp;
    temp.init(f, s);
    return temp;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    Pair A;
    A.init(1, 0.4);
    A.show();
    cout << endl << "A * 2 = " << A.multiply(2);
    
    cout << endl << endl;

    Pair B = make_pair(10, 0.33);
    B.show();
    cout << endl << "B * 1.5 = " << B.multiply(1.5);
    
    cout << endl << endl;
    
    Pair* C = new Pair;
    C->read();
    C->show();

    cout << endl << endl << endl;

    Pair mas[3] = { A, B, *C };
    for (int i = 0; i < 3; i++)
    {
        mas[i].show();
        cout << endl;
    }
}
