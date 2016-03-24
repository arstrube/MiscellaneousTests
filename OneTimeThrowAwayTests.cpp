#include "CppUTest/TestHarness.h"
#include "CppUTestExt/IEEE754ExceptionsPlugin.h"

static volatile float f = 1.0;
static volatile IEEE754ExceptionsPlugin plugin; // link it

int main(int, char**) {
    f /= 0.0f;
    return 0;
}
