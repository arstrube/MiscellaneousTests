#include "CppUTest/TestHarness.h"

enum Colors { 
   Black = 0, 
   Blue, 
   White, 
   MaxColors
};

Colors& operator++(Colors &c) {
    c = static_cast<Colors>(static_cast<int>(c)+1);
    if ( c == Colors::MaxColors )
        c = Colors::Black;
    return c;
}

Colors operator++(Colors& c, int) {
    Colors tmp(c);
    ++c;
    return tmp;
}

TEST_GROUP(Colors_cpp) {};

TEST(Colors_cpp, increment) {
    Colors color = Black;
    BYTES_EQUAL(Blue, ++color);
    BYTES_EQUAL(Blue, color++);
    BYTES_EQUAL(White, color);
}

TEST(Colors_cpp, overflow) {
    Colors color = White;
    BYTES_EQUAL(Black, ++color);
    BYTES_EQUAL(Black, color++);
    BYTES_EQUAL(Blue, color);
}
