#include "Manager.h"

Manager::Manager(string name,
				 string surname,
				 string position,
				 int salary,
				 MyDate hireDate) : Employee(name, surname, position, salary, hireDate)
{	
}

Task::Task(string taskName,
	       Employee* resource,
	       MyDate deadline) : taskName(taskName),
						      resource(resource),
						      deadline(new MyDate(deadline)),
						      finish(nullptr),
						      bonus(false)
{
}

Task::~Task() {
	delete deadline;
	delete finish;
}

void Manager::addProject(Project project) {
	projects.push_back(project);
}

ostream& operator<<(ostream& os, const Manager& manager) {
	os << "MANAGER: ";
	manager.Print();
//	os << static_cast<const Employee&>(manager);
	return os;
}