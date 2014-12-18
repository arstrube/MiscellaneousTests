#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include <memory>

TEST_GROUP(AutoPtr) {
    void setup() {
        MemoryLeakWarningPlugin::turnOffNewDeleteOverloads(); // TODO: Persistence.Remove()
    }
    void teardown() {
        MemoryLeakWarningPlugin::turnOnNewDeleteOverloads();
    }
};

TEST(AutoPtr, aTest) {
    int * bla = new int();
    *bla = 6;
    CHECK(std::auto_ptr<int>(NULL).get() == std::auto_ptr<int>(NULL).get())
}

/** Test main as usual */
int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

