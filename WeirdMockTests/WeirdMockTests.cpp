#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

/// Code to be tested

#define BUFFER_SIZE 13
typedef unsigned char uint8;

bool readArray(uint8*);
bool writeArray(const uint8*);

struct dummy {
    dummy(int n = 0) : number(n) {}
    int number;
};

bool functionToBeTested(void) {
    dummy localDummy;
    const uint8 localArray[BUFFER_SIZE] = "Hello World!";
    bool result = readArray((uint8*)&localDummy);
    if(5 == localDummy.number) result = writeArray(localArray);
    return result;
}

/// Mocks for other functions used by code to be tested

bool readArray(uint8* data) {
	mock().actualCall("readArray").withOutputParameter("data",data);
	return mock().returnUnsignedIntValueOrDefault(false);
}

bool writeArray(const uint8* data) {
	mock().actualCall("writeArray").withParameterOfType("uint8[13]", "data", (const void*)data);
	return mock().returnUnsignedIntValueOrDefault(false);
}

/// An example comparator for the array [13] type

class Array_Comparator : public MockNamedValueComparator {
    virtual bool isEqual(const void* array1, const void* array2) {
    	bool isEqual = true;
    	for(int i=0; i<BUFFER_SIZE; i++) {
    		if(((uint8*)array1)[i]!=((uint8*)array2)[i]) isEqual = false;
    	}
        return isEqual;
    }
    virtual SimpleString valueToString(const void* array) {
        return StringFrom((char*)array);
    }
};

/// The actual tests

TEST_GROUP(WeirdMock) {
    Array_Comparator comparator;
    void setup() {
        mock().installComparator("uint8[13]", comparator);
    }
    void teardown() {
        mock().removeAllComparators();
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(WeirdMock, Weird) {
    const dummy someDummy(5);
    uint8 expectedArray[BUFFER_SIZE] = "Hello World!";
	mock().expectOneCall("readArray")
          .withOutputParameterReturning("data",(void*)&someDummy,sizeof(someDummy))
		  .andReturnValue(true);
	mock().expectOneCall("writeArray")
          .withParameterOfType("uint8[13]", "data", (void*)&expectedArray)
          .andReturnValue(true);
    
    CHECK(functionToBeTested());
}

/// CppUTest main function

int main(int ac, char** av)
{
	return RUN_ALL_TESTS(ac, av);
}
