#ifndef FORCED_H
#define FORCED_H

#if 0 // This actually inlines the functions
#  define INLINE inline
#else // This simply makes non-inlined
#  define INLINE
#endif // #if 0 or #if 1

#endif // FORCED_H