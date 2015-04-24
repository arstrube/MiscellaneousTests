#include "CppUTest/CommandLineTestRunner.h"

enum Colors { 
   Black = 0, 
   Blue = 1, 
   White = 2, 
   MaxColors = 3
};

Colors& operator++(Colors &c) 
{
    c = static_cast<Colors>(static_cast<int>(c)+1);
    if ( c == Colors::MaxColors )
        c = Colors::Black;
    return c;
}

Colors operator++(Colors& c, int)
{
    Colors tmp(c);
    ++c;
    return tmp;
}

TEST_GROUP(Colors) {};

TEST(Colors, increment)
{
    Colors color = Black;
    BYTES_EQUAL(Blue, ++color);
    BYTES_EQUAL(Blue, color++);
    BYTES_EQUAL(White, color);
}

TEST(Colors, overflow)
{
    Colors color = White;
    BYTES_EQUAL(Black, ++color);
    BYTES_EQUAL(Black, color++);
    BYTES_EQUAL(Blue, color);
}

int main(int ac, char** av)
{
	return RUN_ALL_TESTS(ac, av);
}
