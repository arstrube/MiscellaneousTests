extern "C" {
    #include "Enum.h"
    void increment_real(void);
}

#include "Enum_fake.h"

void (*Enum_Fake::increment)(void) = Real::increment;

namespace Stub {
    void increment(void) {
        c++;
    }
}

namespace Real {
    void increment(void) {
        increment_real();
    }
}

extern "C" void increment(void) {
    Enum_Fake::increment();
}
