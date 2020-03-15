#include "mystring.h"
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <stdexcept>

MyString::MyString() {
    str = new char[1];
    str[0] = '\0';
}

MyString::MyString(const char* s) {
    size_t len = strlen(s);
	    
    str = new char[len + 1];
    strcpy(str, s);
}

MyString::MyString(const MyString &ref) {
    size_t SIZE = ref.Size();

    str = new char[SIZE + 1];    
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

MyString& MyString::Insert(size_t pos, const MyString& ref) {
    return Insert(pos, ref.str);
}

MyString& MyString::Insert(size_t pos, const char *s) {
	if (str == nullptr) {
		// throw exception
		throw std::invalid_argument("Null Pointer Exception!");
	}
	
	size_t size = this->Size() + strlen(s);
	char* tmpStr = new char[size + 1];
	
	// first part from this
	strncpy(tmpStr, str, pos);
	tmpStr[pos] = '\0';	
			
    // concat with inserted
    strcat(tmpStr, s);
	    
	// concat with last part from this
    strcat(tmpStr, str + pos);

	delete[] str; // free memory from str	
	str = tmpStr;

    return *this;
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

MyString MyString::Substr(size_t pos, size_t len) const {
    
	char* substring = new char[len + 1];

    memcpy(substring, &str[pos], len);
    substring[len] = '\0';

	MyString res(substring);
	delete[] substring;

	return res;
}






