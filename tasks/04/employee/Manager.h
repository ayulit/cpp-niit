#include "Employee.h"
#include <vector>

struct Task
{
	string taskName;
	Employee* resource; // do not delete, i.e. memory allocated not here!
	MyDate* deadline;
	MyDate* finish;
	bool bonus;
	
	Task(string taskName, Employee* resource, MyDate deadline);
	// TODO: copy constructor
	~Task();
};

struct Project 
{	
	string projectName;
	vector<Task> tasks;
	bool bonus = false;
};

class Manager : public Employee
{
public:
	Manager(string name, string surname, string position, int salary, MyDate hireDate);	
		
	void addProject(Project project);

private:	
	vector<Project> projects;
};

ostream& operator<<(ostream& os, const Manager& manager);