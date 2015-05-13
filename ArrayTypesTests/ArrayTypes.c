#include "ArrayTypes.h"

static UnsafeMatrix unsafe;
static TypesafeMatrix typesafe;

void typeSafeMatrixFunction(TypesafeMatrix typesafeMatrix) {
    byte value;
    for(int i=0; i<INVALID_SIZE; i++) {
        for (int j=0; j<INVALID_SIZE; j++) {
            value = typesafeMatrix.data[i][j];
        }
    }
}

void pointerToUnsafeMatrixFunction(UnsafeMatrix* const unsafeMatrix) {
    (void)unsafeMatrix;
}

void unsafeMatrixFunction(const UnsafeMatrix unsafeMatrix) {
    byte value;
    for(int i=0; i<INVALID_SIZE; i++) {
        for (int j=0; j<INVALID_SIZE; j++) {
            value = unsafeMatrix[i][j];
        }
    }
}

void useAllFunctions(void) {
    typeSafeMatrixFunction(typesafe);
    pointerToUnsafeMatrixFunction(&unsafe);
    unsafeMatrixFunction(unsafe);
}