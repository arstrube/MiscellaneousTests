#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/MockSupport.h"
#include "CppUTestExt/MockSupportPlugin.h"

extern "C" {
    #include "ArrayTypes.h"
}


/// Tests

TEST_GROUP(Matrices) {};

TEST(Matrices, callAllFunctions) {
    useAllFunctions();
}

/// CppUTest main function

int main(int ac, char** av)
{
    MockSupportPlugin mockPlugin;
    TestRegistry::getCurrentRegistry()->installPlugin(&mockPlugin);
    return RUN_ALL_TESTS(ac, av);
}

/****
 Observations:
 1. Why pass a pointer to an array, unless you want to modify the address of the array? 
    It makes no sense to pass a pointer to a pointer, if it is gonna be const anyway.
 ****/
