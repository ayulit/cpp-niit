#include "Employee.h"

int Employee::count = 0;

Employee::Employee(string name,
				   string surname, 
				   string position, 
				   int salalry,
				   MyDate hireDate) : ID(++count) {

	this->name = name;
	this->surname = surname;
	this->position = position;
	this->salalry = salalry;
	this->hireDate = hireDate;

	this->fireDate = MyDate(3000, 1, 1); // alternative: we can work be prts and nullptr
	this->bonus = false;
}

std::ostream& operator<<(std::ostream& out, const Employee& ref)
{

//	cout << "Employee{" + ref.name + " " + ref.surname + "}";

	cout << "Employee";

	return out;
}