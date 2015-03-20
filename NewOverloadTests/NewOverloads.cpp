#include <iostream>

void* operator new(size_t size, const std::nothrow_t&) _NOEXCEPT
{
    std::cout << "Called overloaded operator new with size: " << size << "\n";
    return malloc(size);
}

void* operator new[](size_t size, const std::nothrow_t&) _NOEXCEPT
{
    std::cout << "Called overloaded operator new[] with size: " << size<< "\n";
    return malloc(size);
}

void operator delete(void* mem) _NOEXCEPT
{
    std::cout << "Called overloaded operator delete\n";
    free(mem);
}

void operator delete[](void* mem) _NOEXCEPT
{
    std::cout << "Called overloaded operator delete[]\n";
    free(mem);
}
