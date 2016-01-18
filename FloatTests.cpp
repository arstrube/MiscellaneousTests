#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "math.h"

union Double_t {
    Double_t(const double num = 0.0l) : d(num) {}
    double d;
    struct {
        uint64_t mantissa : 52;
        uint64_t exponent : 11;
        uint64_t sign : 1;
    } parts;
};

union Float_t {
    Float_t(const float num = 0.0l) : f(num) {}
    Float_t(const uint32_t num) : bits(num) {}
    float f;
    struct {
        uint32_t mantissa : 23;
        uint32_t exponent : 8;
        uint32_t sign : 1;
    } parts;
    uint32_t bits;
};

double PlatformSpecificGetNaN() {
    Double_t d;
    d.parts.exponent = 0x7ff;
    d.parts.mantissa = 1;
    return d.d;
}

TEST_GROUP(tests) {
};

TEST(tests, funkyFloat) {
    Float_t funky(0xfffffffc);
    BITS_EQUAL(0xfffffffc, funky.bits, 0xffffffff)
    DOUBLES_EQUAL(-4.9, funky.f, 0.00001);
    DOUBLES_EQUAL(4.9, fabs(funky.f), 0.00001);
}

TEST(tests, isnan) {
    const double zero = 0.0;
    const double not_a_number = zero / zero;
    const Double_t mynan = Double_t(PlatformSpecificGetNaN());
    LONGS_EQUAL(0x7ff, mynan.parts.exponent )
    LONGS_EQUAL(0x1, mynan.parts.mantissa )
    DOUBLES_EQUAL(not_a_number, mynan.d, 0.0);
}

/** Test main as usual */
int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}

