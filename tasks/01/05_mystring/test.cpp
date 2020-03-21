#include "mystring.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>

int main()
{
    // Constructor from another c-string
    char* cstr = "abcdef";
    MyString str1(cstr);
    cout << "str1 = " << str1 << endl;

    // Constructor from string literal
    MyString str2("123");
    cout << "str2 = " << str2 << endl;
	    
    // Insert srt2 at pos #2
    cout << "str1 = " << str1.Insert(2, str2) << endl;

    MyString logic("logic");
    cout << "logic -> " << logic.Insert(4, "sti") << endl;

    // Copy constructor
    MyString str3(str1);
    cout << "str3 = " << str3 << endl;

    // Find SUCCESS
    cout << "Find str2 in str3: " << str3.Find(str2) << endl;

    // Find FAILED
    MyString str4("blah");
    cout << "Find str4 in str3: " << str3.Find(str4) << endl;

    // Find literal SUCCESS
    cout << "Find 'cde' in str3: " << str3.Find("cde") << endl;

    // Find literal FAILED
    cout << "Find 'blah' in str3: " << str3.Find("blah") << endl;

    // Substring
    MyString str5("Hello, world!");
    cout << "Substring: " << str5.Substr(7, 5) << endl; // world
	    
    MyString str6;
	MyString str7("str7"); // copy constructor in action.
    str6 = str7; // will be crash if assignment operator isn't overloaded!
	
	MyString str8 = str7; // this is ok! Copy constructor in action.
	cout << "str8 ->  " << str8.Insert(0, "str8=") << endl;
	
	try {
		cout << "str6 ->  " << str6.Insert(0, "str6=") << endl;
	}
	catch (const std::exception& e)  {
		cout << e.what() << endl;
	}
	
	MyString str9 = "str";
	cout << "str9 ->  " << str9.Insert(3, "9") << endl;

	MyString hello = "Hello, ";
	MyString world = "world!";
    cout << "Concatenation MyString + MyString ->  " << (hello + world) << endl;

    MyString merry = "Merry ";
    char* xmas = "Xmas!";
    cout << "Concatenation MyString + char* ->  " << (merry + xmas) << endl;

//    MyString inputString;
//    cout << "Please, input a string: " << endl;
//    cin >> inputString;
//    cout << "You've just entered: " << inputString << endl;

    MyString one = "wombat";
    MyString two = "wombat";

    if (one == two) {
        cout << "Equal!" << endl;
    }

    if (!(hello == world)) {
        cout << "NOT Equal!" << endl;
    }

    if (hello != world) {
        cout << "NOT Equal!" << endl;
    }

    MyString aaa= "aaa";
    MyString aab= "aab";

    if (aaa < aab) {
        cout << "aaa < aab" << endl;
    }

    if (aab > aaa) {
        cout << "aab > aaa" << endl;
    }

    aab += aaa;
    cout << aab << endl; // aabaaa


    aab += merry;
    cout << aab << endl; // aabaaaMerry

    aab += "1";
    cout << aab << endl;

    MyString macbook = "MacBook";
    cout << macbook-3 << endl;

    return 0;
}