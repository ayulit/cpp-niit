#pragma once
#include "Manager.h"

#ifndef CPP_NIIT_SUPERVISOR_H
#define CPP_NIIT_SUPERVISOR_H


class Supervisor : public Manager
{
public:
    Supervisor(string name, string surname, string position, int salary, MyDate hireDate);
    // FIXME copy constructor ???
};

ostream& operator<<(ostream& os, const Supervisor& supervisor);

#endif //CPP_NIIT_SUPERVISOR_H
