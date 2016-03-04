#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

// Test double for assert()
void assert(bool condition) {
    if(!condition) throw "";
}

// Production code
void my_thing(int * other_thing) {
    assert(other_thing);
    *other_thing = 5; /* crash */
}

TEST_GROUP(useful) {};

TEST(useful, null_pointer_should_trigger_assert) {
    bool assert_triggered = false;
    try {
        my_thing(0);
    }
    catch (char const* e) {
        assert_triggered = true; 
    }
    CHECK(assert_triggered);
}

int main(int argc, char** argv) {
    return RUN_ALL_TESTS(argc, argv);
}
