#include "ArrayTypes.h"

bool functionToBeTested(void) {
    dummy localDummy;
    byte localArray[BUFFER_SIZE] = { "Hello World!" };
    bool result = readArray((byte*)&localDummy);
    if(5 == localDummy.number) result = writeArray((byte*) &localArray);
    return result;
}
