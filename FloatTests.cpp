#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

//#define _DEBUG
//#include "Float_t.h"

union Double_t
{
    Double_t(double num = 0.0l) : d(num) {}
    double d;
    struct
    {
        uint64_t mantissa : 52;
        uint64_t exponent : 11;
        uint64_t sign : 1;
    } parts;
};

double PlatformSpecificGetNaN() 
{
    Double_t d;
    d.parts.exponent = 0x3FF;
    d.parts.mantissa = 1;
    return d.d;
}

TEST_GROUP(double)
{
};

TEST(double, isnan)
{
    const double zero = 0.0;
    const double not_a_number = zero / zero;
    const Double_t mynan = Double_t(PlatformSpecificGetNaN());
    LONGS_EQUAL(0x3ff, (uint32_t) mynan.parts.exponent )
    LONGS_EQUAL(0x1, (uint32_t) mynan.parts.mantissa )
    DOUBLES_EQUAL(not_a_number, PlatformSpecificGetNaN(), 0.0);
}

/** Test main as usual */
int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

