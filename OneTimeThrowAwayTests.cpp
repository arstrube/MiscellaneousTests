#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/TestTestingFixture.h"
#include "CppUTest/TestRegistry.h"
#include <assert.h>

// Production code
void my_thing(int * other_thing) {
    assert(other_thing);
    *other_thing = 5; /* crash */
}

TEST_GROUP(useful) {};

static void assert_test_function_(void) {
    my_thing(0);
}

TEST(useful, null_pointer_should_trigger_assert) {
    TestTestingFixture fixture;
    fixture.registry_->setRunTestsInSeperateProcess();
    fixture.setTestFunction((void(*)())assert_test_function_);
    fixture.runAllTests();
    fixture.assertPrintContains("Failed in separate process - killed by signal 6");
}

int main(int argc, char** argv) {
    return RUN_ALL_TESTS(argc, argv);
}
