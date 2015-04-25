extern "C" {
    #include "Enum_fake.h"
    
    void increment_real(void);
}

void (*Enum_Fake::increment)(void) = increment_real;

extern "C" void increment(void)
{
    Enum_Fake::increment();
}