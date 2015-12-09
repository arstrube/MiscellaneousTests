#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

extern "C" {
#include "ModifiedVariably.h"
}

TEST_GROUP(ModifiedVariably) {};
TEST(ModifiedVariably, align_96_to_4_manually) {
    Test_align_4_st t4;
    LONGS_EQUAL(96 + 96 % 4, sizeof(t4));
}
TEST(ModifiedVariably, align_96_to_8_manually) {
    Test_align_8_st t8;
    LONGS_EQUAL(96 + 96 % 8, sizeof(t8));
}
TEST(ModifiedVariably, align_96_to_64_manually) {
    Test_align_64_st t64;
    LONGS_EQUAL(96 + 96 % 64, sizeof(t64));
}
TEST(ModifiedVariably, align_96_to_4_compiler) {
    Test_align_4c_st tc4;
    LONGS_EQUAL(96 + 96 % 4, sizeof(tc4));
}
TEST(ModifiedVariably, align_96_to_8_compiler) {
    Test_align_8c_st tc8;
    LONGS_EQUAL(96 + 96 % 8, sizeof(tc8));
}
TEST(ModifiedVariably, align_96_to_64_compiler) {
    Test_align_64c_st tc64;
    LONGS_EQUAL(96 + 96 % 64, sizeof(tc64));
}

/** Test main as usual */
int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

#if 0

int main(int, char**)
{
    return 0;
}

#endif
