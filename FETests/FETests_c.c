#include "FETests_c.h"
#include "math.h"

void set_divisionbyzero_c(void) {
    float32 f = 1.0f / 0.0f;
    (void) f;
}
void set_overflow_c(void) {
    float32 f = 1000.0f;
    while (f < infinity()) f *= f;
}
void set_underflow_c(void) {
    float32 f = 0.01f;
    while (f > 0.0f) f *= f;
}
void set_invalid_c(void) {
    float32 f = sqrt(-1.0f);
    (void) f;
}
void set_inexact_c(void) {
    float32 f = 2.0f / 3.0f;
    (void) f;
}
void set_nothing_c(void) {
}
void set_everything_c() {
    set_divisionbyzero_c();
    set_overflow_c();
    set_underflow_c();
    set_invalid_c();
    set_inexact_c();
}
