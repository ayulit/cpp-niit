#pragma once
#include "Employee.h"
#include <vector>

struct Subordinate
{
	string taskName;
	Employee* resource; // do not delete, i.e. memory allocated not here!
	MyDate* deadline;
	MyDate* finish;

	Subordinate(string taskName, Employee* resource, MyDate deadline);
    Subordinate(const Subordinate& subordinate); // copy constructor
	~Subordinate();

    void setFinish(const MyDate& finish);

    bool isDeadlineExpired();
};

class Manager : public Employee
{
public:
	Manager(string name, string surname, string position, int salary, MyDate hireDate);
    // FIXME copy constructor ???

	void addSubordinate(Subordinate* subordinate);

	// FIXME maybe by ref?
	Subordinate* getSubordinateById(int id);

    void checkSubordinates();

    /** overloading */
    // TODO: overload =, etc.?
private:	
	vector<Subordinate*> subordinates;
};

ostream& operator<<(ostream& os, const Manager& manager);