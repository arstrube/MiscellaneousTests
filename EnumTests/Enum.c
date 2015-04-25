#include "Enum.h"

enum Colors { 
   Black = 0, 
   Blue, 
   White, 
   MaxColors
};

enum Colors c = Black;

void increment(void)
{
    if(MaxColors==++c) c = Black;
}
