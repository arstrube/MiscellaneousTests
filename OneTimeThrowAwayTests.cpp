#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

// Test double for assert()
void assert(bool condition) {
    if(!condition) mock().actualCall("assert");
}

// Production code
void my_thing(int * other_thing) {
    assert(other_thing);
    *other_thing = 5; /* crash */
}

TEST_GROUP(useful) {};

TEST(useful, null_pointer_should_trigger_assert) {
    mock().expectOneCall("assert");
    my_thing(0);
    mock().checkExpectations();
    mock().clear();
}

int main(int argc, char** argv) {
    return RUN_ALL_TESTS(argc, argv);
}
