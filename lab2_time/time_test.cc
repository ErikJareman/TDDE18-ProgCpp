#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "time.h"
using namespace std;
#include <sstream>

Time test_time{1,1,1};

TEST_CASE("testing is_valid")
{
    CHECK(is_valid(test_time));
    test_time={60,60,60};
    CHECK_FALSE(is_valid(test_time));
}

TEST_CASE("testing to_string")
{
    test_time={1,1,1};
    CHECK(to_string(test_time, 24) == "01:01:01");
    CHECK(to_string(test_time, 12) == "01:01:01 am");
    test_time={13,12,1};
    CHECK(to_string(test_time, 24) == "13:12:01");
    CHECK(to_string(test_time, 12) == "01:12:01 pm");
}

TEST_CASE("testing is_am")
{
    CHECK_FALSE(is_am(test_time));
    test_time={10,10,10};
    CHECK(is_am(test_time));
}

TEST_CASE("testing + operator")
{
    test_time={0,0,0};
    CHECK(to_string((test_time + 3600),24) == "01:00:00");
    CHECK(to_string((test_time + 60),24) == "00:01:00");
    CHECK(to_string((test_time + 59),24) == "00:00:59");

    CHECK(to_string((test_time + 5000),24) == "01:23:20"); //simple addition
    CHECK(to_string((test_time + 100000),24) == "03:46:40"); //midnight rollover
    CHECK(to_string(test_time, 24) == "00:00:00");
}

TEST_CASE("testing - operator")
{
    test_time={0,0,0};
    CHECK(to_string((test_time - 3600),24) == "23:00:00");
    CHECK(to_string((test_time - 60),24) == "23:59:00");
    CHECK(to_string((test_time - 59),24) == "23:59:01");

    CHECK(to_string((test_time - 1),24) == "23:59:59"); //simple subtraction
    CHECK(to_string((test_time - 100000),24) == "20:13:20"); //midnight rollover
    CHECK(to_string(test_time, 24) == "00:00:00");
}

TEST_CASE("testing ++ and -- operator")
{
    CHECK(to_string(++test_time, 24) == "00:00:01");
    CHECK(to_string(test_time--, 24) == "00:00:01");
    CHECK(to_string(test_time++, 24) == "00:00:00");
    CHECK(to_string(test_time, 24) == "00:00:01");
    test_time++;
    CHECK(to_string(test_time, 24) == "00:00:02");
    --test_time;
    CHECK(to_string(test_time, 24) == "00:00:01");
    test_time--;
    CHECK(to_string(test_time, 24) == "00:00:00");
    test_time--;
    CHECK(to_string(test_time, 24) == "23:59:59");
    CHECK(to_string(++test_time, 24) == "00:00:00");
}

TEST_CASE("testing comparison operators")
{
    Time test_time_2{1,1,1};
    CHECK_FALSE(test_time == test_time_2);
    CHECK(test_time != test_time_2);
    CHECK(test_time == test_time);
    CHECK_FALSE(test_time_2 != test_time_2);
    CHECK_FALSE(test_time > test_time_2);
    CHECK_FALSE(test_time >= test_time_2);
    CHECK(test_time < test_time_2);
    CHECK(test_time <= test_time_2);
    CHECK(test_time <= test_time);
    CHECK(test_time >= test_time);
}

TEST_CASE("testing io operators")
{
    istringstream iss{"01:01:11"};
    iss >> test_time;
    CHECK_FALSE(iss.fail());
    CHECK(to_string(test_time, 24) == "01:01:11");

    istringstream iss2{"30:01:11"};
    iss2 >> test_time;
    CHECK(iss2.fail());
    CHECK(to_string(test_time, 24) == "01:01:11");

    ostringstream oss {};
    test_time={12, 12, 45};
    oss << test_time;
    CHECK(oss.str() == "12:12:45");
}