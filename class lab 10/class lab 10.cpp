#include <iostream>
#include "Pair.h"
#include "functions.h"

using namespace std;

int main()
{
	const char* PATH = "file.txt";

	// create file
	make_file(PATH);
	cout << endl << endl;
	print_file(PATH);

	cout << "\n\n";
	
	// del object with given value
	cout << "del object with given value\n";
	Pair p1;
	cin >> p1;
	cout << endl;
	del_by_data_file(PATH, p1);
	print_file(PATH);

	cout << "\n\n";

	//decrease object with given value
	cout << "decrease object with given value\n";
	Pair p2; int L;
	cin >> p2 >> L;
	cout << endl;
	change_file_by_data(PATH, p2, L);
	print_file(PATH);

	cout << "\n\n";

	//add objects after one with given value
	cout << "add objects after one with given value\n";
	Pair p3; int K;
	cin >> p2 >> K;
	cout << endl;
	add_after_file(PATH, p2, K);
	print_file(PATH);
}
