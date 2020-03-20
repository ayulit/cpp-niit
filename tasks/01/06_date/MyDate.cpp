#include "MyDate.h"

#include <cstdio>

/* sets current time */
MyDate::MyDate() {
    timeinfo = new tm();
    time_t rawtime = 0;
    time(&rawtime); // now

    // FIXME Am I right with struct copy?
    struct tm* ptr = gmtime(&rawtime);
    timeinfo->tm_year = ptr->tm_year;
    timeinfo->tm_mon = ptr->tm_mon;
    timeinfo->tm_mday = ptr->tm_mday;
}

MyDate::MyDate(long sec) {
    timeinfo = new tm();
    time_t rawtime = sec;

    struct tm* ptr = gmtime(&rawtime);
    // FIXME Am I right with struct copy?
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
    time_t thisRawtime = mktime(timeinfo);
    time_t refRawtime = mktime(ref.timeinfo);

    return difftime(thisRawtime, refRawtime);
}


