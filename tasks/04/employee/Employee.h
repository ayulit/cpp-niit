#pragma once

#include <string>

#include "..\\..\\01\\06_date\\MyDate.h"

using namespace std;

class Employee
{
public:
//	Employee() : ID(++count), bonus(false) {};

	Employee(string name,
		     string surname, 
			 string position, 
			 int salalry,
			 MyDate hireDate);
private:
	const int ID;
	
	static int count;

	string name;
	string surname;
	string position;
	int salalry;
	MyDate hireDate; // can be ptr
	MyDate fireDate; // can be ptr
	bool bonus;
};



std::ostream& operator<<(std::ostream& out, const Employee& ref);