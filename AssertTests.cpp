#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "CppUTestExt/MockSupportPlugin.h"

/** ASSERT callback and macros */

void X_onAssert(char const * const file, int line);

#define X_DEFINE_THIS_FILE \
    static char const l_this_file[] = __FILE__;

#define X_DEFINE_THIS_MODULE(name_) \
    static char_t const l_this_file[] = name_;

#define X_ASSERT(test_) \
        ((test_) ? (void)0 : X_onAssert(&l_this_file[0], (int)__LINE__))

#define Q_ASSERT_ID(id_, test_) \
        ((test_) ? (void)0 : X_onAssert(&l_this_file[0], (int)(id_)))


X_DEFINE_THIS_FILE
X_DEFINE_THIS_MODULE("AssertTests")

static void X_onAssert(char const * const file, int line)
{
    mock().actualCall().withParameter("file", file).withParameter("line", line);
    FAIL("ASSERT failed")
}

void functionToTest(void * ptr)
{
    X_ASSERT(0 != ptr);
    ptr[2] = 0;
}

TEST_GROUP(Group)
{
};

TEST(Group, Test)
{
    mock()
}

int main(int ac, char** av)
{

	return CommandLineTestRunner::RunAllTests(ac, av);
}

