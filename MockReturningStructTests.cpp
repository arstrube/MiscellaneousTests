#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

typedef struct Complex_t {
    int i;
    int q;
} Complex_t;

/// A mock returning a struct

static const Complex_t nil = {0, 0};

Complex_t makeComplex(int i, int q)
{
    mock().actualCall("makeComplex")
          .withIntParameter("i", i)
          .withIntParameter("q", q);

    return *(Complex_t*)mock().returnPointerValueOrDefault((void*)&nil);
}

/// Some code to be tested (that happens to test the mock ;-)

bool foo(int i, int q) {
	Complex_t c = makeComplex(i, q);
	return c.i == i && c.q == q;
}

/// Some tests demonstrating the behavior of the mock

TEST_GROUP(MockReturningStruct)
{
    void teardown() {
        mock().clear();
        mock().checkExpectations();
    }
};

TEST(MockReturningStruct, mockReturnsDefaultIfNoReturnValueIsSpecified)
{
	mock().ignoreOtherCalls();

	CHECK_FALSE(foo(1, -1));
}

TEST(MockReturningStruct, mockReturnsCorrectComplexValueStruct)
{
    Complex_t c = {1, -7};
    
	mock().expectOneCall("makeComplex")
	   .ignoreOtherParameters()
	   .andReturnValue(&c);
	   
	CHECK(foo(1, -7));
}

TEST(MockReturningStruct, mockIsCalledWithCorrectParameters)
{
	mock().expectOneCall("makeComplex")
	   .withParameter("i", 1)
	   .withParameter("q", -7);
}

TEST(MockReturningStruct, weirdProblem)
{
    Complex_t* actual = (Complex_t*) 0x5;
    mock().expectNCalls(1, "weird").andReturnValue((void*) &nil);
    mock().actualCall("weird");
    actual = (Complex_t*) mock().returnPointerValueOrDefault(NULL);
    POINTERS_EQUAL(&nil, actual);
}

/// CppUTest main function

int main(int ac, char** av)
{
	return RUN_ALL_TESTS(ac, av);
}

