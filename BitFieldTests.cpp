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
    Data_t* data_pst {&data_st};
    
    TestFixture(uint8 f1, uint8 f2, uint8 f3, uint8 f4) :
        data_st {f1, f2,f3,f4}
        {}
        
    void check_all_fields(boolean f1, boolean f2, boolean f3, boolean f4)
    {
        CHECK(f1 == Bf_IsFieldSet(1));
        CHECK(f2 == Bf_IsFieldSet(2));
        CHECK(f3 == Bf_IsFieldSet(3));
        CHECK(f4 == Bf_IsFieldSet(4));
    }
};

TEST_GROUP(BitFieldSet)
{
    TestFixture f{0,0,0,0};
    
    void setup() override
    {
        mock().expectNCalls(4, "Bf_GetData").andReturnValue(f.data_pst);
    }
    void teardown() override
    {
	    mock().checkExpectations();
	    mock().clear();
    }
};

TEST(BitFieldSet, Field1_Set)
{
    f.data_st.field1_u16 = 1;
    f.check_all_fields(TRUE, FALSE, FALSE, FALSE);
}

TEST(BitFieldSet, Field2_Set)
{
    f.data_st.field2_u16 = 2;
    f.check_all_fields(FALSE, TRUE, FALSE, FALSE);
}

TEST(BitFieldSet, Field3_Set)
{
    f.data_st.field3_u16 = 1;
    f.check_all_fields(FALSE, FALSE, TRUE, FALSE);
}

TEST(BitFieldSet, Field4_Set)
{
    f.data_st.field4_u16 = 1;
    f.check_all_fields(FALSE, FALSE, FALSE, TRUE);
}

TEST_GROUP(BitFieldClear)
{
    TestFixture f {1,3,1,1};;
    
    void setup() override
    {
        mock().expectNCalls(4, "Bf_GetData").andReturnValue(f.data_pst);
    }
    void teardown() override
    {
	    mock().checkExpectations();
	    mock().clear();
    }
};

TEST(BitFieldClear, Field1_Clear)
{
    f.data_st.field1_u16 = 0;
    f.check_all_fields(FALSE, TRUE, TRUE, TRUE);
}

TEST(BitFieldClear, Field2_Clear)
{
    f.data_st.field2_u16 = 0;
    f.check_all_fields(TRUE, FALSE, TRUE, TRUE);
}

TEST(BitFieldClear, Field3_Clear)
{
    f.data_st.field3_u16 = 0;
    f.check_all_fields(TRUE, TRUE, FALSE, TRUE);
}

TEST(BitFieldClear, Field4_Clear)
{
    f.data_st.field4_u16 = 0;
    f.check_all_fields(TRUE, TRUE, TRUE, FALSE);
}

int main(int ac, char** av)
{
	return RUN_ALL_TESTS(ac, av);
}

