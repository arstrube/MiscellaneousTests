#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

extern "C" {
    #include "Colors.h"
}

#include "Colors_fake.h"

extern unsigned int c;

TEST_GROUP(Colors_c) {
    void setup() { 
        c = 0;
    }
};

TEST(Colors_c, increment1) {
    Colors_increment();
    BYTES_EQUAL(1, c);
}

TEST(Colors_c, increment2) {
    Colors_increment();
    Colors_increment();
    BYTES_EQUAL(2, c);
}

TEST(Colors_c, overflow) {
    Colors_increment();
    Colors_increment();
    Colors_increment();
    BYTES_EQUAL(0, c);
}

TEST(Colors_c, stubbed) {
    UT_PTR_SET(Colors_Fake::Colors_increment, Stub::Colors_increment);
    Colors_increment();
    BYTES_EQUAL(1, c);
}

int main(int ac, char** av) {
	return RUN_ALL_TESTS(ac, av);
}
