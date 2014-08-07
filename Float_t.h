#include <stdint.h>

/** See
    http://randomascii.wordpress.com/2012/01/11/tricks-with-the-floating-point-format/
    for the potential portability problems with the union and bit-fields below.
*/

union Float_t
{
    Float_t(float num = 0.0f) : f(num) {}
    // Portable extraction of components.
    bool Negative() const { return (i >> 31) != 0; }
    int32_t RawMantissa() const { return i & ((1 << 23) - 1); }
    int32_t RawExponent() const { return (i >> 23) & 0xFF; }

    int32_t i;
    float f;
#ifdef _DEBUG
    struct
    {   // Bitfields for exploration. Do not use in production code.
        uint32_t mantissa : 23;
        uint32_t exponent : 8;
        uint32_t sign : 1;
    } parts;
#endif
};

 static const int64_t one = 1;

union Double_t
{
    Double_t(double num = 0.0l) : d(num) {}
    // Portable extraction of components.
    bool Negative() const { return (i >> 63) != 0; }
    int64_t RawMantissa() const { return i & ((one << 52) - 1); }
    int64_t RawExponent() const { return (i >> 52) & 0x3FF; }

    int64_t i;
    double d;
#ifdef _DEBUG
    struct
    {   // Bitfields for exploration. Do not use in production code.
        uint64_t mantissa : 52;
        uint64_t exponent : 11;
        uint64_t sign : 1;
    } parts;
#endif
};
