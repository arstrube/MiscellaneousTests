#ifndef INLINE_WRAPPER_H
#define INLINE_WRAPPER_H

#define INLINE extern

#define inline_add inline_add_ignored
#define inline_mul inline_mul_ignored
#define inline_sub inline_sub_ignored
#define inline_div inline_div_ignored

#include "inline.h"

#undef inline_add
#undef inline_mul
#undef inline_sub
#undef inline_div

extern int inline_add(int i, int j);
extern int inline_mul(int i, int j);
extern int inline_sub(int i, int j);
extern int inline_div(int i, int j);

#include "inline.h"

#undef INLINE

#endif // INLINE_WRAPPER_H