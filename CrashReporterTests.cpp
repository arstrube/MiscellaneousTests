#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include <signal.h>

TEST_GROUP(CrashReporter)
{
};

// The application will stop running after a crash, so only one of these tests can be tested at a time.

TEST(CrashReporter, RaisingSignals)
 {
 // The crash reporter can catch any of these
 //raise(SIGABRT);
 //raise(SIGFPE);
 raise(SIGILL);
 //raise(SIGINT);
 //raise(SIGSEGV);
 //raise(SIGTERM);
 }

IGNORE_TEST(CrashReporter, DivideByZero)
 {
 int a = 10;
 int b = 0;
 a = a/b;
 }

IGNORE_TEST(CrashReporter, reportsAccessViolationCrash) 
{
    *(int*)NULL = 0;
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}
