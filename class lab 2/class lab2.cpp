#include <iostream>
#include "Abitur.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    Abitur A;
    cout << "Конструктор без параметров\n";
    A.show();
    cout << endl << endl;

    Abitur B("Иванов Сергей Алексеевич", "РИС 22 1б", 250);
    cout << "Конструктор с параметрами\n";
    B.show();
    cout << endl << endl;

    Abitur C = B;
    cout << "Конструктор копирования\n";
    C.show();
    cout << "\n\n\n\n\n\n";

    C.set_spec("ИВТ 22 1б");
    C.set_ege(249);
    C.show();
    cout << endl << endl;
}
