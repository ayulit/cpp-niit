#pragma once

#include <string>

#include "../../01/06_date/MyDate.h"

using namespace std;

class Employee
{
public:
	Employee(string name, string surname, string position, int salary, MyDate hireDate);
	    
    virtual ~Employee();

	void Print() const;

    /** getters */
    int getId() const;
    const string& getName() const;
    const string& getSurname() const;
    const string& getPosition() const;
    int getSalary() const;
    const MyDate *getHireDate() const;
    const MyDate *getFireDate() const;
    bool hasBonus() const;

    /** overloading */
    bool operator==(const Employee& rhs) const;
    bool operator!=(const Employee& rhs) const;
protected:
	void setBonus(bool bonus);
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