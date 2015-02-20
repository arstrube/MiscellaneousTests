#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

extern "C"
{
}

TEST_GROUP(Separate_Process)
{
};

TEST(Separate_Process, thisTestIsStillRunAndSucceeds)
{
    LONGS_EQUAL(1, 1);
}

TEST(Separate_Process, thisTestIsStillRunAndFails)
{
    LONGS_EQUAL(3, 1);
}

TEST(Separate_Process, thisTestIsStillRunAndCrashesWithDivisionByZero)
{
	int bar = 0;
	LONGS_EQUAL(0, 1/bar);
}

TEST(Separate_Process, thisTestCrashesWithCoreDump)
{
	int* value = NULL;
	LONGS_EQUAL(15, *value);
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}
