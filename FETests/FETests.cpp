#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTest/IEEE754ExceptionFlagsPlugin.h"
#include "CppUTest/TestTestingFixture.h"
#include <cfenv>
#include <cmath>
#include <limits>

extern "C" { 
    #include "FETests_c.h"
}

static void IEEE754_setup(void) {
    std::feclearexcept(FE_ALL_EXCEPT);
}

TEST_GROUP(FE__with_Plugin) {
    TestTestingFixture fixture;
    IEEE754ExceptionFlagsPlugin* ieee754Plugin;
    void setup(void) override {
        ieee754Plugin = new IEEE754ExceptionFlagsPlugin("IEE754");
        fixture.setSetup(IEEE754_setup);
        fixture.registry_->installPlugin(ieee754Plugin);
    }
    void teardown(void) override {
        delete ieee754Plugin;
    }
};
TEST(FE__with_Plugin, should_fail_when__FE_DIVBYZERO__is_set) {
    fixture.setTestFunction(set_divisionbyzero_c);
    fixture.runAllTests();
    fixture.assertPrintContains("CHECK_FALSE(std::fetestexcept(FE_DIVBYZERO)) failed");
}
TEST(FE__with_Plugin, should_fail_when__FE_OVERFLOW___is_set) {
    fixture.setTestFunction(set_overflow_c);
    fixture.runAllTests();
    fixture.assertPrintContains("CHECK_FALSE(std::fetestexcept(FE_OVERFLOW)) failed");
}
TEST(FE__with_Plugin, should_fail_when__FE_UNDERFLOW__is_set) {
    fixture.setTestFunction(set_underflow_c);
    fixture.runAllTests();
    fixture.assertPrintContains("CHECK_FALSE(std::fetestexcept(FE_UNDERFLOW)) failed");
}
TEST(FE__with_Plugin, should_fail_when__FE_INVALID____is_set) {
    fixture.setTestFunction(set_invalid_c);
    fixture.runAllTests();
    fixture.assertPrintContains("CHECK_FALSE(std::fetestexcept(FE_INVALID)) failed");
}
TEST(FE__with_Plugin, should_fail_when__FE_INEXACT____is_set) {
    fixture.setTestFunction(set_inexact_c);
    fixture.runAllTests();
    fixture.assertPrintContains("CHECK_FALSE(std::fetestexcept(FE_INEXACT)) failed");
}
TEST(FE__with_Plugin, should_succeed_with_5_checks_when_no_flags_are_set) {
    fixture.setTestFunction(set_nothing_c);
    fixture.runAllTests();
    fixture.assertPrintContains("OK (1 tests, 1 ran, 5 checks, 0 ignored, 0 filtered out, 0 ms)");
}
TEST(FE__with_Plugin, should_check_only_once_when_all_flags_are_set) {
    fixture.setTestFunction(set_everything_c);
    fixture.runAllTests();
    LONGS_EQUAL(1, fixture.getCheckCount());
}
TEST(FE__with_Plugin, should_fail_only_once_when_all_flags_are_set) {
    fixture.setTestFunction(set_everything_c);
    fixture.runAllTests();
    LONGS_EQUAL(1, fixture.getFailureCount());
}

int main(int ac, char** av) {
	return RUN_ALL_TESTS(ac, av);
}
