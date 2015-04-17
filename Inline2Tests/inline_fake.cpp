#include "CppUTestExt/MockSupport.h"

extern "C" {
    #include "inline.h"
}

int inline_add(int i, int j) { 
    mock().actualCall("inline_add")
          .withParameter("i", i)
          .withParameter("j", j); 
    return mock().returnIntValueOrDefault(0);
}
int inline_mul(int i, int j) { return i * j; }
int inline_sub(int i, int j) { return i - j; }
int inline_div(int i, int j) { return i / j; }


