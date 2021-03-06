#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTest/IEEE754ExceptionFlagsPlugin.h"
#include <cfenv>
#include <limits>

typedef float float32;

TEST_GROUP(FE_Demo) {
};
TEST(FE_Demo, should_fail_when__FE_DIVBYZERO__is_set) {
    float32 f = 1.0f;
    CHECK(f /= 0.0f == std::numeric_limits<float>::infinity() );
}
TEST(FE_Demo, should_fail_when__FE_UNDERFLOW__is_set) {
    float32 f = 0.01f;
    while (f > 0.0f) f *= f;
    CHECK(f == 0.0f);
}
TEST(FE_Demo, should_fail_when__FE_OVERFLOW__is_set) {
    float32 f = 1000.0f;
    while (f < std::numeric_limits<float>::infinity()) f *= f;
    CHECK(f == std::numeric_limits<float>::infinity());
}
TEST(FE_Demo, should_succeed_when_no_flags_are_set) {
    CHECK(5.0f == 15.0f / 3.0f);
}

static IEEE754ExceptionFlagsPlugin ieee754Plugin{"IEEE754"};

int main(int ac, char** av) {
    TestRegistry::getCurrentRegistry()->installPlugin(&ieee754Plugin);
	return RUN_ALL_TESTS(ac, av);
}
