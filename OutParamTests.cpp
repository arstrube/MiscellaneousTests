#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "CppUTest/PlatformSpecificFunctions.h"

extern "C"
{
}

struct Data
{
    Data(int value) : value_(value) {}
    int value_;
};

void Callee_setData(Data* data, size_t size)
{
	mock().actualCall("Callee_setData")
	      .withOutputParameter("data", data)
          .withParameter("size", size);
}

int Caller_getData(void)
{
    Data data(0);
    Callee_setData(&data, sizeof(Data));
    return data.value_;
}

class Data_Comparator : public MockNamedValueComparator
{
public:
	virtual bool isEqual(const void* object1, const void* object2)
	{
		return ((Data*)object1)->value_ == ((Data*)object2)->value_;
	}
	virtual SimpleString valueToString(const void* object)
	{
		return StringFrom(((Data*)object)->value_);
	}
};

static Data_Comparator cmp;

SimpleString StringFrom(const Data d)
{
	SimpleString result;
	result = SimpleString("\n value_: ") + StringFrom(d.value_);
    return result;
}

TEST_GROUP(Caller_getData)
{
};

TEST(Caller_getData, withOutputParameter_noSize)
{
	const int expected = 17;
	int actual;
	Data data(17);
	mock().installComparator("Data*", cmp);
	mock().expectOneCall("Callee_setData")
          .withOutputParameterReturning("data", (void*)&data, sizeof(data))
	      .withParameter("size", sizeof(Data));
	actual = Caller_getData();
	LONGS_EQUAL(expected, actual);
	mock().checkExpectations();
	mock().removeAllComparators();
	mock().clear();
}

TEST_GROUP(OutputParameter)
{
    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
};
TEST(OutputParameter, ChangeCharArrayInPlace)
{
    char before[] = "abcde";
    const char after[] = "edcga";
    mock().expectOneCall("foo").withOutputParameterReturning("bar", after, sizeof(char)*5);
    mock().actualCall("foo").withOutputParameter("bar", before);
    STRCMP_EQUAL(before, "edcga");
}
TEST(OutputParameter, ChangeIntArrayInPlace)
{
    int before[] = {5,4,3,2,1};
    const int after[] = {1,2,3,4,5};
    mock().expectOneCall("foo").withOutputParameterReturning("bar", after, sizeof(int)*5);
    mock().actualCall("foo").withOutputParameter("bar", before);
    for(int i=0; i<5; i++) LONGS_EQUAL(i+1, before[i]);
}
TEST(OutputParameter, IntIOParameter)
{
    int before = 783;
    const int after = -5809;
    mock().expectOneCall("foo")
          .withParameter("bar", (int)before)
          .withOutputParameterReturning("bar", &after, sizeof(int));
    mock().actualCall("foo")
         .withParameter("bar", before)
         .withOutputParameter("bar", &before);
    LONGS_EQUAL(after, before);
}

/** Gavin Lambert's example (@uecasm) */

#include <stdint.h>

uint16_t my_function(uint8_t x, uint16_t *y)
{
    MockActualCall& call = mock().actualCall("my_function")
        .withParameter("x", x)
        .withParameter("y", *y);
    if (y) { call.withOutputParameter("y", y); }
    return call.returnUnsignedIntValue();
}
TEST(OutputParameter, test_my_function)
{
    uint16_t result;
    uint16_t before = 33;
    const uint16_t after = 777;
    mock().expectOneCall("my_function")
          .withParameter("x", 3)
          .withParameter("y", before)
          .withOutputParameterReturning("y", &after, sizeof(before))
          .andReturnValue(0u);
    result = my_function(3, &before);
    LONGS_EQUAL(after, before);
    LONGS_EQUAL(0, result);
}

int main(int ac, char** av)
{
	return RUN_ALL_TESTS(ac, av);
}

