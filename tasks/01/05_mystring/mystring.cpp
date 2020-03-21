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

void MyString::Print() const {
    std::cout << str;
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

MyString& MyString::operator=(const MyString &right) {
    if (this != &right) {
        delete[] str;
        str = new char[right.Size() + 1];
        strcpy(str, right.str);
    }
    return *this;
}

// strings concatenation
MyString MyString::operator+(const MyString &right) const {
    return operator+(right.str);
}

MyString MyString::operator+(const char *s) const {
    size_t size = this->Size() + strlen(s);
    char* newStr = new char[size + 1];

	strcpy(newStr, str); // before strcat!!!
    strcat(newStr, s);

    MyString res(newStr);
    delete[] newStr;

    return res;
}

MyString& MyString::operator+=(const MyString& right) {
    return operator+=(right.str);
}

MyString& MyString::operator+=(const char *s) {
    size_t size = this->Size() + strlen(s);
    char* newStr = new char[size + 1];

	strcpy(newStr, str); // before strcat!!!    
    strcat(newStr, s);

    delete[] str; // free memory from str
    str = newStr;

    return *this;
}

bool MyString::operator==(const MyString &right) const {
    if (Size() != right.Size() || strcmp(str, right.str) != 0) {
        return false;
    }
    return true;
}

bool MyString::operator!=(const MyString &right) const {
    return !(*this == right);
}

bool MyString::operator>(const MyString &right) const {
    return strcmp(str, right.str) > 0;
}

bool MyString::operator<(const MyString &right) const {
    return strcmp(str, right.str) < 0;
}

MyString MyString::operator-(size_t pos) const {
    size_t len = Size() - pos;
    MyString res = this->Substr(pos, len);
    return res;
}


std::ostream& operator<<(std::ostream& out, const MyString& ref)
{
    ref.Print();
    return out;
}

std::istream& operator>>(std::istream& in, MyString& ref)
{
    size_t max = 80;
    char* inStr = new char[max];

    in.get(inStr, max);
    ref = inStr;

    delete[] inStr;

    return in;
}





