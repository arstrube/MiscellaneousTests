#include <iostream>
#include <cstdlib>

#ifndef __clang__
  #define _NOEXCEPT throw()
#endif

void* operator new(size_t size, const std::nothrow_t&) _NOEXCEPT {
    std::cout << "overloaded operator new      - size: " << size << "\n";
    return malloc(size);
}

void* operator new[](size_t size, const std::nothrow_t&) _NOEXCEPT {
    std::cout << "overloaded operator new[]    - size: " << size<< "\n";
    return malloc(size);
}

void operator delete(void* mem) _NOEXCEPT {
    std::cout << "overloaded operator delete\n";
    free(mem);
}

void operator delete[](void* mem) _NOEXCEPT {
    std::cout << "overloaded operator delete[]\n";
    free(mem);
}
