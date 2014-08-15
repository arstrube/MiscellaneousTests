/** KernelModuleTests.cpp */

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "KernelModule.h"
#include <cstdarg>
#include "CppUTest/PlatformSpecificFunctions.h"

#define NBUF 2048L
static char buffer[NBUF];

extern "C" {

    /** Kernel function stubs */

    int printk (const char * fmt, ...);

    int printk (const char * fmt, ...)
    {
        va_list args;
        va_start( args, fmt );
        return PlatformSpecificVSNprintf(buffer, NBUF, fmt, args);
    }

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
