#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

extern "C" {
#include "uses_malloc.h"
}

TEST_GROUP(tests) {
};

TEST(tests, malloc_dontfree) {
    allocate();
//    deallocate();
}

TEST(tests, new_dontdelete) {
    int * dummy = new int(3);
    (void) dummy;
//    delete dummy;
}


/** Test main as usual */
int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}
