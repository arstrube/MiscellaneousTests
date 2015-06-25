#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

//--------------------------------------------------------------------------------------------
struct Simple {
    Simple() {
        m_data = new int;
    }
    Simple(const Simple& rhs) {
        m_data = new int;
        *m_data = *rhs.m_data;
    }
    Simple& operator=(const Simple& rhs) {
        *m_data = *rhs.m_data;
        return *this;
    }
    ~Simple() {
        delete m_data;
    }
    int * m_data;
};

struct Simple2 {
    int m_data;
};

class SimpleComparator : public MockNamedValueCopier {
public:
    virtual bool isEqual(const void* object1, const void* object2)
    {
        return object1 == object2;
    }
    virtual SimpleString valueToString(const void* object)
    {
        return StringFrom(((Simple*)object)->m_data);
    }
    virtual void* copy(const void* to, const void* from)
    {
        Simple* ret = (Simple*)to;
        *ret = *((Simple*)from);
        return (void*)ret;
    }
};
//--------------------------------------------------------------------------------------------
TEST_GROUP(Simple) {};

TEST(Simple, WillItFail)
{
    SimpleComparator comparator;
    mock().installComparator("Simple", comparator);
    Simple source, destination;
    *source.m_data = 5;
    *destination.m_data = 7;
    mock().expectOneCall("foo").withOutputParameterOfTypeReturning("Simple", "simple", &source);
    mock().actualCall("foo").withOutputParameterOfType("Simple", "simple", &destination);

    mock().checkExpectations();
    LONGS_EQUAL(5, *destination.m_data);

    mock().clear();
    mock().removeAllComparators();
}
TEST(Simple, WillItFail2)
{
    Simple2 source, destination;
    source.m_data = 5;
    destination.m_data = 7;
    mock().expectOneCall("foo").withOutputParameterReturning("simple", &source, sizeof(source));
    mock().actualCall("foo").withOutputParameter("simple", &destination);

    mock().checkExpectations();
    LONGS_EQUAL(5, destination.m_data);

    mock().clear();
}
//--------------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
