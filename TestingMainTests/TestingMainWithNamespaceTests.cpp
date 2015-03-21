#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#define MAX_ITERATIONS 10

namespace Control_class {
    void main (void);
}

void Task1_run() {
    mock().actualCall("Task1_run");
}

void Task2_run() {
    mock().actualCall("Task2_run");
}

void Sys_sleep(int) {
    static int count = 1;
    count++;
    if(count > MAX_ITERATIONS) {
        count = 1;
        throw "Bailing out";
    }
}

TEST_GROUP(Control_class) {};

TEST(Control_class, main_with_namespace_Task1_runs) {
    mock().expectNCalls(MAX_ITERATIONS, "Task1_run");
    mock().ignoreOtherCalls();
    try {
        Control_class::main();
    }
    catch(char const* s) {
    }
}

TEST(Control_class, main_with_namespace_Task2_runs) {
    mock().expectNCalls(MAX_ITERATIONS, "Task2_run");
    mock().ignoreOtherCalls();
    try {
        Control_class::main();
    }
    catch(char const* s) {
    }
}

