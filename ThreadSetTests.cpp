#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include <pthread.h>
#include <unistd.h>

#define MAX_TIMEOUT 1000000

static volatile bool reg;
pthread_t tid;

void* setReg (void*)
{
    usleep(100);
    reg = true;
    return 0;
}

bool problematic_function(void)
{
    reg = false;
    bool retVal = true;
    unsigned int timeout = 0;
    
    while (false == reg) {
        timeout++;
        if (MAX_TIMEOUT <= timeout){
            retVal = false;
            break;
        }
    }
    return retVal;
}

TEST_GROUP(ThreadSetTest)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(ThreadSetTest, myTest)
{
    CHECK(0==pthread_create(&tid, NULL, setReg, NULL));
    CHECK(problematic_function());
}

int main(int ac, char** av)
{
    int result = CommandLineTestRunner::RunAllTests(ac, av);
    return result;
}
