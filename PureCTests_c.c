#include "PureCTests_c.h"
#include "CppUTest/TestHarness_c.h"
#include "CppUtestExt/MockSupport_c.h"

/** Mock for function internal() */
int internal(int new) 
{
    mock_c()->actualCall("internal")
            ->withIntParameters("new", new);
    return mock_c()->returnValue().value.intValue;
}

/** Function to test */
int private (int new)
{
    return internal(new);
}

/** Setup and Teardown per test group (optional) */
TEST_GROUP_C_SETUP(mygroup)
{
}
TEST_GROUP_C_TEARDOWN(mygroup)
{
    mock_c()->checkExpectations();
    mock_c()->clear();
}

/** The actual tests for this test group */
TEST_C(mygroup, test_success)
{
    mock_c()->expectOneCall("internal")->withIntParameters("new", 5)->andReturnIntValue(5);
    int actual = private(5);
    CHECK_EQUAL_C_INT(5, actual);
}
TEST_C(mygroup, test_mockfailure)
{
    mock_c()->expectOneCall("internal")->withIntParameters("new", 2)->andReturnIntValue(5);
    int actual = private(5);
    CHECK_EQUAL_C_INT(5, actual);
}
TEST_C(mygroup, test_equalfailure)
{
    mock_c()->expectOneCall("internal")->withIntParameters("new", 5)->andReturnIntValue(2);
    int actual = private(5);
    CHECK_EQUAL_C_INT(5, actual);
}
