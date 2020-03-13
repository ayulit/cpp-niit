#ifndef CPP_NIIT_MYSTRING_H
#define CPP_NIIT_MYSTRING_H

#include <cstddef> // needed on Mac

class MyString {
public:
    MyString() : str(nullptr) {}
    explicit MyString(const char* cstr); // clion wants explicit
    MyString(const MyString& ref);       // copy constructor
    ~MyString();

    char *const ToString() const;
    size_t Size() const;
    void Insert(const MyString& ref, size_t pos);
    void Insert(const char* cstr, size_t pos);
    long Find(const MyString& ref) const;
    long Find(const char* cstr) const;
    MyString Substr(size_t pos, size_t len) const;
private:
    char* str;
};

#endif //CPP_NIIT_MYSTRING_H
