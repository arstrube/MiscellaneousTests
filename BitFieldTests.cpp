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
    
    boolean expected[4][4] { 
        { TRUE, FALSE, FALSE, FALSE },
        { FALSE, TRUE, FALSE, FALSE },
        { FALSE, FALSE, TRUE, FALSE },
        { FALSE, FALSE, FALSE, TRUE },
    };
    
    TestFixture(uint8 f1, uint8 f2, uint8 f3, uint8 f4) : data_st {f1, f2,f3,f4} {}
        
    void check_field(uint8 idx, boolean t)
    {
        for (auto i : expected[idx-1]) CHECK(Bf_IsFieldSet(i+1) == (t == expected[idx-1][i]));
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
    f.check_field(1, TRUE);
}

TEST(BitFieldSet, Field2_Set)
{
    f.data_st.field2_u16 = 2;
    f.check_field(2, TRUE);
}

TEST(BitFieldSet, Field3_Set)
{
    f.data_st.field3_u16 = 1;
    f.check_field(3, TRUE);
}

TEST(BitFieldSet, Field4_Set)
{
    f.data_st.field4_u16 = 1;
    f.check_field(4, TRUE);
}

TEST_GROUP(BitFieldClear)
{
    TestFixture f {1,3,1,1};
    
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
    f.check_field(1, FALSE);
}

TEST(BitFieldClear, Field2_Clear)
{
    f.data_st.field2_u16 = 0;
    f.check_field(2, FALSE);
}

TEST(BitFieldClear, Field3_Clear)
{
    f.data_st.field3_u16 = 0;
    f.check_field(3, FALSE);
}

TEST(BitFieldClear, Field4_Clear)
{
    f.data_st.field4_u16 = 0;
    f.check_field(4, FALSE);
}

int main(int ac, char** av)
{
	return RUN_ALL_TESTS(ac, av);
}

