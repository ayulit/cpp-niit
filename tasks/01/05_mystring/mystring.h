#ifndef CPP_NIIT_MYSTRING_H
#define CPP_NIIT_MYSTRING_H

#define _CRT_SECURE_NO_WARNINGS

#include <cstddef> // needed on Mac
#include <iostream>

class MyString {
public:
    MyString();
    MyString(const char* s);             // clion wants explicit
    MyString(const MyString& ref);       // copy constructor
    ~MyString();

    void Print() const;
    size_t Size() const;
    MyString& Insert(size_t pos, const MyString& ref);
    MyString& Insert(size_t pos, const char* s);
    long Find(const MyString& ref) const;
    long Find(const char* cstr) const;
    MyString Substr(size_t pos, size_t len) const;

    // Overloading
    MyString& operator= (const MyString& right);
    MyString operator+ (const MyString& right) const;
    MyString operator+ (const char* s) const;
    MyString& operator+=(const MyString& right);
    MyString& operator+=(const char* s);

    // get a substring from 'pos' till the end
    MyString operator- (size_t pos) const;

    bool operator== (const MyString& right) const;
    bool operator!= (const MyString& right) const;
    bool operator> (const MyString& right) const;
    bool operator< (const MyString& right) const;

private:
    char* str;
};

std::ostream& operator<<(std::ostream& out, const MyString& ref);
std::istream& operator>>(std::istream& in, MyString& ref);

#endif //CPP_NIIT_MYSTRING_H
