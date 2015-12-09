
#include "ModifiedVariably.h"
Test_st test;

// unsigned char array[ (unsigned short)((80.0f)/(5.0f)) ];


/*

PROBLEM:

gcc (4.8.3) complains about the following code:

    unsigned char array[ (unsigned short)((80.0f)/(5.0f)) ];

saying:

    ModifiedVariably.c:3:1: error: variably modified 'array' at file scope [-Werror]
    unsigned char array[ (unsigned short)((80.0f)/(5.0f)) ];
    ^
But there is no variable, and the floating point result is cast to an unsigned before being used as a subscript.

It seems that other compilers do not have this problem.

SOLUTION:

Wrap in a c++ source and have g++ compile it.

*/