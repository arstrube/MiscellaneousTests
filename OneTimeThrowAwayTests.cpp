#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#define USE_LONGLONG

TEST_GROUP(longlong) {
    long long value;
};

TEST(longlong, myTest) {
    value = 0xFFFFFFFFFFFFFFFF;
    LONGLONGS_EQUAL(0xFFFFFFFFFFFFFFFE, value); // expecting failure
}

CPPUTEST_DEFAULT_MAIN
