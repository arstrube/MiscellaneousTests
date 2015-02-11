/** This test demonstrates how to use a mock with an output parameter, when just one
 *  field of the otherwise inaccessible struct needs to be manipulated.
 */

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C"
{
    #include "MockPartOut.h"
}

void test_mock_func(Mpo_t* p)
{
	mock().actualCall("test_mock_func").withOutputParameter("p", (void*) &p->my_ar);
}

TEST_GROUP(Rsp_Sample_Test) {};

TEST(Rsp_Sample_Test, Rsp_MockOutputSample)
{
	// setup
    sint8 mock_array[4];
    Mpo_init();
    Mpo_t* result = Mpo_get(); 
    for (int i=0; i<4; i++) mock_array[i]=i;
	mock().expectNCalls(1, "test_mock_func").withOutputParameterReturning("p", mock_array, sizeof(mock_array));

	// execute
	Mpo_doit();

	// check
    mock().checkExpectations();
    
    int i, start = 1;
    
	for (i=0; i<3; i++) { LONGS_EQUAL(start++, result->other_stuff_ar[i]); }
    for (i=0; i<4; i++) { LONGS_EQUAL(mock_array[i], result->my_ar[i]); start++; }
    for (i=0; i<2; i++) { LONGS_EQUAL(start++, result->more_stuff_ar[i]); }

    // cleanup
    mock().clear();
}

/// CppUTest main function

int main(int ac, char** av)
{
	return RUN_ALL_TESTS(ac, av);
}
