#include "FETests_c.h"
#include "math.h"

float32 do_divisionbyzero_c(void) {
    return 1.0f / 0.0f;
}
float32 do_overflow_c(float32 f) {
    while (f < infinity()) f *= f;
    return f;
}
float32 do_underflow_c(float32 f) {
    while (f > 0.0f) f *= f;
    return f;
}
float32 do_invalid_c(void) {
    return sqrt(-1.0f);
}
float32 do_inexact_c(void) {
    return 2.0f / 3.0f;
}
