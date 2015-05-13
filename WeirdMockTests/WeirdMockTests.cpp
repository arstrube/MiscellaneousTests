#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/MockSupport.h"
#include "CppUTestExt/MockSupportPlugin.h"

/// General type definitions

typedef unsigned char byte;

/// A type to make given-size array *really* type-safe

typedef struct ByteArray13 {
    byte data[13];
} ByteArray13;

/// Code to be tested

#define BUFFER_SIZE 13

bool readArray(byte*);
bool writeArray(const byte*);

struct dummy {
    dummy(int n = 0) : number(n) {}
    int number;
};

bool functionToBeTested(void) {
    dummy localDummy;
    byte localArray[BUFFER_SIZE] = { "Hello World!" };
    bool result = readArray((byte*)&localDummy);
    if(5 == localDummy.number) result = writeArray((byte*) &localArray);
    return result;
}

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
        mock().installComparator("ByteArray13", comparator); /* move this to main() comparator not found */
    }
    void teardown() {
        /* remove these and CRASH on failure */
        // mock().checkExpectations();
        // mock().removeAllComparators();
        // mock().clear(); /* remove this and CRASH */
    }
};

TEST(WeirdMock, WeirdWithCallToWriteArray) {
    const dummy someDummy(4);
    ByteArray13 expectedArray = { "Hello World!" };
	mock().expectOneCall("readArray")
          .withOutputParameterReturning("data",(void*)&someDummy,sizeof(someDummy))
		  .andReturnValue(true);
	mock().expectOneCall("writeArray")
          .withParameterOfType("ByteArray13", "data", (void*)&expectedArray)
          .andReturnValue(true);
    
    CHECK(functionToBeTested());
}

TEST(WeirdMock, WeirdWithoutCallToWriteArray) {
    const dummy someDummy;
    mock().expectOneCall("readArray")
    .withOutputParameterReturning("data",(void*)&someDummy,sizeof(someDummy))
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
