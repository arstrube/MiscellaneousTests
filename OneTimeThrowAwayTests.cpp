// File OneTimeThrowAwayTests.cpp

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

// Assertions (simplified)
#define ASSERT(test_) \
    ((test_) ? (void)0 : onAssert(__FILE__, (int)__LINE__))

// Test double for onAssert()
void onAssert(char const * const file, int line) {
    mock().actualCall("onAssert")
         .withParameter("file", file)
         .withParameter("line", (int) line);
}

// Production code
void my_thing(void * other_thing) {
    ASSERT(other_thing);
    // Do useful stuff with non null other_thing
}

TEST_GROUP(useful) {};

TEST(useful, null_pointer_should_trigger_assert) {
    mock().expectOneCall("onAssert")
          .withParameter("file", "OneTimeThrowAwayTests.cpp")
          .withParameter("line", 21);
    my_thing(0);
    mock().checkExpectations();
    mock().clear();
}

int main(int argc, char** argv) {
    return RUN_ALL_TESTS(argc, argv);
}
