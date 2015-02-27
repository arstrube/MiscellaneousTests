#ifndef BITFIELD_C_H
#define BITFIELD_C_H

#define TRUE   ((boolean) 1)
#define FALSE  ((boolean) 0)
#define NULL_PTR  ((void *)0)

typedef unsigned char uint8;
typedef unsigned char boolean;
typedef unsigned short uint16;
typedef short sint16;

typedef struct Data {
    uint16 field1_u16 : 1;
    uint16 field2_u16 : 3;
    uint16 field3_u16 : 1;
    uint16 field4_u16 : 1;
} Data_t;

boolean Bf_IsFieldSet(uint8 field_u8);

Data_t * Bf_GetData(void);

#endif // BITFIELD_C_H
