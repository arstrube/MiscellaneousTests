#ifndef INLINELIB_MACRO_H
#define INLINELIB_MACRO_H

STATIC INLINE int private_func1(int i) ATTRIBUTE(always_inline); // OK
// INLINE int private_func1(int i) ATTRIBUTE(always_inline); // NOT OK
STATIC INLINE ATTRIBUTE(always_inline) int private_func2(int i);
// INLINE ATTRIBUTE(always_inline) int private_func2(int i); // NOT OK
static inline __attribute__((always_inline)) int private_func3(int i);
// inline __attribute__((always_inline)) int private_func3(int i); // NOT OK

int private_func1(int i) { return i; }
int private_func2(int i) { return i; }
int private_func3(int i) { return i; }
STATIC INLINE ATTRIBUTE(always_inline) int private_func4(int i) { return i; }

#endif // INLINELIB_MACRO_H