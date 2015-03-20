#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#define MAX_ITERATIONS 10

extern "C" {

    void Control_class_main(void);
    
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
            throw "Bailing out";
        }
    }
}

TEST_GROUP(Control_class) {};

TEST(Control_class, main) {
    mock().expectNCalls(MAX_ITERATIONS, "Task1_run");
    mock().expectNCalls(MAX_ITERATIONS, "Task2_run");
    try {
        Control_class_main();
    }
    catch(char const* s) {
    }
}
