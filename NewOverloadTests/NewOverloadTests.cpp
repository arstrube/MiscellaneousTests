#include <iostream>

extern "C" int main(int, char**) {
    int * n = new (std::nothrow) int;
    char * s = new (std::nothrow) char[5];
    delete n;
    delete[] s;
    return 0;
}
