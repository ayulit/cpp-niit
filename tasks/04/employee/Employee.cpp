#include "Employee.h"

#include <iostream>
using std::cout;
using std::endl;

int Employee::count = 0;

Employee::Employee(string name,
                   string surname,
                   string position,
                   int salary,
                   MyDate hireDate) : ID(++count),
                                      name(name),
                                      surname(surname),
                                      position(position),
                                      salary(salary),
                                      hireDate(new MyDate(hireDate)),
                                      fireDate(nullptr),
                                      bonus(false) {
}

Employee::~Employee() {
    delete fireDate;
    delete hireDate;
}

void Employee::Print() const
{
	cout << "id: " << ID
		 << " name: " << name
		 << " surname: " << surname
		 << " position: " << position
		 << " salary: " << salary
		 << " hireDate: " << *hireDate; // dereferencing!

	if (fireDate != nullptr) {
		cout << " fireDate: " << *fireDate; // dereferencing!
	}

	cout << " bonus: " << bonus;	
}

/** getters */
int Employee::getId() const {
    return ID;
}
const string& Employee::getName() const {
    return name;
}
const string& Employee::getSurname() const {
    return surname;
}
const string& Employee::getPosition() const {
    return position;
}
int Employee::getSalary() const {
    return salary;
}
const MyDate* Employee::getHireDate() const {
    return hireDate;
}
const MyDate* Employee::getFireDate() const {
    return fireDate;
}
bool Employee::hasBonus() const {
    return bonus;
}

/** setters */
void Employee::setBonus(bool bonus) {
	this->bonus = bonus;
}

/** overloading */
bool Employee::operator==(const Employee& rhs) const {
    return ID == rhs.ID; // just ID, i.e. unique
}
bool Employee::operator!=(const Employee &rhs) const {
    return !(rhs == *this);
}

ostream& operator<<(ostream& os, const Employee& employee) {
	cout << "EMPLOYEE: ";
	employee.Print();
    return os;
}