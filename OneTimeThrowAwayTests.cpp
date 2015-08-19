#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness_c.h"

TEST_GROUP(CHECK_EXCEPTION) {};

TEST(CHECK_EXCEPTION, aTest) {
    MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
};

int main(int argc, char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
