#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "Control_class_wrapper.h"

void Task1_run() {}
void Task2_run() {}make
void sleep(int) {}

TEST_GROUP(Control_class) {};

TEST(Control_class, main) {
    Control_class::main();
}
