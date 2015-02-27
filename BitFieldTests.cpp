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

static const boolean values[8][4] { 
    { TRUE, FALSE, FALSE, FALSE },
    { FALSE, TRUE, FALSE, FALSE },
    { FALSE, FALSE, TRUE, FALSE },
    { FALSE, FALSE, FALSE, TRUE },
    { FALSE, TRUE, TRUE, TRUE },
    { TRUE, FALSE, TRUE, TRUE },
    { TRUE, TRUE, FALSE, TRUE },
    { TRUE, TRUE, TRUE, FALSE },
};
    

class TestFixture {
public:
    Data_t data_st;
    Data_t* data_pst {&data_st};
    static uint8 idx;
    
    TestFixture()
    {
        data_st.field1_u16 = values[idx][0];
        data_st.field2_u16 = values[idx][1];
        data_st.field3_u16 = values[idx][2];
        data_st.field4_u16 = values[idx][3];
        
        mock().expectNCalls(4, "Bf_GetData").andReturnValue(data_pst);
    }
    
    void check_fields(void)
    {
        for (auto i : values[idx]) CHECK(Bf_IsFieldSet(i+1) == values[idx][i]);
    }
};

uint8 TestFixture::idx{0};

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
    TestFixture f;
    f.check_fields();
}
TEST(BitField, Field2_Set)
{
    TestFixture f;
    f.check_fields();
}
TEST(BitField, Field3_Set)
{
    TestFixture f;
    f.check_fields();
}
TEST(BitField, Field4_Set)
{
    TestFixture f;
    f.check_fields();
}
TEST(BitField, Field1_Clear)
{
    TestFixture f;
    f.check_fields();
}
TEST(BitField, Field2_Clear)
{
    TestFixture f;
    f.check_fields();
}
TEST(BitField, Field3_Clear)
{
    TestFixture f;
    f.check_fields();
}
TEST(BitField, Field4_Clear)
{
    TestFixture f;
    f.check_fields();
}

int main(int ac, char** av)
{
	return RUN_ALL_TESTS(ac, av);
}

