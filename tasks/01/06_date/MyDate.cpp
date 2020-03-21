#include "MyDate.h"

#include <cstdio>

/* sets current time */
MyDate::MyDate() {
    timeinfo = new tm();
    time_t rawtime = 0;
    time(&rawtime); // now
	    
    struct tm* ptr = gmtime(&rawtime);
    timeinfo->tm_year = ptr->tm_year;
    timeinfo->tm_mon = ptr->tm_mon;
    timeinfo->tm_mday = ptr->tm_mday;

	
	    
}

MyDate::MyDate(long sec) {
    timeinfo = new tm();
    time_t rawtime = sec;

    struct tm* ptr = gmtime(&rawtime);
    
    timeinfo->tm_year = ptr->tm_year;
    timeinfo->tm_mon = ptr->tm_mon;
    timeinfo->tm_mday = ptr->tm_mday;

    
}

MyDate::MyDate(int year, int month, int day) {
    timeinfo = new tm();

    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
}

MyDate::MyDate(const MyDate &ref) {
    timeinfo = new tm();

    timeinfo->tm_year = ref.timeinfo->tm_year;
    timeinfo->tm_mon = ref.timeinfo->tm_mon;
    timeinfo->tm_mday = ref.timeinfo->tm_mday;
}

MyDate::~MyDate() {
    delete timeinfo;
}

char* MyDate::getDate() const {
    static char result[11];
    static const char mon_name[][4] = {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    sprintf(result, "%.3s %d %d",
            mon_name[timeinfo->tm_mon],
            timeinfo->tm_mday,
            1900 + timeinfo->tm_year);

    return result;
}

void MyDate::setDate(int year, int month, int day) {
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
}

double MyDate::diff(const MyDate &ref) const {
    time_t thisRawtime = timegm(timeinfo);
    time_t refRawtime = timegm(ref.timeinfo);

    return difftime(thisRawtime, refRawtime);
}

double MyDate::operator-(const MyDate &right) const {
    return this->diff(right);
}

MyDate MyDate::operator-(long sec) const {
    time_t rawtime = timegm(timeinfo) - sec;
    return MyDate(rawtime);
}

MyDate MyDate::operator+(long sec) const {
    time_t rawtime = timegm(timeinfo) + sec;
    return MyDate(rawtime);
}

MyDate& MyDate::operator-=(long sec) {
    time_t rawtime = timegm(timeinfo) - sec;

    struct tm* ptr = gmtime(&rawtime);
    
    timeinfo->tm_year = ptr->tm_year;
    timeinfo->tm_mon = ptr->tm_mon;
    timeinfo->tm_mday = ptr->tm_mday;



    return *this;
}

MyDate& MyDate::operator+=(long sec) {
    time_t rawtime = timegm(timeinfo) + sec;

    struct tm* ptr = gmtime(&rawtime);
    
    timeinfo->tm_year = ptr->tm_year;
    timeinfo->tm_mon = ptr->tm_mon;
    timeinfo->tm_mday = ptr->tm_mday;



    return *this;
}

bool MyDate::operator==(const MyDate &right) const {
    return timegm(timeinfo) == timegm(right.timeinfo);
}

bool MyDate::operator!=(const MyDate &right) const {
    return !(*this == right);;
}

bool MyDate::operator>(const MyDate &right) const {
    return timegm(timeinfo) > timegm(right.timeinfo);
}

bool MyDate::operator<(const MyDate &right) const {
    return timegm(timeinfo) < timegm(right.timeinfo);
}

std::ostream& operator<<(std::ostream& out, const MyDate& ref)
{
    std::cout << ref.getDate();
    return out;
}

std::istream& operator>>(std::istream& in, MyDate& ref)
{
    int year;
    int month;
    int day;
    std::cout << "Enter date..." << std::endl;

    std::cout << "Year: ";
    in >> year;
    std::cout << "Month: ";
    in >> month;
    std::cout << "Day: ";
    in >> day;

    ref.setDate(year, month, day);

    return in;
}

