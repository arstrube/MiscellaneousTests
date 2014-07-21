#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/TestOutput.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTest/TestTestingFixture.h"
#include "CppUTestExt/OrderedTest.h"

static int totalTests = 0;

TEST_GROUP(TestOrderedTest)
{
    TestTestingFixture* fixture;

    OrderedTestShell orderedTest;
    OrderedTestShell orderedTest2;
    OrderedTestShell orderedTest3;
    ExecFunctionTestShell normalTest;
    ExecFunctionTestShell normalTest2;
    ExecFunctionTestShell normalTest3;

    OrderedTestShell* orderedTestCache;
    void setup()
    {
        orderedTestCache = OrderedTestShell::getOrderedTestHead();
        OrderedTestShell::setOrderedTestHead(0);

        fixture = new TestTestingFixture();
        fixture->registry_->unDoLastAddTest();
        
        totalTests++;
    }

    void teardown()
    {
        delete fixture;
        OrderedTestShell::setOrderedTestHead(orderedTestCache);
    }

    void InstallOrderedTest(OrderedTestShell& test, int level)
    {
        OrderedTestInstaller(test, "testgroup", "testname", __FILE__, __LINE__, level);
    }

    void InstallNormalTest(UtestShell& test)
    {
        TestInstaller(test, "testgroup", "testname", __FILE__, __LINE__);
    }

    UtestShell* firstTest()
    {
        return fixture->registry_->getFirstTest();
    }

    UtestShell* secondTest()
    {
        return fixture->registry_->getFirstTest()->getNext();
    }
};

TEST(TestOrderedTest, TestInstallerSetsFields)
{
    OrderedTestInstaller(orderedTest, "testgroup", "testname", "this.cpp", 10, 5);
    STRCMP_EQUAL("testgroup", orderedTest.getGroup().asCharString());
    STRCMP_EQUAL("testname", orderedTest.getName().asCharString());
    STRCMP_EQUAL("this.cpp", orderedTest.getFile().asCharString());
    LONGS_EQUAL(10, orderedTest.getLineNumber());
    LONGS_EQUAL(5, orderedTest.getLevel());
}

TEST(TestOrderedTest, InstallOneText)
{
    InstallOrderedTest(orderedTest, 5);
    CHECK(firstTest() == &orderedTest);
}

TEST(TestOrderedTest, OrderedTestsAreLast)
{
    InstallNormalTest(normalTest);
    InstallOrderedTest(orderedTest, 5);
    CHECK(firstTest() == &normalTest);
    CHECK(secondTest() == &orderedTest);
}

TEST(TestOrderedTest, TwoTestsAddedInReverseOrder)
{
    InstallOrderedTest(orderedTest, 5);
    InstallOrderedTest(orderedTest2, 3);
    CHECK(firstTest() == &orderedTest2);
    CHECK(secondTest() == &orderedTest);
}

TEST(TestOrderedTest, TwoTestsAddedInOrder)
{
    InstallOrderedTest(orderedTest2, 3);
    InstallOrderedTest(orderedTest, 5);
    CHECK(firstTest() == &orderedTest2);
    CHECK(secondTest() == &orderedTest);
}

TEST(TestOrderedTest, MultipleOrderedTests)
{
    InstallNormalTest(normalTest);
    InstallOrderedTest(orderedTest2, 3);
    InstallNormalTest(normalTest2);
    InstallOrderedTest(orderedTest, 5);
    InstallNormalTest(normalTest3);
    InstallOrderedTest(orderedTest3, 7);

    UtestShell * firstOrderedTest = firstTest()->getNext()->getNext()->getNext();
    CHECK(firstOrderedTest == &orderedTest2);
    CHECK(firstOrderedTest->getNext() == &orderedTest);
    CHECK(firstOrderedTest->getNext()->getNext() == &orderedTest3);
}

TEST(TestOrderedTest, MultipleOrderedTests2)
{
    InstallOrderedTest(orderedTest, 3);
    InstallOrderedTest(orderedTest2, 1);
    InstallOrderedTest(orderedTest3, 2);

    CHECK(firstTest() == &orderedTest2);
    CHECK(secondTest() == &orderedTest3);
    CHECK(secondTest()->getNext() == &orderedTest);

}

TEST_GROUP(TestOrderedTestMacros)
{
    void setup()
    {
        totalTests++;
    }
};

static int testNumber = 0;

TEST(TestOrderedTestMacros, NormalTest)
{
    CHECK(testNumber == 0);
    testNumber++;
}

TEST_ORDERED(TestOrderedTestMacros, Test2, 2)
{
	CHECK(testNumber == 2);
	testNumber++;
}

TEST_ORDERED(TestOrderedTestMacros, Test1, 1)
{
	CHECK(testNumber == 1);
	testNumber++;
}

TEST_ORDERED(TestOrderedTestMacros, Test4, 4)
{
    CHECK(testNumber == 4);
    testNumber++;
}

TEST_ORDERED(TestOrderedTestMacros, Test3, 3)
{
    CHECK(testNumber == 3);
    testNumber++;
}

int main(int ac, char** av)
{
    int result = CommandLineTestRunner::RunAllTests(ac, av);
    CHECK(12 == totalTests);
    return result;
}
