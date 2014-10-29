#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include <cstdio>

#if 0
 #include <signal.h>
 #define RAISE(a) raise(a)
 #define DIVISION_BY_ZERO { int a = 10; int b = 0; a = a/b; }
 #define ACCESS_VIOLATION { *(int*)NULL = 0; }
#else
 #define RAISE(a) {}
 #define DIVISION_BY_ZERO {}
 #define ACCESS_VIOLATION {}
#endif

static auto runCount = 7u;

TEST_GROUP(CrashReporter)
{
};
TEST(CrashReporter, canCatchSIGABRT) {
    if(1 == runCount) RAISE(SIGABRT);
}
TEST(CrashReporter, canCatchSIGFPE) {
    if(2 == runCount) RAISE(SIGFPE);
}
TEST(CrashReporter, canCatchSIGILL) {
    if(3 == runCount) RAISE(SIGILL);
}
TEST(CrashReporter, canCatchSIGINT) {
    if(4 == runCount) RAISE(SIGINT);
}
TEST(CrashReporter, canCatchSIGSEGV) {
    if(5 == runCount) RAISE(SIGSEGV);
}
TEST(CrashReporter, canCatchSIGTERM) {
    if(6 == runCount) RAISE(SIGTERM);
}
TEST(CrashReporter, canCatchDIVISION_BY_ZERO) {
    if(7 == runCount) DIVISION_BY_ZERO;
}
TEST(CrashReporter, canCatchACCESS_VIOLATION) {
    if(8 == runCount) ACCESS_VIOLATION
}
#define MAX_TESTS 8u
TEST(CrashReporter, TOO_MANY_TEST_RUNS) {
    if(MAX_TESTS < runCount) FAIL("Too many test runs");;
}

int main(int ac, char** av) {
    auto result = 0u;
    for(; runCount <= MAX_TESTS+1; runCount++) {
        printf("\n\nStarting test run no. %d.\n\n", runCount); fflush(stdout);
	    result += CommandLineTestRunner::RunAllTests(ac, av);
    }
    printf("\n\nTest finished: %d runs, %d failures.\n\n", --runCount, result); fflush(stdout);
    return result;
}
