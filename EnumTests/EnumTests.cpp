#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

extern "C" {
    #include "Enum.h"
}

#include "Enum_fake.h"

extern unsigned int c;

TEST_GROUP(increment) {
    void setup() { 
        c = 0;
    }
};

TEST(increment, increment1) {
    increment();
    BYTES_EQUAL(1, c);
}

TEST(increment, increment2) {
    increment();
    increment();
    BYTES_EQUAL(2, c);
}

TEST(increment, overflow) {
    increment();
    increment();
    increment();
    BYTES_EQUAL(0, c);
}

TEST(increment, stubbed) {
    UT_PTR_SET(Enum_Fake::increment, Stub::increment);
    increment();
    BYTES_EQUAL(1, c);
}

int main(int ac, char** av) {
	return RUN_ALL_TESTS(ac, av);
}
