#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/MockSupport.h"
#include "CppUTestExt/MockSupportPlugin.h"

extern "C" {
    #include "ArrayTypes.h"
}

struct TestDummy : public dummy {
    TestDummy(int n = 0) {
        number = n;
    }
};



/// An example comparator for the ByteArray13 type

class ByteArray13_Comparator : public MockNamedValueComparator {
    virtual bool isEqual(const void* array1, const void* array2) {
        for(int i=0; i<13; i++) {
            if(((ByteArray13*)array1)->data[i]!=((ByteArray13*)array2)->data[i]) return false;
        }
        return true;
    }
    virtual SimpleString valueToString(const void* array) {
        return StringFrom((char*)array);
    }
};

/// Mocks for other functions used by code to be tested

bool readArray(byte* data) {
	mock().actualCall("readArray").withOutputParameter("data",data);
	return mock().returnUnsignedIntValueOrDefault(false);
}

bool writeArray(const byte* data) {
	mock().actualCall("writeArray").withParameterOfType("ByteArray13", "data", (const void*)data);
	return mock().returnUnsignedIntValueOrDefault(false);
}

/// The actual tests

TEST_GROUP(WeirdMock) {
    ByteArray13_Comparator comparator;
    void setup() {
        mock().installComparator("ByteArray13", comparator);
    }
    void teardown() {
        mock().checkExpectations();
        mock().removeAllComparators();
        mock().clear();
    }
};

TEST(WeirdMock, WeirdWithCallToWriteArray) {
    const TestDummy testDummy(5);
    ByteArray13 expectedArray = { "Hello World!" };
	mock().expectOneCall("readArray")
          .withOutputParameterReturning("data",(void*)&testDummy,sizeof(testDummy))
		  .andReturnValue(true);
	mock().expectOneCall("writeArray")
          .withParameterOfType("ByteArray13", "data", (void*)&expectedArray)
          .andReturnValue(true);
    
    CHECK(functionToBeTested());
}

TEST(WeirdMock, WeirdWithoutCallToWriteArray) {
    const TestDummy testDummy;
    mock().expectOneCall("readArray")
    .withOutputParameterReturning("data",(void*)&testDummy,sizeof(testDummy))
		  .andReturnValue(true);
    
    CHECK(functionToBeTested());
}

/// CppUTest main function

int main(int ac, char** av)
{
    MockSupportPlugin mockPlugin;
    TestRegistry::getCurrentRegistry()->installPlugin(&mockPlugin);
    return RUN_ALL_TESTS(ac, av);
}
