#define INLINE static

#define inline_add inline_add_ignored
#define inline_mul inline_mul_ignored

#include "inline.h"

#undef inline_add
#undef inline_mul

extern int inline_add(int i, int j);
extern int inline_mul(int i, int j);

#include "Lib1.c"

#undef INLINE