#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    List L1(10, 0);
    cout << "L1: " << L1 << endl << endl;

    L1.push_back(99);
    L1.push_front(-99);
    cout << "L1: " << L1 << endl << endl;

    List L2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    cout << L2 << endl << endl;

    List L3;
    cin >> L3;
    cout << endl << "L3: " << L3 << endl << endl;

    cout << "L3[3] = " << L3[3] << endl << endl;

    List L4 = { 1, 1, 1 };
    List L5 = { 2, 2, 2 };
    cout << "{ 1, 1, 1 } + { 2, 2, 2 } = " << L4 + L5 << endl << endl;

    List L6 = { 3, 3, 3 };
    cout << "{ 3, 3, 3 } + 1 = " << L6 + 1 << endl << endl;

    List L7 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (List::iter it = L7.begin(); it != L7.end(); it++)
    {
        cout << *it << " ";
    }

}
