#if 0

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

extern "C" {
#include "ModifiedVariably.h"
}

TEST_GROUP(ModifiedVariably) {};

/** Test main as usual */
int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

#endif

int main(int, char**)
{
    return 0;
}