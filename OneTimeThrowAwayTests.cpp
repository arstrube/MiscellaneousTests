#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness_c.h"
#include <stdexcept>

TEST_GROUP(CHECK_EXCEPTION) {};

void test_me(void) {
    CHECK_THROWS(std::range_error, throw std::range_error(""));
}

TEST(CHECK_EXCEPTION, aTest) {
    MemoryLeakWarningPlugin::turnOnNewDeleteOverloads();
    test_me();
};

int main(int argc, char** argv)
{
    crash_on_allocation_number(2);
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
