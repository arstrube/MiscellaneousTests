#ifndef FORCED_H
#define FORCED_H

#define OPTION 1

#if OPTION == 0 // This actually inlines the functions

#define STATIC static
#define INLINE inline
#define ATTRIBUTE(a) __attribute__((a))

#elif OPTION == 1 // Gcc funky solution

#define STATIC extern
#define INLINE inline
#define ATTRIBUTE(a) __attribute__((gnu_inline))

#else // This simply makes them static

#pragma GCC diagnostic ignored "-Wunused-function"

#define STATIC static
#define INLINE
#define ATTRIBUTE(a)

#endif // OPTION

#endif // FORCED_H