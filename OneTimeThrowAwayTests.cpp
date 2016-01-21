#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <memory>

class Example {
public:
    void func(int value) {
        mock("Example").actualCall("func").withParameter("value", value);
    }
};

TEST_GROUP(MockTest)
{
    void teardown() _override
    {
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(MockTest, withNullPtr)
{
    mock("Example").expectOneCall("func").withParameter("value", 17);
    std::unique_ptr<Example> ptr(new Example);
    //CHECK_TRUE(ptr == nullptr);
    ptr->func(17); /* <--- Doesn't fail */
}

int main(int argc, char** argv) {
    return RUN_ALL_TESTS(argc, argv);
}
