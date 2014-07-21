#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "CppUTestExt/MockSupportPlugin.h"
#include <cstdio>

/** ASSERT callback and macros */

void X_onAssert(char const * const file, int line);
/*
#define X_DEFINE_THIS_FILE \
    static char const l_this_file[] = __FILE__;
*/
#define X_DEFINE_THIS_MODULE(name_) \
    static char const l_this_file[] = name_;

#define X_ASSERT(test_) \
        ((test_) ? (void)0 : X_onAssert(&l_this_file[0], (int)__LINE__))

#define X_ASSERT_ID(id_, test_) \
        ((test_) ? (void)0 : X_onAssert(&l_this_file[0], (int)(id_)))


/* X_DEFINE_THIS_FILE */
X_DEFINE_THIS_MODULE("AssertTests")

void X_onAssert(char const * const file, int line)
{
    mock().actualCall("X_onAssert").withParameter("file", file).withParameter("line", line);
    fprintf(stderr, "Assertion failed in %s, line %d", file, line);
    fflush(stdout);
    FAIL("");
}

void functionToTest(char * ptr)
{
    X_ASSERT_ID(1, 0 != ptr);
    ptr[1] = 0;
}

TEST_GROUP(Group)
{
};

TEST(Group, Test)
{
    mock().expectOneCall("X_onAssert").withParameter("file", "AssertTests")
          .withParameter("line", 1);
    functionToTest(0);
}

int main(int ac, char** av)
{
    MockSupportPlugin mockPlugin;
    TestRegistry::getCurrentRegistry()->installPlugin(&mockPlugin);
	return CommandLineTestRunner::RunAllTests(ac, av);
}

