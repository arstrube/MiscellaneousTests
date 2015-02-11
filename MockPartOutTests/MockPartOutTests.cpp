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

void Otr_func(Mpo_t* p)
{
	mock().actualCall("Otr_func").withOutputParameter("p", (void*) &p->my_ar);
}

TEST_GROUP(Rsp_Sample_Test) {};

TEST(Rsp_Sample_Test, Rsp_MockOutputSample)
{
	// setup
    unsigned char mock_array[4];
    Mpo_init();
    Mpo_t* result = Mpo_get(); 
    for (int i=0; i<4; i++) mock_array[i]=i;
	mock().expectNCalls(1, "Otr_func").withOutputParameterReturning("p", mock_array, sizeof(mock_array));

	// execute
	Mpo_doit();

	// check
    mock().checkExpectations();
    DOUBLES_EQUAL(17.95, result->f, 0.0001);
	LONGS_EQUAL(1, result->other_stuff_ar[0]);
	LONGS_EQUAL(2, result->other_stuff_ar[1]);
	LONGS_EQUAL(3, result->other_stuff_ar[2]);
	LONGS_EQUAL(mock_array[0], result->my_ar[0]);
	LONGS_EQUAL(mock_array[1], result->my_ar[1]);
	LONGS_EQUAL(mock_array[2], result->my_ar[2]);
	LONGS_EQUAL(mock_array[3], result->my_ar[3]);
	LONGS_EQUAL(999999, result->l);

    // cleanup
    mock().clear();
}

/// CppUTest main function

int main(int ac, char** av)
{
	return RUN_ALL_TESTS(ac, av);
}
