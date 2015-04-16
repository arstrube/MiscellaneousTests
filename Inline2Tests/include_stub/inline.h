#ifndef INLINE_WRAPPER_H
#define INLINE_WRAPPER_H

#pragma push_macro("INLINE")

#define INLINE static

#define inline_add inline_add_ignored
#define inline_mul inline_mul_ignored
#define inline_sub inline_sub_ignored
#define inline_div inline_div_ignored

#include "include/inline.h"

#undef inline_add
#undef inline_mul
#undef inline_sub
#undef inline_div

extern int inline_add(int i, int j);
extern int inline_mul(int i, int j);
extern int inline_sub(int i, int j);
extern int inline_div(int i, int j);

#pragma pop_macro("INLINE")

#endif // INLINE_WRAPPER_H