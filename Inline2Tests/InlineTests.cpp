#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

extern "C" {
#include "Lib.h"
}

TEST_GROUP(inline) {};

TEST(inline, test_lib_add) {
   LONGS_EQUAL(3, lib_add(1, 2));
}

TEST(inline, test_lib_mul) {
   LONGS_EQUAL(15, lib_mul(3, 5));
}

TEST(inline, test_lib_sub) {
   LONGS_EQUAL(-1, lib_sub(3, 4));
}

TEST(inline, test_lib_div) {
   LONGS_EQUAL(3, lib_div(10, 3));
}

/** Test main as usual */
int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

