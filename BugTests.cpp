#include <string>

#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

//--------------------------------------------------------------------------------------------
class MyReference
{
public:
    MyReference():
    m_name("Hello")
    {
    }
    ~MyReference(){}

private:
    // If I remove this field, it works as expected
    std::string m_name; // Double freed!!!??
};

//--------------------------------------------------------------------------------------------
class ReturnReference
{
public:
    ReturnReference(){}
    virtual ~ReturnReference(){}

    virtual bool returnReference(MyReference& ref)
    {
        ref = m_ref;
        return true;
    }
private:
    MyReference m_ref;
};

//--------------------------------------------------------------------------------------------
class ReturnReferenceMock:
public ReturnReference
{
public:
    ReturnReferenceMock(){}
    ~ReturnReferenceMock(){}

    bool returnReference(MyReference& ref)
    {
        return mock().actualCall("returnReference").onObject(this).
        withOutputParameter("ref", &ref).returnIntValue();
    }
};

//--------------------------------------------------------------------------------------------
class UseReturnReference
{
public:
    UseReturnReference(ReturnReference* returnReference) :
    m_pReturnReference(returnReference)
    {
    }

    ~UseReturnReference()
    {
        delete m_pReturnReference;
    }

    void useReturnReference()
    {
        MyReference ref;
        m_pReturnReference->returnReference(ref);
    }

private:
    ReturnReference* m_pReturnReference;
};

//--------------------------------------------------------------------------------------------
TEST_GROUP(TestReferenceMock)
{

    TEST_SETUP()
    {
        // XXX: Double free!
        //MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
    }

    TEST_TEARDOWN()
    {
        mock().clear();
        MemoryLeakWarningPlugin::turnOnNewDeleteOverloads();
    }
};

TEST(TestReferenceMock, willItFail)
{
    ReturnReferenceMock* retRefMock = new ReturnReferenceMock();
    UseReturnReference useRef(retRefMock);
    MyReference* ref = new MyReference();

    mock().expectOneCall("returnReference").onObject(retRefMock).
    withOutputParameterReturning("ref", ref, sizeof(*ref)).
    andReturnValue(true);

    useRef.useReturnReference();

    mock().checkExpectations();

    // Not doing this reports a memory leak as expected!
    delete ref;
}

TEST(TestReferenceMock, willItFail2)
{
    ReturnReferenceMock* retRefMock = new ReturnReferenceMock();
    UseReturnReference useRef(retRefMock);
    MyReference ref;

    mock().expectOneCall("returnReference").onObject(retRefMock).
    withOutputParameterReturning("ref", &ref, sizeof(ref)).
    andReturnValue(true);

    useRef.useReturnReference();

    mock().checkExpectations();
}

//--------------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    // Run the tests
    return CommandLineTestRunner::RunAllTests(argc, argv);
}