#pragma once // FIXME: Q: Use in all header in hierarchy?

#include <string>

#include "../../01/06_date/MyDate.h"

using namespace std;

class Employee
{
public:
    // TODO: default
	Employee(string name, string surname, string position, int salary, MyDate hireDate);
    Employee(const Employee& employee); // copy constructor

    virtual ~Employee();

	void print() const;

	/* setters */
    void setBonus(bool bonus);

    /* getters */
    int getId() const;

    /** overloading */
    // TODO overload = ???
    // FIXME virtual overloading???
    bool operator==(const Employee& rhs) const;
    bool operator!=(const Employee& rhs) const;

private:
	const int ID;
	static int count;

	string name;
	string surname;
	string position;
	int salary;
	MyDate* hireDate;
	MyDate* fireDate;
	bool bonus;
};

ostream& operator<<(ostream& os, const Employee& employee);