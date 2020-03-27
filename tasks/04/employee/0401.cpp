#include "Employee.h"

#include <iostream>

using namespace std;

int main()
{
	Employee e1("Luke", "Skywalker", "jedi", 1000, new MyDate(2000, 1, 1));
	Employee e2("Han", "Solo", "captain", 2000, new MyDate(1995, 1, 1));

	cout << e1 << endl;
	cout << e2 << endl;

	if(e1 == e2) {
	    cout << "Equals!" << endl;
	} else {
        cout << "e1 is NOT e2" << endl;
	}
    cout << (e1 == e1) << endl;

	return 0;
}