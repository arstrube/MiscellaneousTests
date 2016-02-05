#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <memory>

#if 0
class Example {
public:
    void func(int value) {
        mock("Example").actualCall("func").withParameter("value", value);
    }
};
#else
class Example
{
private:
   // int m_value;
public:
    void func(int )
    {
        // m_value = value;
    }
    // ...
};
#endif
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
    std::unique_ptr<Example> ptr = nullptr;
    //std::unique_ptr<Example> ptr(new Example);
    CHECK_TRUE(ptr == 0);
    ptr->func(17); /* <--- Doesn't fail */
}

int main(int argc, char** argv) {
    return RUN_ALL_TESTS(argc, argv);
}
