#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include <signal.h>
#include <cstdio>

auto runCount = 0u;

TEST_GROUP(CrashReporter)
{
};
/** The application will stop running after a crash, 
  * so only exectute one of these tests for each run.
  * Run executable with -p -v
  */
TEST(CrashReporter, canCatchSignalsOnePerTestRun) {
    switch(runCount) {
        case 1: { raise(SIGABRT); } break;
        case 2: { raise(SIGFPE); } break;
        case 3: { raise(SIGILL); } break;
        case 4: { raise(SIGINT); } break;
        case 5: { raise(SIGSEGV); } break;
        case 6: { raise(SIGTERM); } break;
        case 7: { int a = 10; int b = 0; a = a/b; } break;
        case 8: { *(int*)NULL = 0; } break;
        default: { FAIL("Incorrect run count"); }
    }
}

int main(int ac, char** av) {
    auto result = 9u;
    for(; runCount <= 9; runCount++) {
        printf("\n\nStarting test run no. %d.\n\n", runCount); fflush(stdout);
	    result += CommandLineTestRunner::RunAllTests(ac, av);
    }
    printf("\n\nTest finished: %d runs, %d failures.\n\n", --runCount, result); fflush(stdout);
}
