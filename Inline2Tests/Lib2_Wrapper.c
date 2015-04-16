#define INLINE extern

#define inline_sub inline_sub_ignored
#define inline_div inline_div_ignored

#include "inline.h"

#undef inline_sub
#undef inline_div

extern int inline_sub(int i, int j);
extern int inline_div(int i, int j);

#include "Lib2.c"

#undef INLINE