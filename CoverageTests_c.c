#include "CoverageTests.h"

/** Statement Coverage (C0) ****************************************/

int Statement_100_percent_AorB_andC (char a, char b, char c)
{
    int x;
    
    if ((a || b) && c)
    {
        x = 1;
    }
    else
    {
        x = 2;
    }
    
    return x;
}

int Statement_100_percent_AandBandC (char a, char b, char c)
{
    int x;
    
    if (a && b && c)
    {
        x = 1;
    }
    else
    {
        x = 2;
    }
    
    return x;
}

/** Gcov "Branches executed" (n/a) *********************************/

int GcovBranch_100_percent_AorB_andC(char a, char b, char c)
{
    int x;
    
    if ((a || b) && c)
    {
        x = 1;
    }
    else
    {
        x = 2;
    }
    
    return x;
}

int GcovBranch_100_percent_AandBandC(char a, char b, char c)
{
    int x;
    
    if (a && b && c)
    {
        x = 1;
    }
    else
    {
        x = 2;
    }
    
    return x;
}

/** Branch Coverage ************************************************/

int Branch_100_percent_AorB_andC(char a, char b, char c)
{
    int x;
    
    if ((a || b) && c)
    {
        x = 1;
    }
    else
    {
        x = 2;
    }
    
    return x;
}

int Branch_100_percent_AandBandC(char a, char b, char c)
{
    int x;
    
    if (a && b && c)
    {
        x = 1;
    }
    else
    {
        x = 2;
    }
    
    return x;
}

/** Condition Coverage *********************************************/

int Condition_100_percent_AandBandC(char a, char b, char c)
{
    int x;
    
    if (a && b && c)
    {
        x = 1;
    }
    else
    {
        x = 2;
    }
    
    return x;
}

int Condition_100_percent_AorB_andC(char a, char b, char c)
{
    int x;
    
    if ((a || b) && c)
    {
        x = 1;
    }
    else
    {
        x = 2;
    }
    
    return x;
}

/** MC/DC **********************************************************/

int MCDC_100_percent_AandBandC(char a, char b, char c)
{
    int x;
    
    if (a && b && c)
    {
        x = 1;
    }
    else
    {
        x = 2;
    }
    
    return x;
}

int MCDC_100_percent_AorB_andC(char a, char b, char c)
{
    int x;
    
    if ((a || b) && c)
    {
        x = 1;
    }
    else
    {
        x = 2;
    }
    
    return x;
}

/** Multi-Decision Coverage ****************************************/

int Multi_100_percent_AandBandC(char a, char b, char c)
{
    int x;
    
    if (a && b && c)
    {
        x = 1;
    }
    else
    {
        x = 2;
    }
    
    return x;
}

int Multi_100_percent_AorB_andC(char a, char b, char c)
{
    int x;
    
    if ((a || b) && c)
    {
        x = 1;
    }
    else
    {
        x = 2;
    }
    
    return x;
}
