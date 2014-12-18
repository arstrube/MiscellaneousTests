#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#define DOUBLES_GE(a, b) { doubles_should( a>=b , make_text(a, "GE", b)); }
#define DOUBLES_LT(a, b) { doubles_should( a< b , make_text(a, "LT", b)); }
//... etc.

SimpleString make_text(double a, SimpleString op, double b) {
    return StringFrom(a) + " not " + op + " " + StringFrom(b);
}

void doubles_should (bool t, SimpleString text) {
    if(!t) FAIL(text.asCharString());
}

TEST_GROUP(DOUBLE_LT) {};

TEST(DOUBLE_LT, test_0p6_lt_0p5) {
    DOUBLES_GE(0.5, 0.0f);
    DOUBLES_LT(0.6, 0.5f);
}

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

