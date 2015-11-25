#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/MockSupportPlugin.h"

TEST_GROUP(MultiMockFailTest)
{
    void teardown()
    {
        // mock().checkExpectations(); /* Makes multiple failures go away */
    }
};

TEST(MultiMockFailTest, MyTest)
{
    mock().expectOneCall("NonExistantMock");
	FAIL("This test failed.");
}

int main(int ac, char** av)
{
    MockSupportPlugin mockPlugin;
    TestRegistry::getCurrentRegistry()->installPlugin(&mockPlugin);
    return RUN_ALL_TESTS(ac, av);
}
