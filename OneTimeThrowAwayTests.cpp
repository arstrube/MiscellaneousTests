#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(CHECK_EXCEPTION) {
};

TEST(CHECK_EXCEPTION, aTest) {
    CHECK_THROWS(char*, throw "");
};

int main(int argc, char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
