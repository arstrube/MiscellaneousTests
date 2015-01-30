#include "CoverageTests.h"

#define MACRO_FUNCTION_AorB_andC(a,b,c) { \
    if ((a || b) && c)                    \
        return 1;                         \
    else                                  \
        return 2;                         \
}

#define MACRO_FUNCTION_AandBandC(a,b,c) { \
    if (a && b && c)                      \
        return 1;                         \
    else                                  \
        return 2;                         \
}

/** Statement Coverage (C0) ****************************************/

int Statement_100_percent_AorB_andC (char a, char b, char c)
           MACRO_FUNCTION_AorB_andC(a, b, c)

int Statement_100_percent_AandBandC (char a, char b, char c)
           MACRO_FUNCTION_AandBandC(a, b, c)

/** Gcov "Branches executed" (n/a) *********************************/

int GcovBranch_100_percent_AorB_andC(char a, char b, char c)
            MACRO_FUNCTION_AorB_andC(a, b, c)

int GcovBranch_100_percent_AandBandC(char a, char b, char c)
            MACRO_FUNCTION_AandBandC(a, b, c)

/** Branch Coverage ************************************************/

int Branch_100_percent_AorB_andC(char a, char b, char c)
        MACRO_FUNCTION_AorB_andC(a, b, c)

int Branch_100_percent_AandBandC(char a, char b, char c)
        MACRO_FUNCTION_AandBandC(a, b, c)

/** Condition Coverage *********************************************/

int Condition_100_percent_AandBandC(char a, char b, char c)
           MACRO_FUNCTION_AandBandC(a, b, c)
    
int Condition_100_percent_AorB_andC(char a, char b, char c)
           MACRO_FUNCTION_AorB_andC(a, b, c)

/** MC/DC **********************************************************/

int MCDC_100_percent_AandBandC(char a, char b, char c)
      MACRO_FUNCTION_AandBandC(a, b, c)

int MCDC_100_percent_AorB_andC(char a, char b, char c)
      MACRO_FUNCTION_AorB_andC(a, b, c)

/** Multi-Decision Coverage ****************************************/

int Multi_100_percent_AandBandC(char a, char b, char c)
       MACRO_FUNCTION_AandBandC(a, b, c)

int Multi_100_percent_AorB_andC(char a, char b, char c)
       MACRO_FUNCTION_AorB_andC(a, b, c)
