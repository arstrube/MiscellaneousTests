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

TEST_GROUP(BitFieldSet)
{
    Data_t testdata_st {0,0,0,0};
    Data_t* testdata_pst {&testdata_st};
    
    void setup() override
    {
        mock().expectNCalls(4, "Bf_GetData").andReturnValue(testdata_pst);
    }
    void teardown() override
    {
	    mock().checkExpectations();
	    mock().clear();
    }
};

TEST(BitFieldSet, Field1_Set)
{
    testdata_st.field1_u16 = 1;
    CHECK( Bf_IsFieldSet(1));
    CHECK(!Bf_IsFieldSet(2));
    CHECK(!Bf_IsFieldSet(3));
    CHECK(!Bf_IsFieldSet(4));
}

TEST(BitFieldSet, Field2_Set)
{
    testdata_st.field2_u16 = 2;
    CHECK(!Bf_IsFieldSet(1));
    CHECK( Bf_IsFieldSet(2));
    CHECK(!Bf_IsFieldSet(3));
    CHECK(!Bf_IsFieldSet(4));
}

TEST(BitFieldSet, Field3_Set)
{
    testdata_st.field3_u16 = 1;
    CHECK(!Bf_IsFieldSet(1));
    CHECK(!Bf_IsFieldSet(2));
    CHECK( Bf_IsFieldSet(3));
    CHECK(!Bf_IsFieldSet(4));
}

TEST(BitFieldSet, Field4_Set)
{
    testdata_st.field4_u16 = 1;
    CHECK(!Bf_IsFieldSet(1));
    CHECK(!Bf_IsFieldSet(2));
    CHECK(!Bf_IsFieldSet(3));
    CHECK( Bf_IsFieldSet(4));
}

TEST_GROUP(BitFieldClear)
{
    Data_t testdata_st {1,3,1,1};
    Data_t* testdata_pst {&testdata_st};
    
    void setup() override
    {
        mock().expectNCalls(4, "Bf_GetData").andReturnValue(testdata_pst);
    }
    void teardown() override
    {
	    mock().checkExpectations();
	    mock().clear();
    }
};

TEST(BitFieldClear, Field1_Clear)
{
    testdata_st.field1_u16 = 0;
    CHECK_FALSE( Bf_IsFieldSet(1));
    CHECK_FALSE(!Bf_IsFieldSet(2));
    CHECK_FALSE(!Bf_IsFieldSet(3));
    CHECK_FALSE(!Bf_IsFieldSet(4));
}

TEST(BitFieldClear, Field2_Clear)
{
    testdata_st.field2_u16 = 0;
    CHECK_FALSE(!Bf_IsFieldSet(1));
    CHECK_FALSE( Bf_IsFieldSet(2));
    CHECK_FALSE(!Bf_IsFieldSet(3));
    CHECK_FALSE(!Bf_IsFieldSet(4));
}

TEST(BitFieldClear, Field3_Clear)
{
    testdata_st.field3_u16 = 0;
    CHECK_FALSE(!Bf_IsFieldSet(1));
    CHECK_FALSE(!Bf_IsFieldSet(2));
    CHECK_FALSE( Bf_IsFieldSet(3));
    CHECK_FALSE(!Bf_IsFieldSet(4));
}

TEST(BitFieldClear, Field4_Clear)
{
    testdata_st.field4_u16 = 0;
    CHECK_FALSE(!Bf_IsFieldSet(1));
    CHECK_FALSE(!Bf_IsFieldSet(2));
    CHECK_FALSE(!Bf_IsFieldSet(3));
    CHECK_FALSE( Bf_IsFieldSet(4));
}

int main(int ac, char** av)
{
	return RUN_ALL_TESTS(ac, av);
}

