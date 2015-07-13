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

static void _setup(void) {
    CHECK(0 == std::feclearexcept(FE_ALL_EXCEPT));
}
static void _empty(void) {}

TEST_GROUP(FE__with_Plugin) {
    TestTestingFixture fixture;
    IEEE754ExceptionFlagsPlugin* ieee754Plugin;
    void setup(void) override {
        ieee754Plugin = new IEEE754ExceptionFlagsPlugin("IEE754");
        fixture.setSetup(_setup);
        fixture.registry_->installPlugin(ieee754Plugin);
    }
    void teardown(void) override {
        delete ieee754Plugin;
    }
};
TEST(FE__with_Plugin, FE_DIVBYZERO__is_working) {
    fixture.setTestFunction(_divisionbyzero_c);
    fixture.runAllTests();
    fixture.assertPrintContains("CHECK_FALSE(std::fetestexcept(FE_DIVBYZERO)) failed");
}
TEST(FE__with_Plugin, FE_OVERFLOW___is_working) {
    fixture.setTestFunction(_overflow_c);
    fixture.runAllTests();
    fixture.assertPrintContains("CHECK_FALSE(std::fetestexcept(FE_OVERFLOW)) failed");
}
TEST(FE__with_Plugin, FE_UNDERFLOW__is_working) {
    fixture.setTestFunction(_underflow_c);
    fixture.runAllTests();
    fixture.assertPrintContains("CHECK_FALSE(std::fetestexcept(FE_UNDERFLOW)) failed");
}
TEST(FE__with_Plugin, FE_INVALID____is_working) {
    fixture.setTestFunction(_invalid_c);
    fixture.runAllTests();
    fixture.assertPrintContains("CHECK_FALSE(std::fetestexcept(FE_INVALID)) failed");
}
TEST(FE__with_Plugin, FE_INEXACT____is_working) {
    fixture.setTestFunction(_inexact_c);
    fixture.runAllTests();
    fixture.assertPrintContains("CHECK_FALSE(std::fetestexcept(FE_INEXACT)) failed");
}
TEST(FE__with_Plugin, check_no_FE) {
    fixture.setTestFunction(_empty);
    fixture.runAllTests();
    fixture.assertPrintContains("OK (1 tests, 1 ran, 1 checks, 0 ignored, 0 filtered out, 0 ms)");
}

int main(int ac, char** av) {
	return RUN_ALL_TESTS(ac, av);
}
