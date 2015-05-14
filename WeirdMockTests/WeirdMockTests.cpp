/**********************************************************************
 SOLUTION 1 (PREFERRED):
 USE MOCKSUPPORTPLUGIN FOR COMPARATORS
 NOTE: FAILING MOCK EXPECTATION IS ESSENTIAL
 **********************************************************************/

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/MockSupport.h"
#include "CppUTestExt/MockSupportPlugin.h"

class DummyComparator : public MockNamedValueComparator {
    virtual bool isEqual(const void*, const void*) {
        return true;
    }
    virtual SimpleString valueToString(const void*) {
        return "dummy";
    }
};

/// The actual tests

TEST_GROUP(WeirdMock) {};

TEST(WeirdMock, WeirdWithCallToWriteArray) {
	mock().expectOneCall("function")
          .withParameterOfType("dummy", "parameter", (void*)1);
}

/// CppUTest main function

int main(int ac, char** av)
{
    MockSupportPlugin mockPlugin;
    DummyComparator comparator;
    mockPlugin.installComparator("dummy", comparator);
    TestRegistry::getCurrentRegistry()->installPlugin(&mockPlugin);
    return RUN_ALL_TESTS(ac, av);
}
