#include "Employee.h"

#include <iostream>

using namespace std;

int main()
{
	Employee e1("John", "Doe", "Designer", 1000, {2000, 1, 1});
	
	cout << e1 << endl;
	
	return 0;
}