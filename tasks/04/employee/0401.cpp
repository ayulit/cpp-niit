#include "Employee.h"
#include "Manager.h"
#include "Supervisor.h"

#include <iostream>

using namespace std;

int main()
{	
	Employee bobbaFet("Bobba", "Fet", "hunter", 1000, MyDate(1980, 5, 17));
	Employee moffTarkin("Moff", "Tarkin", "admiral", 1000, MyDate(1977, 5, 25));
	cout << bobbaFet << endl;
	cout << moffTarkin << endl;
	if(bobbaFet == moffTarkin) {
	    cout << "Equals!" << endl;
	} else {
        cout << "bobbaFet is NOT moffTarkin" << endl;
	}
    cout << (bobbaFet == bobbaFet) << endl;

	Manager darthVader("Darth", "Vader", "lord", 3000, MyDate(1977, 5, 25));
	cout << darthVader << endl;

	Subordinate captureSolo ("Capture Han Solo", &bobbaFet, MyDate(2011, 1, 1));
	Subordinate finishDeathStar ("Finish Death Star", &moffTarkin, MyDate(2011, 1, 1));

    darthVader.addSubordinate(&captureSolo);
    darthVader.addSubordinate(&finishDeathStar);

    Employee grievous("General", "Grievous", "general", 1000, MyDate(2005, 5, 19));
    Employee viceroy("Nute", "Gunray", "viceroy", 1000, MyDate(1999, 5, 16));
    cout << grievous << endl;
    cout << viceroy << endl;

    Manager dooku("Count", "Dooku", "count", 3000, MyDate(2002, 5, 12));
    cout << dooku << endl;
    Subordinate killObiWan ("Kill Obi-Wan Kenobi)", &grievous, MyDate(2011, 1, 1));
    Subordinate takeNaboo ("Take over the Naboo", &viceroy, MyDate(2011, 1, 1));

    dooku.addSubordinate(&killObiWan);
    dooku.addSubordinate(&takeNaboo);

    Supervisor emperor("Emperor", "Palpatin", "emperor", 5000, MyDate(1977, 5, 25));
    cout << emperor << endl;
    Subordinate crushRebels ("Crush the Rebellion", &darthVader, MyDate(2011, 1, 1));
    Subordinate destroyRepublic ("Defeat the Galactic Republic", &dooku, MyDate(2011, 1, 1));

    emperor.addSubordinate(&crushRebels);
    emperor.addSubordinate(&destroyRepublic);

    /* Check if job finished in time */

    darthVader.getSubordinateById(1)->setFinish(MyDate(2010, 1, 1));
    darthVader.getSubordinateById(2)->setFinish(MyDate(2010, 1, 1));
    darthVader.checkSubordinates();

    dooku.getSubordinateById(4)->setFinish(MyDate(2020, 1, 1));
    dooku.getSubordinateById(5)->setFinish(MyDate(2020, 1, 1));
    dooku.checkSubordinates();

    emperor.getSubordinateById(3)->setFinish(MyDate(2010, 1, 1));
    emperor.getSubordinateById(6)->setFinish(MyDate(2020, 1, 1));
    emperor.checkSubordinates();

    cout << "\nVIEW AGAIN\n\n";
    cout << bobbaFet << endl;
    cout << moffTarkin << endl;
    cout << darthVader << endl;
    cout << grievous << endl;
    cout << viceroy << endl;
    cout << dooku << endl;
    cout << emperor << endl;

	return 0;
}