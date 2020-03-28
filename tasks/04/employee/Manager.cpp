#include "Manager.h"

Manager::Manager(string name,
				 string surname,
				 string position,
				 int salary,
				 MyDate hireDate) : Employee(name, surname, position, salary, hireDate)
{	
}

Subordinate::Subordinate(string taskName,
                         Employee* resource,
                         MyDate deadline) : taskName(taskName),
						      resource(resource),
						      deadline(new MyDate(deadline)),
						      finish(nullptr)
{

}

/** copy constructor */
Subordinate::Subordinate(const Subordinate& subordinate) {
    taskName = subordinate.taskName;
    resource = subordinate.resource; // FIXME: double reference? yes! It needed here...

    deadline = new MyDate(*(subordinate.deadline));

    // FIXME
    if (subordinate.finish == nullptr) {
        finish = nullptr;
    } else {
        finish = new MyDate(*(subordinate.finish));
    }
}

Subordinate::~Subordinate() {
	delete deadline;
	delete finish;
}

void Subordinate::setFinish(const MyDate& mdFinish) {
    finish = new MyDate(mdFinish);
    if (*finish < (*deadline)) {
        resource->setBonus(true);
    } else {
        // cancel bonus!
        resource->setBonus(false);
    }
}

bool Subordinate::isDeadlineExpired() {
    return *finish < (*deadline);
}

void Manager::addSubordinate(Subordinate* ptSubordinate) {
    subordinates.push_back(ptSubordinate);
}

Subordinate* Manager::getSubordinateById(int id) {
    for(vector<Subordinate*>::iterator it = subordinates.begin(); it != subordinates.end(); ++it) {
        if((*it)->resource->getId() == id) {
            return *it;
        }
    }
    return nullptr;
}

void Manager::checkSubordinates() {
    for(vector<Subordinate*>::iterator itSub = subordinates.begin(); itSub != subordinates.end(); ++itSub) {
        if((*itSub)->isDeadlineExpired()) {
            return;
        }
    }
    setBonus(true);
}

ostream& operator<<(ostream& os, const Manager& manager) {
	os << "MANAGER: ";
    manager.print();
//	os << static_cast<const Employee&>(manager);
	return os;
}