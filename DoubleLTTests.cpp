#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#define DOUBLES_GE(a, b) doubles_should( a>=b , make_text(a, "GE", b));
#define DOUBLES_LT(a, b) doubles_should( a< b , make_text(a, "LT", b));
//... etc.

#define make_text(a, operator, b) SimpleString(StringFrom(a) + " is not " + operator + " " + StringFrom(b))
#define doubles_should(cond, text) if(!(cond)) FAIL(text.asCharString());

TEST_GROUP(DoubleComparisons) {};

TEST(DoubleComparisons, test_0p5_lt_05) {
    DOUBLES_GE(0.5, 0.0); DOUBLES_LT(0.5, 0.5);
}

TEST(DoubleComparisons, test_0p3_lt_0p5) {
    DOUBLES_GE(0.3, 0.0); DOUBLES_LT(0.3, 0.5);
}

TEST(DoubleComparisons, test_negative) {
    DOUBLES_GE(-0.0001, 0.0); DOUBLES_LT(-0.0001, 0.5);
}

TEST(DoubleComparisons, test_zero) {
    DOUBLES_GE(-0.0, 0.0); DOUBLES_LT(-0.0, 0.5);
}

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

