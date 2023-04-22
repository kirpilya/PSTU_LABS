#include <iostream>
#include "List.h"
#include "Pair.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    List<int> L1 = { 1, 2, 3, 4, 5 };
    L1.push_back(10);
    cout << L1 << endl << endl;

    List<float> L2(5, 0.33);
    L2.pop_back();
    cout << L2 << endl << endl;

    List<double> L3 = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    L3.push_front(9.99);
    cout << L3 << endl << endl;

    List<Pair> L4;

    Pair p1(1, 0.1);
    Pair p2(2, 1.1);
    Pair p3(0, 4.5);

    L4.push_back(p1);
    L4.push_back(p2);
    L4.push_back(p3);

    cout << ' ' << L4;

}
