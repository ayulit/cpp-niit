#include <iostream>
#include "mystring.h"

using std::cout;
using std::endl;

int main()
{
    // Constructor from another c-string
    char* cstr = "abcdef";
    MyString str1(cstr);
    str1.Print();

    // Constructor from string literal
    MyString str2("123");
    str2.Print();

    // TODO: check bounds
    // Insert srt2 at pos #2
    str1.Insert(str2, 2);
    str1.Print();

    return 0;
}