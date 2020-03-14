#include "mystring.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    // Constructor from another c-string
    char* cstr = "abcdef";
    MyString str1(cstr);
    cout << "str1 = " << str1.ToString() << endl;

    // Constructor from string literal
    MyString str2("123");
    cout << "str2 = " << str2.ToString() << endl;
	    
    // Insert srt2 at pos #2
    cout << "str1 = " << str1.Insert(2, str2).ToString() << endl;

    MyString logic("logic");
    cout << "logic -> " << logic.Insert(4, "sti").ToString() << endl;

    // Copy constructor
    MyString str3(str1);
    cout << "str3 = " << str3.ToString() << endl;

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
    cout << "Substring: " << str5.Substr(7, 5).ToString() << endl; // world
	    
    MyString str6;
	MyString str7("str7");
    //str6 = str7; // crash
	try {
		cout << "str6 ->  " << str6.Insert(0, "str6=").ToString() << endl;
	}
	catch (const std::exception& e)  {
		cout << e.what() << endl;
	}
	
	MyString str8 = "str";
	cout << "str8 ->  " << str8.Insert(3, "8").ToString() << endl;

    return 0;
}