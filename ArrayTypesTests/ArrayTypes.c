#include "ArrayTypes.h"

static const UnsafeMatrixA constUnsafeA = {{1}};
//static UnsafeMatrixA unsafeA;
static TypesafeMatrixA typesafeA;
static const UnsafeMatrixA constUnsafeB = {{1}};
//static UnsafeMatrixB   unsafeB;
// static TypesafeMatrixB typesafeB;

void typeSafeMatrixConstFunctionA(const TypesafeMatrixA typesafeMatrixA) {
    byte value;
    for(int i=0; i<INVALID_SIZE; i++) {
        for (int j=0; j<INVALID_SIZE; j++) {
            value = typesafeMatrixA.data[i][j];
        }
    }
    (void)value;
}

void pointerToUnsafeMatrixConstFunctionA(const UnsafeMatrixA* const unsafeMatrixA) {
    (void)unsafeMatrixA;
}

void unsafeMatrixConstFunctionA(const UnsafeMatrixA unsafeMatrixA) {
    byte value;
    for(int i=0; i<INVALID_SIZE; i++) {
        for (int j=0; j<INVALID_SIZE; j++) {
            value = unsafeMatrixA[i][j];
        }
    }
    (void)value;
}

void useAllFunctions(void) {
    // typeSafeMatrixConstFunctionA(typesafeB); /* compiler won't allow this */
    // pointerToUnsafeMatrixConstFunctionA(&unsafeB);
    unsafeMatrixConstFunctionA(constUnsafeB);
    typeSafeMatrixConstFunctionA(typesafeA);
    pointerToUnsafeMatrixConstFunctionA(&constUnsafeA);
    unsafeMatrixConstFunctionA(constUnsafeA);
}