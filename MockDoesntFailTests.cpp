#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/MockSupport.h"
#include "CppUTestExt/MockSupportPlugin.h"

TEST_GROUP(GoodTest) {
    void teardown() _override {
    }
};

TEST_GROUP(OkayTest) {
    void teardown() _override {
        mock().checkExpectations();
        mock().clear();
    }
};

TEST_GROUP(BadTest) {
    void teardown() _override {
        mock().clear();
    }
};

TEST(GoodTest, shouldFail) {
    mock().expectOneCall("doesntHappen");
}

TEST(OkayTest, shouldFail) {
    mock().expectOneCall("doesntHappen");
}

TEST(BadTest, shouldFail) {
    mock().expectOneCall("doesntHappen");
}

MockSupportPlugin mockPlugin;

int main(int ac, char** av) {
    TestRegistry::getCurrentRegistry()->installPlugin(&mockPlugin);
    return RUN_ALL_TESTS(ac, av);
}
