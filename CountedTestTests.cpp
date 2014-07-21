#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/OrderedTest.h"
#include "CppUTest/TestRegistry.h"

extern "C" 
{
}

#define TOTAL_NUMBER_OF_TESTS 11

static int testsRun = 0;

TEST_GROUP(Group1)
{
    void setup()
    {
        testsRun++;
    }
};

TEST(Group1, Test1)
{
}

TEST(Group1, Test2) 
{
}

TEST(Group1, Test3) 
{
}

TEST_ORDERED(Group1, Order3, 3) 
{
}

TEST_ORDERED(Group1, Order1, 1) 
{
}

TEST_ORDERED(Group1, Order2, 2) 
{
}

TEST(Group1, Test4) 
{
}

TEST(Group1, Test5) 
{
}

TEST(Group1, Test6) 
{
}

TEST_ORDERED(Group1, Order4, 4) 
{
}

TEST_GROUP(VerifyNumberOfTests)
{
};

TEST_ORDERED(VerifyNumberOfTests, VerifyNumber_Order9999, 9999)
{
    testsRun++;
    int repeats = TestRegistry::getCurrentRegistry()->getCurrentRepetition();
    if(repeats) testsRun/=(++repeats);
    LONGS_EQUAL(TOTAL_NUMBER_OF_TESTS, testsRun)
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}

