#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    // MAX_SIZE = 30

    try
    {
        List a(40, 0);
    }
    catch (int)
    {
        cout << "Some error 1" << endl;
    }

    try
    {
        List a(30, 0);
        a.push_back(5);

    }
    catch (int)
    {
        cout << "Some error 2" << endl;
    }

    try
    {
        List a;
        a.pop_back();
    }
    catch (int)
    {
        cout << "Some error 3" << endl;
    }

    try
    {
        List a(20, 0);
        a[-2] = 5;
    }
    catch (int)
    {
        cout << "Some error 4" << endl;
    }

    try
    {
        List a(20, 0);
        a[25] = 5;
    }
    catch (int)
    {
        cout << "Some error 5" << endl;
    }

    try
    {
        List a(20, 0);
        List b(20, 1);

        a = a + b;
    }
    catch (int)
    {
        cout << "Some error 6" << endl;
    }

    try
    {
        List a(30, 0);
        a + 5;
    }
    catch (int)
    {
        cout << "Some error 7" << endl;
    }

}
