#ifndef CPP_NIIT_MYDATE_H
#define CPP_NIIT_MYDATE_H

#include <ctime>

class MyDate
{
public:
    MyDate();
    explicit MyDate(long sec);
    MyDate(int year, int month, int day);
    MyDate(const MyDate& ref);       // copy constructor
//    ~MyDate(); FIXME Is it needed?

    char* getDate() const;
    void setDate(int year, int month, int day);

    double diff(const MyDate& ref) const;
private:
    struct tm * timeinfo;
};

#endif //CPP_NIIT_MYDATE_H
