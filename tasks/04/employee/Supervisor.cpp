#include "Supervisor.h"

Supervisor::Supervisor(string name,
                       string surname,
                       string position,
                       int salary,
                       MyDate hireDate) : Manager(name, surname, position, salary, hireDate)
{
}

ostream& operator<<(ostream& os, const Supervisor& supervisor) {
    os << "SUPERVISOR: ";
    supervisor.print();
    return os;
}