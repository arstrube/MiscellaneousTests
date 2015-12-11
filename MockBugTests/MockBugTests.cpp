#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C"
{
    #include "MockBugCode.h"
}

void fp_mock(void) {
    mock().actualCall("fp");
}

TEST_GROUP(MockBug) {
    void setup(void) {
        mock().expectOneCall("Xyz_FirstMock");
        Mbc_Init();
    }
    void setCurrentCallback(fp_t fp_mock) {
        mock().disable();
        Mbc_Process();
        Mbc_SetCurrentCallback(fp_mock);
        mock().enable();
    }
    void teardown(void) {
        mock().checkExpectations();
        mock().clear();
    }
};

extern config_t* config;

TEST(MockBug, ConfigFp1IsValid)
{
    fp1_t save_pf = config->fp1;
    setCurrentCallback(&fp_mock); // TODO: Why does merely entering this method (!) corrupt config->fp1?
    mock().expectOneCall("fp");
    config->fp1 = save_pf;

    if(!config->fp1)
    {
        FAIL("Callback function is NULL!");
    }
    else
    {
        config->fp1(0, 0);
    }
}

TEST(MockBug, ConfigFp2IsValid)
{
    /*** Arrange ***/
    fp2_t save_fp = config->fp2;
    setCurrentCallback(&fp_mock); // TODO: Why does merely entering this method (!) corrupt config->fp2?
    mock().expectOneCall("fp");
    config->fp2 = save_fp;

    /*** Act ***/
    if(!config->fp2)
    {
        FAIL("Callback function is NULL!");
    }
    else
    {
        config->fp2(1);
    }

    /*** Assert ***/
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}

