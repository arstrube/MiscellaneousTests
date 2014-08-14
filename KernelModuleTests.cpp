#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "KernelModule.h"

extern "C" {
}

TEST_GROUP(KernelModule) {};

TEST(KernelModule, Init)
{
    FAIL("Not implemented.")
}

TEST(KernelModule, Cleanup)
{
    FAIL("Not implemented.")
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}
