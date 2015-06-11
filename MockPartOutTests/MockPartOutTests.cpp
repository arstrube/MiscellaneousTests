/** This test demonstrates how to use a mock with an output parameter, when just one
 *  field of the otherwise inaccessible struct needs to be manipulated.
 */

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

// #define VARIANT_2

extern "C"
{
    #include "MockPartOut.h"
}

#ifndef VARIANT_2
void Mpo_copy(Mpo_t* const to, const Mpo_t* const from)
{
    to->f = from->f;
    for(int i=0; i<3; i++ ) to->other_stuff[i] = from->other_stuff[i];
    /// Don't copy the field(s) to be modified (tp->to_modify[])
	to->l = from->l;
}

void Otr_func(Mpo_t* p)
{
	mock().actualCall("Otr_func").withOutputParameter("p", (void*) p->to_modify);
}
#else
void Otr_func(Mpo_t* p)
{
    Mpo_t save;

    Mpo_copy(&save, p); /// Save the fields not to be written

	mock().actualCall("Otr_func")
	      .withOutputParameter("p", (void*) p); /// Writes all fields

	Mpo_copy(p, &save); /// Restore the fields not to be written
}
#endif

TEST_GROUP(Rsp_Sample_Test) {};

TEST(Rsp_Sample_Test, Rsp_MockOutputSample)
{
	/// setup
    Mpo_init();
    Mpo_t* result = Mpo_get();
    Mpo_t expected;

    expected.f = -1.0;                                  /// should be ignored
    for (int i=0; i<3; i++) expected.other_stuff[i]=-1; /// should be ignored
    for (int i=0; i<4; i++) expected.to_modify[i]=i;
    expected.l = -1L;                                   /// should be ignored

#ifndef VARIANT_2
	mock().expectNCalls(1, "Otr_func").withOutputParameterReturning("p", expected.to_modify, sizeof(expected.to_modify));
#else
    mock().expectNCalls(1, "Otr_func").withOutputParameterReturning("p", (void*) &expected, sizeof(expected));
#endif

	/// execute
	Mpo_doit();

	/// check
    mock().checkExpectations();
    DOUBLES_EQUAL(17.95, result->f, 0.0001); /// should be unchanged
	LONGS_EQUAL(1, result->other_stuff[0]);  /// should be unchanged
	LONGS_EQUAL(2, result->other_stuff[1]);  /// should be unchanged
	LONGS_EQUAL(3, result->other_stuff[2]);  /// should be unchanged
	LONGS_EQUAL(expected.to_modify[0], result->to_modify[0]);
	LONGS_EQUAL(expected.to_modify[1], result->to_modify[1]);
	LONGS_EQUAL(expected.to_modify[2], result->to_modify[2]);
	LONGS_EQUAL(expected.to_modify[3], result->to_modify[3]);
	LONGS_EQUAL(999999, result->l);           /// should be unchanged

    /// cleanup
    mock().clear();
}

/// CppUTest main function

int main(int ac, char** av)
{
	return RUN_ALL_TESTS(ac, av);
}
