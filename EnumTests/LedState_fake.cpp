extern "C" {
    #include "LedState.h"
}

#include "LedState_fake.h"

void (*LedState_Fake::LedState_setFiveLedsOn)(void) = Real::LedState_setFiveLedsOn;
void (*LedState_Fake::LedState_setSixLedsOn)(void) = Real::LedState_setSixLedsOn;

namespace Stub {
    void LedState_setFiveLedsOn(void) {
    }
    void LedState_setSixLedsOn(void) {
    }
}

namespace Real {
    #include "LedState.c"
}

extern "C" void LedState_setFiveLedsOn(void) {
    LedState_Fake::LedState_setFiveLedsOn();
}

extern "C" void LedState_setSixLedsOn(void) {
    LedState_Fake::LedState_setSixLedsOn();
}
