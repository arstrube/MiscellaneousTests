#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

/* Definition from header */

void Sys_sleep(void);

/* Macro definition must occur after header */

#define Sys_sleep() break

/* Source to be tested */

void Task_run(void)
{
    for(;;)
    {
        Sys_sleep();
    }
}

/* Tests */

TEST_GROUP(Task)
{
};

TEST(Task, run)
{
    Task_run();
}

int main(int ac, char** av)
{
    return RUN_ALL_TESTS(ac, av);
}
