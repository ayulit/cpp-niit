#pragma once
#ifndef CPP_NIIT_MYDATE_H
#define CPP_NIIT_MYDATE_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>

// #define timegm _mkgmtime // windows

class MyDate
{
public:
    MyDate();
    explicit MyDate(long sec);
    MyDate(int year, int month, int day);
    MyDate(const MyDate& ref);       // copy constructor
    ~MyDate(); // FIXME Is it needed?

    char* getDate() const;
    void setDate(int year, int month, int day);

    double diff(const MyDate& ref) const;

    // OVERLOADING
    MyDate& operator= (const MyDate& right);
    double operator- (const MyDate& right) const;
    MyDate operator- (long sec) const;
    MyDate operator+ (long sec) const;
    MyDate& operator-=(long sec);
    MyDate& operator+=(long sec);

    bool operator== (const MyDate& right) const;
    bool operator!= (const MyDate& right) const;
    bool operator> (const MyDate& right) const;
    bool operator< (const MyDate& right) const;
private:
    struct tm * timeinfo;
};

std::ostream& operator<<(std::ostream& out, const MyDate& ref);
std::istream& operator>>(std::istream& in, MyDate& ref);

#endif //CPP_NIIT_MYDATE_H
