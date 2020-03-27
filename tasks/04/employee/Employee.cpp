#include "Employee.h"

#include <iostream>
using std::cout;
using std::endl;

int Employee::count = 0;

Employee::Employee(string name,
                   string surname,
                   string position,
                   int salary,
                   MyDate* hireDate) : ID(++count),
                                      name(name),
                                      surname(surname),
                                      position(position),
                                      salary(salary),
                                      hireDate(hireDate),
                                      fireDate(nullptr),
                                      bonus(false) {
}

Employee::~Employee() {
    delete fireDate;
    delete hireDate;
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
MyDate* Employee::getHireDate() const {
    return hireDate;
}
MyDate* Employee::getFireDate() const {
    return fireDate;
}
bool Employee::hasBonus() const {
    return bonus;
}

/** overloading */
bool Employee::operator==(const Employee& rhs) const {
    return ID == rhs.ID; // just ID, i.e. unique
}
bool Employee::operator!=(const Employee &rhs) const {
    return !(rhs == *this);
}

// FIXME: Q: using friend for direct field access
ostream& operator<<(ostream& os, const Employee& employee) {
    os << "ID: " << employee.getId()
       << " name: " << employee.getName()
       << " surname: " << employee.getSurname()
       << " position: " << employee.getPosition()
       << " salary: " << employee.getSalary()
       << " hireDate: " << *(employee.getHireDate()); // dereferencing!

    if (employee.getFireDate() != nullptr) {
        os << " fireDate: " << *(employee.getFireDate()); // dereferencing!
    }

    os << " bonus: " << employee.hasBonus();
    return os;
}