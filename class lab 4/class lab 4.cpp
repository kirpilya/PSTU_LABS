#include <iostream>
#include <limits>
#include "Person.h"
#include "Employee.h"

void PrintPerson(Person& value)
{
    cout << value.get_name() << " " << value.get_age() << " years";
}

Person& FireEmployee(Employee& emp)
{
    return emp;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    cout << "Создание объекта Ivan класса Person\n";
    Person Ivan;
    cin >> Ivan;
    cout << "\nВывод объекта Ivan класса Person\n";
    cout << Ivan << endl << endl;

    cout << "Создание объекта WorkerIvan класса Employee\n";
    Employee WorkerIvan;
    cin >> WorkerIvan;
    cout << "\nВывод объекта WorkerIvan класса Employee\n";
    cout << WorkerIvan << endl << endl;

    cout << "Зарплата WorkerIvan.CountSalary()\nПроцент премии: ";
    int per;
    cin >> per;
    cout << "Зарплата: " << WorkerIvan.CountSalary(per) << endl << endl;

    cout << "Изменение объекта WorkerIvan класса Employee\n";
    WorkerIvan.set_name("Ivan Petrov");
    WorkerIvan.set_age(20);
    WorkerIvan.set_role("Designer");
    WorkerIvan.set_sal(50000);
    cout << WorkerIvan << endl << endl;

    cout << "PrintPerson(Ivan)\n";
    PrintPerson(Ivan);
    cout << endl << endl << "PrintPerson(WorkerIvan)\n";
    PrintPerson(WorkerIvan);

    cout << "\n\nIvan = FireEmployee(WorkerIvan)\n\n";
    Ivan = FireEmployee(WorkerIvan);

    cout << Ivan << "\n\n" << WorkerIvan;

}
