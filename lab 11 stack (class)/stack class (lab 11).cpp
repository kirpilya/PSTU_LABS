#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    Stack st1(5, 1);
    st1.print();

    cout << endl << endl;

    st1.push(10);
    st1.push(20);
    st1.print();

    cout << endl << endl;

    st1.pop();
    st1.print();

    cout << endl << endl;

    st1.insert(3, 999);
    st1.print();

    cout << endl << endl;

    st1.erase(999);
    st1.print();

    cout << endl << endl;
}
