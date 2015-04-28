#ifndef LEDSTATE_FAKE_H__
#define LEDSTATE_FAKE_H__

#include "LedState.h"

extern unsigned int c;

struct LedState_Fake {
    static void (*LedState_setFiveLedsOn)(void);
    static void (*LedState_setSixLedsOn)(void);
};

namespace Stub{
    void LedState_setFiveLedsOn(void);
    void LedState_setSixLedsOn(void);
}

namespace Real{
    void LedState_setFiveLedsOn(void);
    void LedState_setSixLedsOn(void);
}

#endif