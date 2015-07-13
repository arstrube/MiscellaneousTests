#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTest/IEEE754ExceptionFlagsPlugin.h"
#include <cfenv>
#include <cmath>
#include <limits>

extern "C" { 
    #include "FETests_c.h"
} 

static float32 do_divisionbyzero(void) {
    return 1.0f / 0.0f;
}
static float32 do_overflow(float32 f) {
    while (f < std::numeric_limits<float>::infinity()) f *= f;
    return f;
}
static float32 do_underflow(float32 f) {
    while (f > 0.0f) f *= f;
    return f;
}
static float32 do_invalid(void) {
    return sqrt(-1.0f);
}
static float32 do_inexact(void) {
    return 2.0f / 3.0f;
}

TEST_GROUP(FE) {
    void teardown(void) override {
       CHECK(0 == std::feclearexcept(FE_ALL_EXCEPT));
    }
};
TEST(FE, FE_DIVBYZERO____is_working) {
    do_divisionbyzero();
    CHECK(std::fetestexcept(FE_DIVBYZERO));
}
TEST(FE, FE_DIVBYZERO_c__is_working) {
    do_divisionbyzero_c();
    CHECK(std::fetestexcept(FE_DIVBYZERO));
}
TEST(FE, FE_OVERFLOW_____is_working) {
    do_overflow(1000.0f);
    CHECK(std::fetestexcept(FE_OVERFLOW));
}
TEST(FE, FE_OVERFLOW_c___is_working) {
    do_overflow_c(1000.0f);
    CHECK(std::fetestexcept(FE_OVERFLOW));
}
TEST(FE, FE_UNDERFLOW____is_working) {
    do_underflow(0.01f);
    CHECK(std::fetestexcept(FE_UNDERFLOW));
}
TEST(FE, FE_UNDERFLOW_c__is_working) {
    do_underflow_c(0.01f);
    CHECK(std::fetestexcept(FE_UNDERFLOW));
}
TEST(FE, FE_INVALID______is_working) {
    do_invalid();
    CHECK(std::fetestexcept(FE_INVALID));
}
TEST(FE, FE_INVALID_c____is_working) {
    do_invalid_c();
    CHECK(std::fetestexcept(FE_INVALID));
}
TEST(FE, FE_INEXACT______is_working) { /* -frounding-math */
    do_inexact();
    CHECK(fetestexcept(FE_INEXACT));
}
TEST(FE, FE_INEXACT_c____is_working) { /* -frounding-math */
    do_inexact_c();
    CHECK(std::fetestexcept(FE_INEXACT));
}
TEST(FE, check_no_FE) {
    CHECK_FALSE(std::fetestexcept(FE_DIVBYZERO));
    CHECK_FALSE(std::fetestexcept(FE_OVERFLOW));
    CHECK_FALSE(std::fetestexcept(FE_UNDERFLOW));
    CHECK_FALSE(std::fetestexcept(FE_INVALID));
    CHECK_FALSE(std::fetestexcept(FE_INEXACT));
}

TEST_GROUP(FE_PLUGIN) {
    void setup(void) override {
       CHECK(0 == std::feclearexcept(FE_ALL_EXCEPT));
    }
};
TEST(FE_PLUGIN, provoke_failure_to_test_plugin) {
    do_divisionbyzero();
}


int main(int ac, char** av) {
    IEEE754ExceptionFlagsPlugin ieee754Plugin("IEE754");
    TestRegistry::getCurrentRegistry()->installPlugin(&ieee754Plugin);

	return RUN_ALL_TESTS(ac, av);
}
