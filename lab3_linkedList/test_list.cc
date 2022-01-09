// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Code:
// https://github.com/philsquared/Catch.git
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.

// This define lets Catch create the main test program
// (Must be in only one place!)
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <utility>
#include <iostream>

#include "aList.h"

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" ) {
    aList l{};
    REQUIRE( l.isEmpty() == true );
}

TEST_CASE( "Insert/Remove/RemoveAt/GetAt" ) {
    aList l;
    l.insert(3);
    l.insert(1);
    l.insert(2);
    REQUIRE( l.getAt(3) == 3 );

    l.remove(1);
    l.removeAt(1);
    REQUIRE( l.getAt(1) == 3 );
    l.removeAt(1);
    REQUIRE( l.isEmpty() == true );
}

TEST_CASE( "Copy constructor and operator" ) {
    aList l;
    l.insert(3);
    l.insert(1);
    l.insert(2);
    aList l2(l);
    REQUIRE( l.getAt(3) == 3 );
    REQUIRE( l2.getAt(3) == 3 );
    l2.removeAt(1);
    l = l2;
    REQUIRE( l.getAt(2) == 3 );
    REQUIRE( l2.getAt(2) == 3 );
}

TEST_CASE( "Move constructor and operator" ) {
    aList l;
    l.insert(3);
    l.insert(1);
    l.insert(2);
    aList l2(std::move(l));
    REQUIRE( l.isEmpty() == true );
    REQUIRE( l2.getAt(3) == 3 );
    l = std::move(l2);
    REQUIRE( l2.isEmpty() == true );
    REQUIRE( l.getAt(3) == 3 );
}

TEST_CASE( "Print and Clean" ) {
    aList l;
    l.insert(3);
    l.insert(1);
    l.insert(2);
    REQUIRE( l.isEmpty() == false );
    l.clean();
    REQUIRE( l.isEmpty() == true );
}

TEST_CASE( "Print (see console log)" ) {
    aList l;
    l.insert(3);
    l.insert(1);
    l.insert(2);
    l.print();
}

// It is your job to create new test cases and fully test your Sorted_List class