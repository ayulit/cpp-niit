#ifndef CPP_NIIT_MYSTRING_H
#define CPP_NIIT_MYSTRING_H

#include <cstddef> // needed on Mac

class MyString {
public:
    MyString() : str(nullptr) {}
    explicit MyString(const char* cstr); // clion wants explicit
    MyString(const MyString& ref);       // copy constructor
    ~MyString();

    void Print() const;
    size_t Size() const;
    void Insert(const MyString& ref, size_t pos);
private:
    char* str;
};

#endif //CPP_NIIT_MYSTRING_H
