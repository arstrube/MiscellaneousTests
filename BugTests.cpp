#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

//--------------------------------------------------------------------------------------------
struct Simple {
    Simple() {
        m_data = new int;
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

struct Floaty {
    Floaty() {
        m_data = new float;
    }
    Floaty& operator=(const Floaty& rhs) {
        *m_data = *rhs.m_data;
        return *this;
    }
    ~Floaty() {
        delete m_data;
    }
    float * m_data;
};

struct Simple2 {
    int m_data;
};

template <class T>
class Copier : public MockNamedValueCopier {
public:
    virtual void copy(void* to, const void* from)
    {
         *(T*)to = *((T*)from);
    }
};
//--------------------------------------------------------------------------------------------
TEST_GROUP(Copier) {};

TEST(Copier, Simple_WillItFail)
{
    Copier<Simple> copier;
    mock().installCopier("Simple", copier);
    Simple source, destination;
    *source.m_data = 5;
    *destination.m_data = 7;
    mock().expectOneCall("foo").withOutputParameterOfTypeReturning("Simple", "simple", &source);
    mock().actualCall("foo").withOutputParameterOfType("Simple", "simple", &destination);

    mock().checkExpectations();
    LONGS_EQUAL(5, *destination.m_data);

    mock().clear();
    mock().removeAllHandlers();
}
TEST(Copier, Floaty_WillItFail)
{
    Copier<Floaty> copier;
    mock().installCopier("Floaty", copier);
    Simple source, destination;
    *source.m_data = 5.777;
    *destination.m_data = 7;
    mock().expectOneCall("foo").withOutputParameterOfTypeReturning("Floaty", "floaty", &source);
    mock().actualCall("foo").withOutputParameterOfType("Floaty", "floaty", &destination);

    mock().checkExpectations();
    LONGS_EQUAL(5.777, *destination.m_data);

    mock().clear();
    mock().removeAllHandlers();
}
TEST(Copier, Simple2_WillItFail)
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
