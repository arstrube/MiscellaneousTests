#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

extern "C" {
#include "ModifiedVariably.c"
}

TEST_GROUP(ModifiedVariably) {};

/** Test main as usual */
int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

#if 0

int main(int, char**)
{
    return 0;
}

#endif
