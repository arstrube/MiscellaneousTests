#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness_c.h"

typedef unsigned char uint8;
typedef signed char   sint8;
typedef signed short  sint16;
typedef signed long   sint32;

#define RANGE(x,a,b) (((x)>=(a))&&((x)<=(b)))

TEST_GROUP(range) {};

TEST(range, uint8_works_correctly)
{
    uint8 x;
    x = 3;  CHECK_TRUE(RANGE(x,2,4));
    x = 3;  CHECK_TRUE(RANGE(x,3,3));
    x = 0;   CHECK_TRUE(RANGE((sint16)x,0,10));
/*     x = 255; CHECK_TRUE(RANGE(x,10,255));
    x = 3;   CHECK_FALSE(RANGE(x,4,5));
    x = 3;   CHECK_FALSE(RANGE(x,0,2)); */
}
#if 0
IGNORE_TEST(range, sint8_works_correctly)
{
    uint8 x;
    x = 3;  CHECK_TRUE(RANGE_WITH_NO_COMPILER_WARHINGS(x,2,4));
    x = 3;  CHECK_TRUE(RANGE_WITH_NO_COMPILER_WARHINGS(x,3,3));
    x = -128;   CHECK_TRUE(RANGE_WITH_NO_COMPILER_WARHINGS(x,-128,0));
    x = 127; CHECK_TRUE(RANGE_WITH_NO_COMPILER_WARHINGS(x,0,127));
    x = 3;   CHECK_FALSE(RANGE_WITH_NO_COMPILER_WARHINGS(x,4,5));
    x = 3;   CHECK_FALSE(RANGE_WITH_NO_COMPILER_WARHINGS(x,0,2));
    x = -3;   CHECK_FALSE(RANGE_WITH_NO_COMPILER_WARHINGS(x,-5,-4));
    x = -3;   CHECK_FALSE(RANGE_WITH_NO_COMPILER_WARHINGS(x,-2,0));
}
#endif
/** Test main as usual */
int main(int ac, char** av)
{
	return RUN_ALL_TESTS(ac, av);
}

