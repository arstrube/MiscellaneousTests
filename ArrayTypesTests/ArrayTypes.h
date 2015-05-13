#ifndef _ARRAYTYPES_H_
#define _ARRAYTYPES_H_

#define ROW_SIZE 1
#define COL_SIZE 1
#define INVALID_SIZE 5

typedef unsigned char byte;

typedef struct TypesafeMatrix {
    byte data[ROW_SIZE][COL_SIZE];
} TypesafeMatrix;

typedef byte UnsafeMatrix[ROW_SIZE][COL_SIZE];

void typeSafeMatrixFunction(TypesafeMatrix typesafeMatrix);
void pointerToUnsafeMatrixFunctionA(UnsafeMatrix* const unsafeMatrix);
void unsafeMatrixConstFunction(UnsafeMatrix unsafeMatrix);
void useAllFunctions(void);

#endif // _ARRAYTYPES_H_