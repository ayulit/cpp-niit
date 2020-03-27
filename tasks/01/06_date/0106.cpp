#include "MyDate.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
    MyDate date1;
    cout << "Test #1   Today: " << date1.getDate() << endl;
    date1.setDate(1961, 4, 12);
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

    cout << "Test #7   Diff Overloaded -: " << date4 - date3 << endl << endl;

    cout << "Test #8   Minus sec: " << date1 - 1 << endl << endl;

    cout << "Test #9   Plus sec: " << date1 + 1 << endl << endl;

//    MyDate date6;
//    cin >> date6;
//    cout << "Test #10   date6: " << date6 << endl << endl;

    MyDate y2k(2000, 1, 1);
    cout << "Test #11   y2k: " << y2k << endl;
    y2k -= 86400;
    cout << "Test #11   y2k-=86400: " << y2k << endl;
    y2k += 86400;
    cout << "Test #11   y2k+=86400: " << y2k << endl;
    y2k += 86400;
    cout << "Test #11   y2k+=86400: " << y2k << endl;

    MyDate one(2001, 05, 10);
    MyDate two(2001, 05, 10);

    if (one == two) {
        cout << "Equal!" << endl;
    }

    if (one != y2k) {
        cout << "NOT Equal!" << endl;
    }

    if (y2k < one) {
        cout << y2k << " < " << one <<  endl;
    }

    if (one > date1) {
        cout << one << " > " << date1 <<  endl;
    }

    MyDate date7(2014, 06, 01);
    MyDate date8 = date7; // Implicit copy constructor in action.
    cout << "\nTest #12  date7: " << date7 << endl;
    cout << "Test #12  date8: " << date8 << endl;

    date8 = y2k; // will be just second ref if assignment operator isn't overloaded!
    cout << "\nTest #13  date8: " << date8 << endl;
    y2k.setDate(1980,1,1);
    cout << "Test #13  y2k: " << y2k << endl;
    cout << "Test #13  date8: " << date8 << endl;

    return 0;
}