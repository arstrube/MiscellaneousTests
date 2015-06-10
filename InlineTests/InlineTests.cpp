#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

extern "C" {
#include "InlineLib.h"
}

TEST_GROUP(inline) {};

TEST(inline, test_lib_func1) {
   LONGS_EQUAL(8, lib_func1(8));
}

TEST(inline, test_lib_func2) {
   LONGS_EQUAL(17, lib_func2(17));
}

/** Test main as usual */
int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

