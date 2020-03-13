#include "mystring.h"
#include <cstring>

#include <iostream>
using std::cout;
using std::endl;

MyString::MyString(const char* cstr) {
    size_t len = strlen(cstr);

    // FIXME: '1' for null-termination?!
    str = new char[len + 1];
    strcpy(str, cstr);
}

MyString::MyString(const MyString &ref) {
    const size_t SIZE = ref.Size();

    str = new char[SIZE + 1];
    // FIXME: WTF?! str is private?! How is it possible to call ref.str?
    strcpy(str, ref.str);
}

MyString::~MyString() {
    delete [] str;
}

char *const MyString::ToString() const {
    return str;
}

size_t MyString::Size() const {
    return strlen(str);
}

void MyString::Insert(const MyString& ref, size_t pos) {
    const size_t SIZE = this->Size() + ref.Size();
    char tmpStr[SIZE + 1]; // 1 for null-character

    // first part from this
    strncpy(tmpStr, str, pos);
    tmpStr[pos] = '\0';

    // concat with inserted
    strcat(tmpStr, ref.str);

    // concat with last part from this
    strcat(tmpStr, str + pos);

    // FIXME ? realloc this->str
    delete [] str; // free memory from str
    str = new char[SIZE + 1];
    strcpy(str, tmpStr);
}

long MyString::Find(const MyString &ref) const {
    return Find(ref.str);
}

long MyString::Find(const char *cstr) const {
    char* pch = strstr(str, cstr);
    if (pch == nullptr) {
        return -1;
    }
    return pch - str;
}






