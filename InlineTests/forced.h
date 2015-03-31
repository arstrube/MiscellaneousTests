#ifndef FORCED_H
#define FORCED_H

#if 0 // This actually inlines the functions

#define STATIC static
#define INLINE inline
#define ATTRIBUTE(a) __attribute__((a))

#else // This simply makes them static

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"

#define STATIC static
#define INLINE
#define ATTRIBUTE(a)

#endif // #if 0 or #if 1

#endif // FORCED_H