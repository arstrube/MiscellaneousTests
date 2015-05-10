#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

/// Code to be tested

#define BUFFER_SIZE 13
typedef unsigned char byte;

bool readArray(byte*);
bool writeArray(const byte*);

struct dummy {
    dummy(int n = 0) : number(n) {}
    int number;
};

bool functionToBeTested(void) {
    dummy localDummy;
    const byte localArray[BUFFER_SIZE] = "Hello World!";
    bool result = readArray((byte*)&localDummy);
    if(5 == localDummy.number) result = writeArray(localArray);
    return result;
}

/// Mocks for other functions used by code to be tested

bool readArray(byte* data) {
	mock().actualCall("readArray").withOutputParameter("data",data);
	return mock().returnUnsignedIntValueOrDefault(false);
}

bool writeArray(const byte* data) {
	mock().actualCall("writeArray").withParameterOfType("byte[13]", "data", (const void*)data);
	return mock().returnUnsignedIntValueOrDefault(false);
}

/// An example comparator for the array [13] type

class Array_Comparator : public MockNamedValueComparator {
    virtual bool isEqual(const void* array1, const void* array2) {
    	for(int i=0; i<BUFFER_SIZE; i++) {
    		if(((byte*)array1)[i]!=((byte*)array2)[i]) return false;
    	}
        return true;
    }
    virtual SimpleString valueToString(const void* array) {
        return StringFrom((char*)array);
    }
};

/// The actual tests

TEST_GROUP(WeirdMock) {
    Array_Comparator comparator;
    void setup() {
        mock().installComparator("byte[13]", comparator);
    }
    void teardown() {
        mock().removeAllComparators();
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(WeirdMock, WeirdWithCallToWriteArray) {
    const dummy someDummy(5);
    byte expectedArray[BUFFER_SIZE] = "Hello World!";
	mock().expectOneCall("readArray")
          .withOutputParameterReturning("data",(void*)&someDummy,sizeof(someDummy))
		  .andReturnValue(true);
	mock().expectOneCall("writeArray")
          .withParameterOfType("byte[13]", "data", (void*)&expectedArray)
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
	return RUN_ALL_TESTS(ac, av);
}
