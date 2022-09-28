#include "time.h"
#include <iostream>
using namespace std;

bool is_valid(Time const& time)
{
    return(time.hour >= 0 && time.hour <= 23 && time.minute >= 0 && 
        time.minute <= 59 && time.second >= 0 && time.second <= 59);
}

string to_string(Time time, int const& time_format)
{
    string tmp{"00:00:00"};
    if (time_format != 12 && time_format != 24)
    {
        cerr << "Invalid time format";
        return "";
    }else {
        if (time_format == 12)
        {
            if (time.hour >= 12){
                tmp.append(" pm");
                time.hour -= 12;
            }
            else
            {
                tmp.append(" am");
            }
        }
        if (time.hour > 9) {
            tmp.replace(0, 2, to_string(time.hour));
        }
        else{
            tmp.replace(1, 1, to_string(time.hour));
        }

        if (time.minute > 9) {
            tmp.replace(3, 2, to_string(time.minute));
        }
        else{
            tmp.replace(4, 1, to_string(time.minute));
        }

        if (time.second > 9) {
            tmp.replace(6, 2, to_string(time.second));
        }
        else{
            tmp.replace(7, 1, to_string(time.second));
        }
        return tmp;
    }
}

bool is_am(Time const& time)
{
    return time.hour < 12;
}

Time operator+ (Time time, int seconds)
{
    while (seconds >= 3600){
        time.hour++;
        seconds -= 3600;
    }
    while (seconds >= 60){
        time.minute++;
        seconds -= 60;
    }
    time.second += seconds;
    if (time.second > 59)
    {
        time.minute += 1;
        time.second -= 60;
    }
    if (time.minute > 59)
    {
        time.hour += 1;
        time.minute -= 60;
    }
    time.hour = time.hour % 24;
    return time;
}

Time operator- (Time time, int seconds)
{
    while (seconds >= 3600){
        time.hour--;
        seconds -= 3600;
    }
    while (seconds >= 60){
        time.minute--;
        seconds -= 60;
    }
    time.second -= seconds;
    while (time.second < 0)
    {
        time.minute -= 1;
        time.second += 60;
    }
    while (time.minute < 0)
    {
        time.hour -= 1;
        time.minute += 60;
    }
    while (time.hour < 0)
    {
    time.hour += 24;
    }
    return time;
}

Time& operator++(Time& time)
{
    time = time + 1;
    return time;
}

Time operator++(Time& time, int)
{
    Time tmp{time};
    ++time;
    return tmp;
}

Time& operator--(Time& time)
{
    time = time - 1;
    return time;
}

Time operator--(Time& time, int)
{
    Time tmp{time};
    --time;
    return tmp;
}

bool operator==(Time const& time1, Time const& time2)
{
    return time1.hour == time2.hour && time1.minute == 
        time2.minute && time1.second == time2.second;
}

bool operator!=(Time const& time1, Time const& time2)
{
    return !(time1==time2);
}

bool operator<(Time const& time1, Time const& time2)
{
    if (time1.hour < time2.hour){
        return true;
    }else if (time1.hour > time2.hour){
        return false;
    }else if (time1.minute < time2.minute){
        return true;
    }else if (time1.minute > time2.minute){
        return false;
    }else if (time1.second < time2.second){
        return true;
    }else {
        return false;
    }      
}

bool operator<=(Time const& time1, Time const& time2)
{
    return (time1 < time2 || time1 == time2);
}

bool operator>(Time const& time1, Time const& time2){
    return !(time1 <= time2); 
}

bool operator>=(Time const& time1, Time const& time2){
    return !(time1 < time2);
}

ostream& operator<<(ostream& os, Time const& time)
{
    os << to_string(time, 24);
    return os;
}

istream& operator>>(istream& is, Time& time)
{
    int hour;
    int minute;
    int second;
    is >> hour;
    is.ignore(1);
    is >> minute;
    is.ignore(1);
    is >> second;
    Time validate_time{hour, minute, second};
    if(is_valid(validate_time)){
        time.hour = hour;
        time.minute = minute;
        time.second = second;
    } else {
        is.setstate(ios_base::failbit);
    }
    return is;
}