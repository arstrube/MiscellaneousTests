#ifndef INLINE_WRAPPER_H
#define INLINE_WRAPPER_H

#pragma push_macro("INLINE")

#define INLINE static __attribute__((unused))

#define inline_add  add
#define inline_mul  mul
#define inline_sub  sub
#define inline_div  div

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