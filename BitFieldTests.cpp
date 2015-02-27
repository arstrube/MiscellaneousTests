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
        
    void check_set(uint8 idx)
    {
        data_st.field1_u16 = idx;
        for (auto i : expected[idx-1]) CHECK(Bf_IsFieldSet(i+1) == expected[idx][i]);
    }
    void check_clear(uint8 idx)
    {
        data_st.field1_u16 = idx;
        for (auto i : expected[idx-1]) CHECK(!Bf_IsFieldSet(i+1) == expected[idx][i]);
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
    f.check_set(1);
}

TEST(BitFieldSet, Field2_Set)
{
    f.check_set(2);
}

TEST(BitFieldSet, Field3_Set)
{
    f.check_set(3);
}

TEST(BitFieldSet, Field4_Set)
{
    f.check_set(4);
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
    f.check_clear(1);
}

TEST(BitFieldClear, Field2_Clear)
{
    f.check_clear(2);
}

TEST(BitFieldClear, Field3_Clear)
{
    f.check_clear(3);
}

TEST(BitFieldClear, Field4_Clear)
{
    f.check_clear(4);
}

int main(int ac, char** av)
{
	return RUN_ALL_TESTS(ac, av);
}

