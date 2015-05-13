#ifndef _ARRAYTYPES_H_
#define _ARRAYTYPES_H_

#define ROW_SIZE_A 1
#define COL_SIZE_A 1
#define ROW_SIZE_B 2
#define COL_SIZE_B 2
#define INVALID_SIZE 5

typedef unsigned char byte;

typedef struct TypesafeMatrixA {
    byte data[ROW_SIZE_A][COL_SIZE_A];
} TypesafeMatrixA;

typedef struct TypesafeMatrixB {
    byte data[ROW_SIZE_B][COL_SIZE_B];
} TypesafeMatrixB;

typedef byte UnsafeMatrixA[ROW_SIZE_A][COL_SIZE_A];
typedef byte UnsafeMatrixB[ROW_SIZE_B][COL_SIZE_B];

void typeSafeMatrixConstFunctionA(const TypesafeMatrixA typesafeMatrixA);
void pointerToUnsafeMatrixConstFunctionA(const UnsafeMatrixA* const unsafeMatrixA);
void unsafeMatrixConstFunctionA(const UnsafeMatrixA unsafeMatrixA);
void useAllFunctions(void);

#endif // _ARRAYTYPES_H_