#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

// Test double for assert()
void assert(bool condition) {
    if(!condition) mock().actualCall("assert");
}

// Production code
void my_thing(void * other_thing) {
    assert(other_thing);
    // Do useful stuff with non null other_thing
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
