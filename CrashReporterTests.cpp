#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(SeparateProcessBug) {};
TEST(SeparateProcessBug, Fail) { CHECK(false); }
TEST(SeparateProcessBug, Pass) { CHECK(true); }

int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}
