#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness_c.h"

/** For each C test group */
TEST_GROUP_C(mygroup)
{
    TEST_GROUP_C_SETUP_WRAPPER(mygroup);
    TEST_GROUP_C_TEARDOWN_WRAPPER(mygroup);
};

/** For each C test */
TEST_GROUP_C_WRAPPER(mygroup, test_success);
TEST_GROUP_C_WRAPPER(mygroup, test_mockfailure);
TEST_GROUP_C_WRAPPER(mygroup, test_equalfailure);

/** Test main as usual */
int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}

