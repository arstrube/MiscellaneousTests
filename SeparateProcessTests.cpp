#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

extern "C"
{
}

struct Data
{
    Data(int value) : value_(value) {}
    int value_;
};

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

TEST(Separate_Process, thisTestCrashesAlso)
{
	Data* data = NULL;
	data->value_ = 15;
	LONGS_EQUAL(15, data->value_);
}

TEST(Separate_Process, STRCMP_EQUAL_CrashesWithNULL)
{
	STRCMP_EQUAL("Hello", NULL);
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}
