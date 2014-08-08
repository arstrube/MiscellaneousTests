#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/PlatformSpecificFunctions.h"

extern "C" {
}


TEST_GROUP(PlatformSpecificFunctions) {};

#define not_a_number 0.0/0.0
#define infinity 1.0/0.0

TEST(PlatformSpecificFunctions, Fabs)
{
    CHECK(PlatformSpecificFabs(-0.0) == 0.0);
    CHECK(PlatformSpecificFabs(0.0) == 0.0);
    CHECK(PlatformSpecificFabs(-127.345671209) == 127.345671209);
    CHECK(PlatformSpecificFabs(3500.0) == 3500.0);
    CHECK(PlatformSpecificFabs(infinity) == infinity);
    CHECK(PlatformSpecificFabs(not_a_number) != 0.0);
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}
