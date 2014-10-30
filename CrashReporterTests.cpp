#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(SeparateProcessBug) {};
TEST(SeparateProcessBug, Success) { CHECK(false); }

int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}
