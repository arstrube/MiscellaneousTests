#ifndef ENUM_FAKE_H__
#define ENUM_FAKE_H__

#include "Enum.h"

extern unsigned int c;

struct Enum_Fake {
    static void (*increment)(void);
};

namespace Stub{
    void increment(void);
}

namespace Real{
    void increment(void);
}

#endif