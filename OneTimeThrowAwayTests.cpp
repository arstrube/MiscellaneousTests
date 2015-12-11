#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP(Leaks) {};

TEST(Leaks, thisLeaks) {
    MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
};

int main(int argc, char** argv) {
    return RUN_ALL_TESTS(argc, argv);
}
