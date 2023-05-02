#include <iostream>
#include "Person.h"
#include "Employee.h"
#include "Vector.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    Vector vec(4);

    Person Oleg;
    cin >> Oleg;
    cout << endl;

    Employee Alex;
    cin >> Alex;
    cout << endl;

    Person Ivan;
    cin >> Ivan;
    cout << endl;

    vec.add(&Oleg);
    vec.add(&Alex);
    vec.add(&Ivan);

    cout << vec;
}
