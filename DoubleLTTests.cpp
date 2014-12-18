#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

enum comparisons {
    LT,
    LE,
    GT,
    GE,
    POS
} comparision;

#define DOUBLES_SHOULD(a, cmp, b) {\
    SimpleString text; \
    switch(cmp) { \
        case LT: doubles_should_lt(a, b, text); break; \
        case GE: doubles_should_ge(a, b, text); break;\
    } \
}

void doubles_should_ge(double a, double b, SimpleString text) {
    if(a < b) {
        text = StringFrom(a) + SimpleString(" not GE ") + StringFrom(b);
        FAIL(text.asCharString());
    }
}

void doubles_should_lt(double a, double b, SimpleString text) {
    if(a >= b) {
        text = StringFrom(a) + SimpleString(" not LT ") + StringFrom(b);
        FAIL(text.asCharString());
    }
}

TEST_GROUP(DOUBLE_LT) {};

TEST(DOUBLE_LT, test_0p6_lt_0p5) {
    DOUBLES_SHOULD(0.5, GE, 0.0f);
    DOUBLES_SHOULD(0.5, LT, 0.5);
}

TEST(DOUBLE_LT, test_0p5_lt_05) {
    DOUBLES_SHOULD(0.6, GE, 0.0);
    DOUBLES_SHOULD(0.6, LT, 0.5);
}

TEST(DOUBLE_LT, test_0p4_lt_0p5) {
    DOUBLES_SHOULD(0.3, GE, 0.0);
    DOUBLES_SHOULD(0.3, LT, 0.5);
}

TEST(DOUBLE_LT, test_negative) {
    DOUBLES_SHOULD(-0.0001, GE, 0.0);
    DOUBLES_SHOULD(-0.0001, LT, 0.5);
}

/** Test main as usual */
int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

