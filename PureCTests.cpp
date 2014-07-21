#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

/** This will not work in C++

extern "C" {
    #include "PureCTests_c.h" /// Header will not compile in c++
}

*/
int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}

