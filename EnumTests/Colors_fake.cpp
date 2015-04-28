extern "C" {
    #include "Colors.h"
    void Colors_increment_real(void);
}

#include "Colors_fake.h"

void (*Colors_Fake::Colors_increment)(void) = Real::Colors_increment;

namespace Stub {
    void Colors_increment(void) {
        c++;
    }
}

namespace Real {
    void Colors_increment(void) {
        Colors_increment_real();
    }
}

extern "C" void Colors_increment(void) {
    Colors_Fake::Colors_increment();
}
