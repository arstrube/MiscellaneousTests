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

static const boolean expected[4][4] { 
    { TRUE, FALSE, FALSE, FALSE },
    { FALSE, TRUE, FALSE, FALSE },
    { FALSE, FALSE, TRUE, FALSE },
    { FALSE, FALSE, FALSE, TRUE },
};
    

class TestFixture {
public:
    Data_t data_st;
    Data_t* data_pst {&data_st};
    
    TestFixture(uint8 f1, uint8 f2, uint8 f3, uint8 f4) : data_st {f1, f2, f3, f4}
    {
        mock().expectNCalls(4, "Bf_GetData").andReturnValue(data_pst);
    }        
    void check_field(uint8 idx, boolean t)
    {
        for (auto i : expected[idx-1]) CHECK(Bf_IsFieldSet(i+1) == (t == expected[idx-1][i]));
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
    f.check_field(1, TRUE);
}
TEST(BitField, Field2_Set)
{
    TestFixture f{0, 2, 0, 0};
    f.check_field(2, TRUE);
}
TEST(BitField, Field3_Set)
{
    TestFixture f{0, 0, 1, 0};
    f.check_field(3, TRUE);
}
TEST(BitField, Field4_Set)
{
    TestFixture f{0, 0, 0, 1};
    f.check_field(4, TRUE);
}
TEST(BitField, Field1_Clear)
{
    TestFixture f {0,3,1,1};
    f.check_field(1, FALSE);
}
TEST(BitField, Field2_Clear)
{
    TestFixture f {1,0,1,1};
    f.check_field(2, FALSE);
}
TEST(BitField, Field3_Clear)
{
    TestFixture f {1,1,0,1};
    f.check_field(3, FALSE);
}
TEST(BitField, Field4_Clear)
{
    TestFixture f {1,1,1,0};
    f.check_field(4, FALSE);
}

int main(int ac, char** av)
{
	return RUN_ALL_TESTS(ac, av);
}

