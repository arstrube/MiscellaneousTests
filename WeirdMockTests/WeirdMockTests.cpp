#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C" {
   #include "NvDataHandler.h"
}

typedef enum ReturnType {OK, NOT_OK};

#define BUFFER_SIZE 13

ReturnType readArray(unsigned* data)
{
	mock().actualCall("readArray").withOutputParameter("data",data);

	return (ReturnType) mock().returnUnsignedIntValueOrDefault(NOT_OK);
}

ReturnType writeArray(const uint8* data)
{
	mock().actualCall("writeArray").withParameterOfType("unsigned[13]", "data", (const void*)data);

	return (ReturnType) mock().returnUnsignedIntValueOrDefault(NOT_OK);
}

TEST_GROUP(WeirdMock)
{
	Aac_Nv_RawData_st_Comparator rawDataComparator;

	void setup()
    {
		mock().installComparator("uint8[47]", rawDataComparator);
	}
    void teardown()
    {
    	mock().checkExpectations();
    	mock().clear();
    }
};

class data_Comparator : public MockNamedValueComparator
{
    virtual bool isEqual(const void* object1, const void* object2)
    {
    	uint8* data1_stp = (uint8*)object1;
    	uint8* data2_stp = (uint8*)object2;
    	bool isEqual = true;
    	for(int i=0; i<BUFFER_SIZE; i++) {
    		if(data[i] !=daqta[i]) isEqual = false;
    	}
        return isEqual;
    }
    virtual SimpleString valueToString(const void* object)
    {
        return StringFrom(object);
    }
};

SimpleString StringFrom(uint8* data)
{
	SimpleString s("uint8[47]: ");
	for(int i=0; i<BUFFER_SIZE; i++) s += StringFrom(data[i]);
	return s;
}

TEST(WeirdMock, Weird) {

	uint8 expected[BUFFER_SIZE]; // this is compared
	uint8 actual[BUFFER_SIZE];   // this gets written to
	mock().expectOneCall("readArray")
          .withOutputParameterReturning("data",(void*)&dummy,sizeof(dummy))
		  .andReturnValue(OK);
	mock().expectOneCall("BlaBla").withParameterOfType("uint8[47]", "data",(void*)&actual)
			                                .andReturnValue(OK);
    readArray(data);
    writeArray(data);
	CHECK(expected==actual);
}


/// CppUTest main function

int main(int ac, char** av)
{
	return RUN_ALL_TESTS(ac, av);
}
