#include "FETests_c.h"
#include "math.h"

void _divisionbyzero_c(void) {
    float32 f = 1.0f / 0.0f;
    (void) f;
}
void _overflow_c(void) {
    float32 f = 1000.0f;
    while (f < infinity()) f *= f;
}
void _underflow_c(void) {
    float32 f = 0.01f;
    while (f > 0.0f) f *= f;
}
void _invalid_c(void) {
    float32 f = sqrt(-1.0f);
    (void) f;
}
void _inexact_c(void) {
    float32 f = 2.0f / 3.0f;
    (void) f;
}
