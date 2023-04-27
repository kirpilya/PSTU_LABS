#include <iostream>
#include "List.h"
#include "Error.h"

using namespace std;

int main()
{
    // MAX_SIZE = 30

    try
    {
        List a(40, 0);
    }
    catch (Error& err)
    {
        cout << err.what() << endl;
    }

    try
    {
        List a(30, 0);
        a.push_back(5);

    }
    catch (Error& err)
    {
        cout << err.what() << endl;
    }

    try
    {
        List a;
        a.pop_back();
    }
    catch (Error& err)
    {
        cout << err.what() << endl;
    }

    try
    {
        List a(20, 0);
        a[-2] = 5;
    }
    catch (Error& err)
    {
        cout << err.what() << endl;
    }

    try
    {
        List a(20, 0);
        a[25] = 5;
    }
    catch (Error& err)
    {
        cout << err.what() << endl;
    }

    try
    {
        List a(20, 0);
        List b(20, 1);

        a = a + b;
    }
    catch (Error& err)
    {
        cout << err.what() << endl;
    }

    try
    {
        List a(30, 0);
        a + 5;
    }
    catch (Error& err)
    {
        cout << err.what() << endl;
    }
}
