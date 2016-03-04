#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

#define ACTUAL_ASSERT_TEXT(s) { if(!condition) throw s; }
#define CHECK_ASSERT_FAILED(f) \
{ \
    bool assert_triggered = false; \
    try { f; } catch (char const* e) { assert_triggered = true; } \
    CHECK(assert_triggered); \
}

// Test double for assert()
void assert(bool condition) {
    ACTUAL_ASSERT_TEXT("");
}

// Production code
void my_thing(int * other_thing) {
    assert(other_thing);
    *other_thing = 5; /* crash */
}

TEST_GROUP(useful) {};

TEST(useful, null_pointer_should_trigger_assert) {
    CHECK_ASSERT_FAILED(my_thing(0));
}

int main(int argc, char** argv) {
    return RUN_ALL_TESTS(argc, argv);
}
