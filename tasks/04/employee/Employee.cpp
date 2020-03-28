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

/** copy constructor */
Employee::Employee(const Employee& employee) : ID(employee.ID) {
    name = employee.name;
    surname = employee.surname;
    position = employee.position;
    salary = employee.salary;

    hireDate = new MyDate(*hireDate); 
    fireDate = new MyDate(*fireDate); 

    bonus = employee.bonus;
}

Employee::~Employee() {
    delete fireDate;
    delete hireDate;
}

void Employee::print() const
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

/** getters */
int Employee::getId() const {
    return ID;
}

ostream& operator<<(ostream& os, const Employee& employee) {
	cout << "EMPLOYEE: ";
    employee.print();
    return os;
}