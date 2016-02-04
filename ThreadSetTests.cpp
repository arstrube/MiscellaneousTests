#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include <pthread.h>
#include <unistd.h>

#define MAX_TIMEOUT 100

static volatile bool reg;
pthread_t tid;

void* setReg (void*)
{
    do {
    } while(true==reg);
    reg = true;
    return 0;
}

bool problematic_function(void)
{
    reg = false;
    bool retVal = true;
    int timeout = 0;

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
    reg=true;
    CHECK(0==pthread_create(&tid, NULL, setReg, NULL));
    usleep(100000);
    CHECK(problematic_function());
}

int main(int ac, char** av)
{
    int result = CommandLineTestRunner::RunAllTests(ac, av);
    return result;
}
