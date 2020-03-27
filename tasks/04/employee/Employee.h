#pragma once

#include <string>

//#include "..\\..\\01\\06_date\\MyDate.h" // windows
#include "../../01/06_date/MyDate.h"       // mac

using namespace std;

class Employee
{
public:
//	Employee() : ID(++count), bonus(false) {};
	Employee(string name, string surname, string position, int salary, MyDate* hireDate);

    // FIXME: Q: Must it be virtual?
    virtual ~Employee();

    /** getters */
    int getId() const;
    const string& getName() const;
    const string& getSurname() const;
    const string& getPosition() const;
    int getSalary() const;
    MyDate *getHireDate() const;
    MyDate *getFireDate() const;
    bool hasBonus() const;

    /** overloading */
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