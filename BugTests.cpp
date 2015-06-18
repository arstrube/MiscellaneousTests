#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
//--------------------------------------------------------------------------------------------
struct Simple
{
    Simple()
    {
        m_data = new int;
    }
    ~Simple()
    {
        delete m_data;
    }
private:
    int * m_data;
};
//--------------------------------------------------------------------------------------------
TEST_GROUP(Simple) {};

TEST(Simple, WillItFail)
{
    Simple source, destination;

    mock().expectOneCall("foo").withOutputParameterReturning("simple", &source, sizeof(source));
    mock().actualCall("foo").withOutputParameter("simple", &destination);

    mock().checkExpectations();
    mock().clear();
}
//--------------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
