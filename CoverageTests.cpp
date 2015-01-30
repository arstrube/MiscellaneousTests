#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

extern "C"
{
    #include "CoverageTests.h"
}

/** Capitel means: Significant. Lowercase means: irrelevant */

#define T true
#define t true
#define F false
#define f false

TEST_GROUP(CoverageTest)
{
};

/** Statement coverage (C0) *****************************************
 *  Each executable statement in the code was visited at least once.
 *
 *  gcov: "Lines executed".
 */

TEST(CoverageTest, Statement)
{
    LONGS_EQUAL(1, Statement_100_percent_AorB_andC(T, t, T));
    LONGS_EQUAL(2, Statement_100_percent_AorB_andC(t, t, F));
    
    LONGS_EQUAL(1, Statement_100_percent_AandBandC(T, T, T));
    LONGS_EQUAL(2, Statement_100_percent_AandBandC(F, f, f));
}

/** gcov "Branches executed" ****************************************
 *
 *  Each condition in the code was evaluated at least once. For this
 *  to be true, statement coverage can be less than 100%!
 *
 *  gcov: Branches executed
 */

TEST(CoverageTest, GcovBranch_100_percent)
{
    LONGS_EQUAL(1, GcovBranch_100_percent_AorB_andC(F, T, T));
    
    LONGS_EQUAL(1, GcovBranch_100_percent_AandBandC(T, T, T));
}

/** Branch coverage *************************************************
 *
 *  Each execution path in the code was taken at least once.
 *
 *  gcov: 100% Lines executed AND 100% Branches executed
 *        -> 100% Branch coverage
 */

TEST(CoverageTest, Branch_100_percent)
{
    LONGS_EQUAL(1, Branch_100_percent_AorB_andC(F, T, T));
    LONGS_EQUAL(2, Branch_100_percent_AorB_andC(F, T, F));
    
    LONGS_EQUAL(1, Branch_100_percent_AandBandC(T, T, T));
    LONGS_EQUAL(2, Branch_100_percent_AandBandC(T, T, F));
}

/** Condition coverage **********************************************
 *
 *  Each condition in the code was evaluated to both true and false
 *  at least once.
 *
 *  NOTE: Because of shortcut evaluation in C, this might take more
 *        test cases than it one would first think.
 *
 *  gcov: Taken at least once
 */

TEST(CoverageTest, Condition_100_percent) 
{
    LONGS_EQUAL(1, Condition_100_percent_AorB_andC(T, F, T));
    LONGS_EQUAL(2, Condition_100_percent_AorB_andC(F, F, t));
    LONGS_EQUAL(2, Condition_100_percent_AorB_andC(F, T, F));
    
    LONGS_EQUAL(1, Condition_100_percent_AandBandC(T, T, T));
    LONGS_EQUAL(2, Condition_100_percent_AandBandC(F, t, t));
    LONGS_EQUAL(2, Condition_100_percent_AandBandC(T, F, t));
    LONGS_EQUAL(2, Condition_100_percent_AandBandC(T, T, F));
}

/** MC/DC coverage **************************************************
 *
 *  Each condition in the code affects the decision outcome 
 *  independently. (T/F here means: Affects the decision, and t/f
 *  means: Does not affect the decision.
 *  
 *  gcov: n/a
 */

TEST(CoverageTest, MCDC_100_percent) 
{    
    LONGS_EQUAL(1, MCDC_100_percent_AorB_andC(T, f, T));
    LONGS_EQUAL(2, MCDC_100_percent_AorB_andC(F, F, t));
    LONGS_EQUAL(2, MCDC_100_percent_AorB_andC(f, t, F));
    /** gcov does not require this case, but MC/CD does */
    LONGS_EQUAL(1, MCDC_100_percent_AorB_andC(f, T, T));
    
    LONGS_EQUAL(2, MCDC_100_percent_AandBandC(F, t, t));
    LONGS_EQUAL(2, MCDC_100_percent_AandBandC(t, F, t));
    LONGS_EQUAL(2, MCDC_100_percent_AandBandC(t, t, F));
    LONGS_EQUAL(1, MCDC_100_percent_AandBandC(t, t, T));
}

/** Multi-Decision coverage *****************************************
 *
 *  All possible combinations of all conditions are tested.
 *  
 *  gcov: n/a
 */

TEST(CoverageTest, MultiCondition_100_percent) 
{    
    LONGS_EQUAL(1, Multi_100_percent_AorB_andC(T, t, T));
    LONGS_EQUAL(1, Multi_100_percent_AorB_andC(T, f, T));
    LONGS_EQUAL(2, Multi_100_percent_AorB_andC(T, f, F));
    LONGS_EQUAL(2, Multi_100_percent_AorB_andC(T, t, F));
    LONGS_EQUAL(1, Multi_100_percent_AorB_andC(F, t, T));
    LONGS_EQUAL(1, Multi_100_percent_AorB_andC(F, T, T));
    LONGS_EQUAL(2, Multi_100_percent_AorB_andC(F, F, F));
    LONGS_EQUAL(2, Multi_100_percent_AorB_andC(F, F, t));
    
    LONGS_EQUAL(2, Multi_100_percent_AandBandC(F, t, t));
    LONGS_EQUAL(2, Multi_100_percent_AandBandC(t, F, t));
    LONGS_EQUAL(2, Multi_100_percent_AandBandC(t, t, F));
    LONGS_EQUAL(1, Multi_100_percent_AandBandC(t, t, T));
}

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
