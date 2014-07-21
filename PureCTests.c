#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C" {
}

struct A { struct B { int a; } b; int c; };
struct B b; // ill-formed: b has incomplete type (*not* A::B)

struct Data
{
    Data(int value) : value_(value) {}
    int value_;
};

long Mocking_returnLongInt(void)
{
	mock().actualCall("Mocking_returnLongInt");
	return mock().longIntReturnValue();
}

TEST_GROUP(SimpleTypes)
{
    void teardown()
    {
	    mock().checkExpectations();
	    mock().clear();
    }
};

TEST(SimpleTypes, someLongInt)
{
	long actual, expected = 0x012345678;
	mock().expectOneCall("Mocking_returnLongInt")
          .andReturnValue(expected);
	actual = Mocking_returnLongInt();
	LONGS_EQUAL(0x012345678, actual);
}

TEST(SimpleTypes, default)
{
	long actual;
	mock().expectOneCall("Mocking_returnLongInt");
	actual = Mocking_returnLongInt();
	LONGS_EQUAL(0x0, actual);
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}

