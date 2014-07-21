union Float_t
{
    Float_t(float num = 0.0f) : f(num) {}
    // Portable extraction of components.
    bool Negative() const { return (i &gt;&gt; 31) != 0; }
    int32_t RawMantissa() const { return i &amp; ((1 &lt;&lt; 23) - 1); }
    int32_t RawExponent() const { return (i &gt;&gt; 23) &amp; 0xFF; }

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

void TestFunction()
{
    Float_t num(1.0f);
    num.i -= 1;
    printf(&quot;Float value, representation, sign, exponent, mantissa\n&quot;);
    for (;;)
    {
        // Breakpoint here.
        printf(&quot;%1.8e, 0x%08X, %d, %d, 0x%06X\n&quot;,
            num.f, num.i,
            num.parts.sign, num.parts.exponent, num.parts.mantissa);
    }
}

bool AlmostEqualRelative(float A, float B, float maxRelDiff)
{
    // Calculate the difference.
    float diff = fabs(A - B);
    A = fabs(A);
    B = fabs(B);
    // Find the largest
    float largest = (B &gt; A) ? B : A;

    if (diff &lt;= largest * maxRelDiff)
        return true;
    return false;
}

/* See

http://randomascii.wordpress.com/2012/01/11/tricks-with-the-floating-point-format/

for the potential portability problems with the union and bit-fields below.
*/
union Float_t
{
    Float_t(float num = 0.0f) : f(num) {}
    // Portable extraction of components.
    bool Negative() const { return (i &gt;&gt; 31) != 0; }
    int32_t RawMantissa() const { return i &amp; ((1 &lt;&lt; 23) - 1); }
    int32_t RawExponent() const { return (i &gt;&gt; 23) &amp; 0xFF; }

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

bool AlmostEqualUlps(float A, float B, int maxUlpsDiff)
{
    Float_t uA(A);
    Float_t uB(B);

    // Different signs means they do not match.
    if (uA.Negative() != uB.Negative())
    {
        // Check for equality to make sure +0==-0
        if (A == B)
            return true;
        return false;
    }

    // Find the difference in ULPs.
    int ulpsDiff = abs(uA.i - uB.i);
    if (ulpsDiff &lt;= maxUlpsDiff)
        return true;

    return false;
}

