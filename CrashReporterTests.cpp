#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include <signal.h>
#include <cstdio>

static auto runCount = 1u;

TEST_GROUP(CrashReporter)
{
};
/** The application will stop running after a crash, 
  * so only exectute one of these tests for each run.
  * Will not work with -p.
  */
TEST(CrashReporter, SIGABRT) {
    if(1 == runCount) raise(SIGABRT);
}
TEST(CrashReporter, SIGFPE) {
    if(2 == runCount) raise(SIGFPE);
}
TEST(CrashReporter, SIGILL) {
    if(3 == runCount) raise(SIGILL);
}
TEST(CrashReporter, SIGINT) {
    if(4 == runCount) raise(SIGINT);
}
TEST(CrashReporter, SIGSEGV) {
    if(5 == runCount) raise(SIGSEGV);
}
TEST(CrashReporter, SIGTERM) {
    if(6 == runCount) raise(SIGTERM);
}
TEST(CrashReporter, DIVISION_BY_ZERO) {
    if(7 == runCount) { int a = 10; int b = 0; a = a/b; }
}
TEST(CrashReporter, ACCESS_VIOLATION) {
    if(1 == runCount) { *(int*)NULL = 0; }
}
#define MAX_TESTS 9u
TEST(CrashReporter, TOO_MAN_TEST_RUNS) {
    if(MAX_TESTS < runCount) FAIL("Too many test runs");;
}

int main(int ac, char** av) {
    auto result = 0u;
    for(; runCount <= MAX_TESTS; runCount++) {
        printf("\n\nStarting test run no. %d.\n\n", runCount); fflush(stdout);
	    result += CommandLineTestRunner::RunAllTests(ac, av);
    }
    printf("\n\nTest finished: %d runs, %d failures.\n\n", --runCount, result); fflush(stdout);
    return result;
}
