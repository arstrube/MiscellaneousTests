/**********************************************************************
 SOLUTION 3:
 CHECK MOCK EXPECTATIONS WITHIN SCOPE
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
    DummyComparator comparator;
    mock().installComparator("dummy", comparator);
	mock().expectOneCall("function")
          .withParameterOfType("dummy", "parameter", (void*)1);
    mock().checkExpectations();
}

/// CppUTest main function

int main(int ac, char** av)
{
    MockSupportPlugin mockPlugin;
    TestRegistry::getCurrentRegistry()->installPlugin(&mockPlugin);
    return RUN_ALL_TESTS(ac, av);
}
