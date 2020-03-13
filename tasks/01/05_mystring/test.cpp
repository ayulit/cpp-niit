#include <iostream>
#include "mystring.h"

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

    // TODO: check bounds
    // Insert srt2 at pos #2
    str1.Insert(str2, 2);
    cout << "str1 = " << str1.ToString() << endl;

    // Copy constructor
    MyString str3(str1);
    cout << "str3 = " << str3.ToString() << endl;

    return 0;
}