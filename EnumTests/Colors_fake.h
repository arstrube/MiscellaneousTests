#ifndef COLORS_FAKE_H__
#define COLORS_FAKE_H__

#include "Colors.h"

extern unsigned int c;

struct Colors_Fake {
    static void (*Colors_increment)(void);
};

namespace Stub{
    void Colors_increment(void);
}

namespace Real{
    void Colors_increment(void);
}

#endif