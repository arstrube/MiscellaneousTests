#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C"
{
    #include "BitFieldTests_c.h"
}

Data_t * Bf_GetData() 
{
    mock().actualCall("Bf_GetData");
    return (Data_t*) mock().returnPointerValueOrDefault(0);
}

class TestFixture {
public:
    Data_t data_st;
    
    TestFixture(boolean v1, boolean v2, boolean v3, boolean v4) : data_st {v1, v2, v3, v4}
    {
        mock().expectNCalls(1, "Bf_GetData").andReturnValue(&data_st);
    }
};

TEST_GROUP(BitField)
{
    void teardown() override
    {
	    mock().checkExpectations();
	    mock().clear();
    }
};

TEST(BitField, Field1_Set)
{
    TestFixture f{1, 0, 0, 0};
    CHECK_TRUE(Bf_IsFieldSet(1));
}

TEST(BitField, Field2_Set)
{
    TestFixture f{0, 2, 0, 0};
    CHECK_TRUE(Bf_IsFieldSet(2));
}

TEST(BitField, Field3_Set)
{
    TestFixture f{0, 0, 1, 0};
    CHECK_TRUE(Bf_IsFieldSet(3));
}

TEST(BitField, Field4_Set)
{
    TestFixture f{0, 0, 0, 1};
    CHECK_TRUE(Bf_IsFieldSet(4));
}

TEST(BitField, Field1_Clear)
{
    TestFixture f{0, 3, 1, 1};
    CHECK_FALSE(Bf_IsFieldSet(1));
}

TEST(BitField, Field2_Clear)
{
    TestFixture f{1, 0, 1, 1};
    CHECK_FALSE(Bf_IsFieldSet(2));
}

TEST(BitField, Field3_Clear)
{
    TestFixture f{1, 3, 0, 1};
    CHECK_FALSE(Bf_IsFieldSet(3));
}

TEST(BitField, Field4_Clear)
{
    TestFixture f{1, 3, 1, 0};
    CHECK_FALSE(Bf_IsFieldSet(4));
}

int main(int ac, char** av)
{
	return RUN_ALL_TESTS(ac, av);
}

