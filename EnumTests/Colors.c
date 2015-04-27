#include "Colors.h"

/** '++' operator is used on enum, which is an error in C++ */

enum Colors { 
    Black = 0, 
    Blue, 
    White, 
    MaxColors
};

enum Colors c = Black;

void Colors_increment(void) {
    if(MaxColors==++c) c = Black;
}
