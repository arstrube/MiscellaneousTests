#ifndef _ARRAYTYPES_H_
#define _ARRAYTYPES_H_

#ifndef __cplusplus
    typedef enum bool { false, true } bool;
#endif

typedef unsigned char byte;

typedef struct ByteArray13 {
    byte data[13];
} ByteArray13;

typedef struct dummy {
    int number;
} dummy;

#define BUFFER_SIZE 13

bool readArray(byte*);
bool writeArray(const byte*);
bool functionToBeTested(void);

#endif // _ARRAYTYPES_H_