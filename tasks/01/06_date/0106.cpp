#include "MyDate.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {
    MyDate date1;
    cout << "Test #1   Today: " << date1.getDate() << endl;
    date1.setDate(1961, 04, 12);
    cout << "Test #1   date1= " << date1.getDate() << endl << endl;

    MyDate date2(1);
    cout << "Test #2    " << date2.getDate() << endl << endl;

    MyDate date3(1970, 1, 1);
    cout << "Test #3    " << date3.getDate() << endl << endl;

    MyDate date4(86400); // day seconds
    cout << "Test #4    date4= " << date4.getDate() << endl;
    cout << "Test #4    date3= " << date3.getDate() << endl;
    cout << "Test #4    date1= " << date1.getDate() << endl << endl;

    cout << "Test #5    Diff: " << date4.diff(date3) << endl << endl;

    // Copy constructor
    MyDate date5(date1);
    cout << "Test #6   Copy constructor: " << date5.getDate() << endl << endl;

    return 0;
}