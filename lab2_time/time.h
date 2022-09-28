#ifndef TIME_H
#define TIME_H
#include <string>

struct Time
{
    int hour;
    int minute;
    int second;
};
bool is_valid(Time const& time);
std::string to_string(Time time, int const& time_format); 
//set time_format to 12 for 12 hour clock format or 24 for 24 hour clock format
bool is_am(Time const& time);
Time operator+(Time time, int seconds);
Time operator-(Time time, int seconds);
Time& operator++(Time& time);
Time operator++(Time& time, int);
Time& operator--(Time& time);
Time operator--(Time& time, int);
bool operator==(Time const& time1, Time const& time2);
bool operator!=(Time const& time1, Time const& time2);
bool operator<(Time const& time1, Time const& time2);
bool operator<=(Time const& time1, Time const& time2);
bool operator>(Time const& time1, Time const& time2);
bool operator>=(Time const& time1, Time const& time2);
std::ostream& operator<<(std::ostream& os, Time const& time);
std::istream& operator>>(std::istream& is, Time& time);
#endif //TIME_H
