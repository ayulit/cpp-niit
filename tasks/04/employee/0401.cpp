#include "Employee.h"
#include "Manager.h"

#include <iostream>

using namespace std;

int main()
{	
	Employee e1("Bobba", "Fet", "hunter", 1000,  MyDate(2000, 1, 1));
	Employee e2("Moff", "Tarkin", "admiral", 2000, MyDate(1995, 1, 1));

	cout << e1 << endl;
	cout << e2 << endl;

	if(e1 == e2) {
	    cout << "Equals!" << endl;
	} else {
        cout << "e1 is NOT e2" << endl;
	}
    cout << (e1 == e1) << endl;

	Manager m1("Darth", "Vader", "lord", 3000, MyDate(1990, 1, 1));
	cout << m1 << endl;

	Task t1 ("Capture Han Solo", &e1, MyDate(2000, 1, 1));
	Task t2 ( "Finish Death star", &e2, MyDate(2000, 1, 1));
		
	Project p1;
	p1.projectName = "123";
	p1.tasks.push_back(t1);
	p1.tasks.push_back(t2);

	//delete t1;

	return 0;
}